#include "Separator.h"

Separator::Separator(char* SrcMsg, int mode, size_t MaxLen)
{
	if (MaxLen > 144 || MaxLen < 16) MaxLen = 144;

	std::string SrcConvert(SrcMsg);

	switch (mode)
	{
		case 1: //Separation with indication of the gap
		{
			if (SrcConvert.length() > MaxLen)
			{
				while (SrcConvert.length() > MaxLen - 3)
				{
					SeparateWithGap(&SrcConvert, MaxLen - 3);
				}
			}
			if (SrcConvert.length()) MessageQueue.push_back(SrcConvert);
			break;
		}
		default: //Separation as is
		{
			while (SrcConvert.length() > MaxLen)
			{
				SeparateDefault(&SrcConvert, MaxLen);
			}

			if (SrcConvert.length()) MessageQueue.push_back(SrcConvert);
			break;
		}
	}
}

Separator::Separator(char* SrcMsg, int mode, size_t MaxLen, char Separator) //Separation by separator character
{
	if (MaxLen > 144 || MaxLen < 16) MaxLen = 144;

	std::string SrcConvert(SrcMsg);

	while (SrcConvert.length() > MaxLen)
	{
		size_t EraseLength = MaxLen;
		std::string SubStr = SrcConvert.substr(0, EraseLength);
		FixBadHex(EraseLength, SubStr);

		bool Finded = false;
		for (int i = EraseLength; i > 0; i--)
		{
			if (SubStr[i] == Separator)
			{
				EraseLength = i;
				SubStr = SubStr.substr(0, EraseLength);
				SrcConvert.erase(0, EraseLength+1);

				MessageQueue.push_back(SubStr);

				UpdateHex(&SrcConvert);
				Finded = true;
				break;
			}
		}

		if (!Finded)
		{
			switch (mode)
			{
				case 1: //Separation with indication of the gap
				{
					SeparateWithGap(&SrcConvert, MaxLen - 3);
					break;
				}
				default: //Separation as is
				{
					SeparateDefault(&SrcConvert, MaxLen);
					break;
				}
			}
		}
	}
	if (SrcConvert.length()) MessageQueue.push_back(SrcConvert);
}

Separator::Separator(char* SrcMsg, size_t MaxLen, char Separator, char* GapStr, bool AlwaysAddGapStr)
{
	std::string SrcConvert(SrcMsg);
	std::string GapText(GapStr);

	if (MaxLen > 144 || MaxLen < (8 + GapText.length() + 1 + GapText.length() + 1)) MaxLen = 144;

	while (SrcConvert.length() > MaxLen)
	{
		size_t EraseLength = MaxLen;
		std::string SubStr = SrcConvert.substr(0, EraseLength);
		FixBadHex(EraseLength, SubStr);

		bool Finded = false;
		for (int i = EraseLength; i > 0; i--)
		{
			if (SubStr[i] == Separator && (i + GapText.length() <= MaxLen))
			{
				EraseLength = i;
				SubStr = SubStr.substr(0, EraseLength);
				SrcConvert.erase(0, EraseLength + 1);

				if (AlwaysAddGapStr && SrcConvert.length())
				{
					SubStr = SubStr + GapText;

					std::string Hex = "";
					int offset = 0;
					if (SrcConvert.at(offset) == ' ') offset++;
					if (SrcConvert.at(offset) == '{' && SrcConvert.at(offset + 7) == '}')
					{
						Hex = SrcConvert.substr(offset, 8);
						offset += 8;
					}
					SrcConvert = Hex + GapStr + SrcConvert.substr(offset);
				}

				MessageQueue.push_back(SubStr);

				UpdateHex(&SrcConvert);
				Finded = true;
				break;
			}
		}
		if (!Finded) SeparateWithGapText(&SrcConvert, MaxLen - GapText.length(), GapText.c_str());
	}
	if (SrcConvert.length()) MessageQueue.push_back(SrcConvert);
}

void Separator::SeparateWithGap(std::string* SrcConvert, size_t EraseLength)
{
	std::string SubStr = SrcConvert->substr(0, EraseLength);

	FixBadHex(EraseLength, SubStr);

	SrcConvert->erase(0, EraseLength);

	if (SrcConvert->length())
	{
		SubStr = SubStr + "...";

		std::string Hex = "";
		int offset = 0;
		if (SrcConvert->at(offset) == ' ') offset++;
		if (SrcConvert->at(offset) == '{' && SrcConvert->at(offset + 7) == '}')
		{
			Hex = SrcConvert->substr(offset, 8);
			offset += 8;
		}
		*SrcConvert = Hex + "..." + SrcConvert->substr(offset);
	}

	MessageQueue.push_back(SubStr);

	UpdateHex(SrcConvert);
}

void Separator::SeparateDefault(std::string* SrcConvert, size_t EraseLength)
{
	std::string SubStr = SrcConvert->substr(0, EraseLength);

	FixBadHex(EraseLength, SubStr);

	SrcConvert->erase(0, EraseLength);

	MessageQueue.push_back(SubStr);

	UpdateHex(SrcConvert);
}

void Separator::SeparateWithGapText(std::string* SrcConvert, size_t EraseLength, const char* GapStr)
{
	std::string SubStr = SrcConvert->substr(0, EraseLength);

	FixBadHex(EraseLength, SubStr);

	SrcConvert->erase(0, EraseLength);

	if (SrcConvert->length())
	{
		SubStr = SubStr + GapStr;

		std::string Hex = "";
		int offset = 0;
		if (SrcConvert->at(offset) == ' ') offset++;
		if (SrcConvert->at(offset) == '{' && SrcConvert->at(offset + 7) == '}')
		{
			Hex = SrcConvert->substr(offset, 8);
			offset += 8;
		}
		*SrcConvert = Hex + GapStr + SrcConvert->substr(offset);
	}

	MessageQueue.push_back(SubStr);

	UpdateHex(SrcConvert);
}

void Separator::FixBadHex(size_t& EraseLength, std::string& SubStr)
{
	if (SubStr[0] == '{' && SubStr[8] == '{') SubStr.erase(0, 8);

	if (SubStr[EraseLength-8] == '{')
	{
		SubStr.erase(EraseLength-8, EraseLength);
		EraseLength = EraseLength - 8 - 1;
	}
	else
	{
		for (int i = 0; i < 8; i++)
		{
			if (SubStr[EraseLength - 7 + i] == '{')
			{
				SubStr.erase(EraseLength - 7 + i, EraseLength);
				EraseLength = EraseLength - 7 + i - 1;
			}
		}
	}
}

void Separator::UpdateHex(std::string* SrcConvert)
{
	if (!MessageQueue.empty())
	{
		std::string Hex;
		std::regex regex("\\{[A-Za-z\\d]{6}\\}");

		for (std::sregex_iterator ibegin{ MessageQueue.back().begin(), MessageQueue.back().end(), regex }, iend; ibegin != iend; ibegin++)
		{
			Hex = ibegin->str();
		}

		if (!Hex.empty() && SrcConvert->at(0) != '{' && SrcConvert->at(7) != '}')
		{
			*SrcConvert = Hex + *SrcConvert;
		}
	}
}

std::list<std::string> Separator::getMessageQueue() { return MessageQueue; }
