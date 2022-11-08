#pragma once
#include <list>
#include <string>
#include <regex>
class Separator
{
public:
	Separator(char* SrcMsg, int mode, size_t MaxLen);
	Separator(char* SrcMsg, int mode, size_t MaxLen, char Separator);
	std::list<std::string> getMessageQueue();
private:
	std::list<std::string> MessageQueue;
	void UpdateHex(std::string* SrcConvert);
	void FixBadHex(size_t& EraseLength, std::string& SubStr);
	void SeparateDefault(std::string* SrcConvert, size_t EraseLength);
	void SeparateWithGap(std::string* SrcConvert, size_t EraseLength);
};

