#include "Separator.h"

Separator::Separator(char* SrcMsg, int mode)
{
	std::string SrcConvert(SrcMsg);

	switch (mode)
	{
		case 1: //Separation with indication of the gap
		{
			if (SrcConvert.length() > 144)
			{
				while (SrcConvert.length() > 141)
				{
					SeparateWithGap(&SrcConvert);
				}
			}
			if (SrcConvert.length()) MessageQueue.push_back(SrcConvert);
			break;
		}
		default: //Separation as is
		{
			while (SrcConvert.length() > 144)
			{
				SeparateDefault(&SrcConvert);
			}

			if (SrcConvert.length()) MessageQueue.push_back(SrcConvert);
			break;
		}
	}
}

Separator::Separator(char* SrcMsg, int mode, char Separator) //Separation by separator character
{
	std::string SrcConvert(SrcMsg);
	while (SrcConvert.length() > 144)
	{
		int EraseLength = 144;
		std::string SubStr = SrcConvert.substr(0, EraseLength);
		FixBadHex(EraseLength, SubStr);

		bool Finded = false;
		for (int i = EraseLength; i >= 0; i--)
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
					SeparateWithGap(&SrcConvert);
					break;
				}
				default: //Separation as is
				{
					SeparateDefault(&SrcConvert);
					break;
				}
			}
		}
	}
	if (SrcConvert.length()) MessageQueue.push_back(SrcConvert);
}

void Separator::SeparateWithGap(std::string* SrcConvert)
{
	int EraseLength = 141;
	std::string SubStr = SrcConvert->substr(0, EraseLength);

	FixBadHex(EraseLength, SubStr);

	SrcConvert->erase(0, EraseLength);

	if (SrcConvert->length())
	{
		SubStr = SubStr + "...";

		if(SrcConvert->at(0) == ' ') *SrcConvert = "..." + SrcConvert->substr(1);
		else *SrcConvert = "..." + *SrcConvert;
	}

	MessageQueue.push_back(SubStr);

	UpdateHex(SrcConvert);
}

void Separator::SeparateDefault(std::string* SrcConvert)
{
	int EraseLength = 144;
	std::string SubStr = SrcConvert->substr(0, EraseLength);

	FixBadHex(EraseLength, SubStr);

	SrcConvert->erase(0, EraseLength);

	MessageQueue.push_back(SubStr);

	UpdateHex(SrcConvert);
}

void Separator::FixBadHex(int& EraseLength, std::string& SubStr)
{
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

		if (!Hex.empty()) *SrcConvert = Hex + *SrcConvert;
	}
}

std::list<std::string> Separator::getMessageQueue() { return MessageQueue; }
