#pragma once
#include <list>
#include <string>
#include <regex>
class Separator
{
public:
	Separator(char* SrcMsg, int mode);
	Separator(char* SrcMsg, int mode, char Separator);
	std::list<std::string> getMessageQueue();
private:
	std::list<std::string> MessageQueue;
	void UpdateHex(std::string* SrcConvert);
	void FixBadHex(int& EraseLength, std::string& SubStr);
	void SeparateDefault(std::string* SrcConvert);
	void SeparateWithGap(std::string* SrcConvert);
};

