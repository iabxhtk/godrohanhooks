#pragma once
#include <unordered_map>
#include "Player.h"
#include "MapEnums.h"
#include "rapidxml\rapidxml.hpp"
#include <fstream>
#include <string>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
class CItemEntity : public CBiotic
{
public:
	EpochItem * m_pItem;

};

class AdvancedHK
{
private:
	static std::unordered_map<int, int> swordAxePolearmDualSwordStats;
	static std::unordered_map<int, int> zhensStats;
	static std::unordered_map<int, int> wandStaffStats;
	static std::unordered_map<int, int> bowXbowStats;
	static std::unordered_map<int, int> daggerStats;
	static std::unordered_map<int, int> katarStats;
	static std::unordered_map<int, int> accessoryStats;
	static std::unordered_map<int, int> armorStats;
	int StringToOptionType(std::string & strOpt);
	int IsMaxStatInMap(tagItem & item, std::unordered_map<int, int>& itemStatsMap);
public:
	static AdvancedHK & getInstance()
	{
		static AdvancedHK singleton;
		return singleton;
	}
	void SendNoticeMessageGreen(CPlayer * sendTo, std::string messageStringworld, char type);
	void SendNoticeMessage(CPlayer * sendTo, std::string && messageString);
	void readXMLConfig();
	int IsMaxItem(EpochItem * pickedItem);
	static void ApplyHook(HMODULE hModule);
	AdvancedHK();
	~AdvancedHK();
};

