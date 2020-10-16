#pragma once
#include <vector>

class ItemEtcDetailsScript {

public:
	int _iD;                                                     // int m_ID;
	std::basic_string<char, std::char_traits<char>, std::allocator<char> > _etcItemName;// std::basic_string<char,std::char_traits<char>,std::allocator<char> > m_EtcItemName;
	int _etcItemID;                                              // int m_EtcItemID;
	int _getExp;                                                 // int m_GetExp;
	int _moneyType;                                              // int m_MoneyType;
	int _getMoney;                                               // int m_GetMoney;
	int _getItemCountMax;                                        // int m_GetItemCountMax;
	std::vector<int, std::allocator<int> > _getItemNames;         // std::vector<int,std::allocator<int> > m_GetItemNames;
	std::vector<int, std::allocator<int> > _getItemCounts;        // std::vector<int,std::allocator<int> > m_GetItemCounts;
	std::vector<int, std::allocator<int> > _getItemRates;         // std::vector<int,std::allocator<int> > m_GetItemRates;
	unsigned __int16 _useSkillKind;                              // unsigned __int16 m_UseSkillKind;
	char _useSkillLevel;                                         // char m_UseSkillLevel;
	std::basic_string<char, std::char_traits<char>, std::allocator<char> > _useSkillExplain;// std::basic_string<char,std::char_traits<char>,std::allocator<char> > m_UseSkillExplain;
	unsigned __int16 _checkSkillKind;                            // unsigned __int16 m_CheckSkillKind;
	char _checkSkillLevel;                                       // char m_CheckSkillLevel;
	int _runQuestID;                                             // int m_RunQuestID;
	int _itemMaxUseCount;                                        // int m_ItemMaxUseCount;
	int _itemReuseTime;                                          // int m_ItemReuseTime;
	int _itemEtcKeyItem1;                                        // int m_ItemEtcKeyItem_1;
	int _itemEtcKeyItem2;                                        // int m_ItemEtcKeyItem_2;

};
