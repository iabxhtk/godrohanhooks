#pragma once
#include "SubQuest_Template.h"
#include "CPlayerQuestManager.h"
#include "Structs.h"
#include "MapEnums.h"




class  QuestTemplate 
	{
		e_QuestEditorDlgType m_eQuestType;
		std::basic_string<char, std::char_traits<char>, std::allocator<char> > m_QuestTitle;
		std::basic_string<char, std::char_traits<char>, std::allocator<char> > m_TitleExplain;
		std::basic_string<char, std::char_traits<char>, std::allocator<char> > m_QuestDescription;
		unsigned int m_QuestID;
		unsigned int m_OwnerNPC;
		unsigned int m_RewardNPC;
		__int16 m_MinReqLevel;
		__int16 m_MaxReqLevel;
		__int16 m_RecommendLevel;
		unsigned __int16 m_PlayerClass;
		bool m_bInterConnectQuest;
		unsigned int m_ParentQuestID;
		unsigned int m_ChildQuestID;
		unsigned int m_Reward_XP;
		unsigned int m_Reward_Money;
		bool m_bDisable;
		bool m_bAlarmDisable;
		bool m_bIterationQuest;
		bool m_bPartyQuest;
		bool m_bNoPartyQuest;
		bool m_bGuildMasterQuest;
		bool m_bGuildCreateQuest;
		bool m_bChangeJobQuest;
		int m_ChangeJobType;
		bool m_bMainQuest;
		bool m_bUseLevelExpTable;
		bool m_bPartyShareQuest;
		bool m_bUseLevelMoneyTable;
		bool m_bBossQuest;
		bool m_bSimpleQuest;
		bool m_bUseLevelNotyMsg;
		unsigned int m_RewardFlag;
		unsigned int m_ItemCountForSelect;
		int m_iTimeLimit;
		int m_tCompleteTime;
		bool m_bUseEventTime;
		_SYSTEMTIME m_EventTimeStart;
		_SYSTEMTIME m_EventTimeEnd;
		stItemData m_AchieveTitleData;
		std::vector<stItemData, std::allocator<stItemData> > m_RewardItemList;
		std::map<unsigned int, unsigned short, std::less<unsigned int>, std::allocator<std::pair<unsigned int const, unsigned short> > > m_ReqItems;
		std::map<enum questState, std::basic_string<char, std::char_traits<char>, std::allocator<char> >, std::less<enum questState>, std::allocator<std::pair<enum questState const, std::basic_string<char, std::char_traits<char>, std::allocator<char> > > > > m_DlgFiles;
		std::vector<SubQuest_Template *, std::allocator<SubQuest_Template *> > m_SubQuests;
		std::list<std::list<char, std::allocator<char> >, std::allocator<std::list<char, std::allocator<char> > > > m_DependentList;
		std::vector<Quest_Special_condition, std::allocator<Quest_Special_condition> > m_special_acceptance;
		Quest_Special_condition m_special_reward;
		bool m_bLadderQuest;
		_SYSTEMTIME m_AcceptStartDate;
		_SYSTEMTIME m_AcceptEndDate;
		int m_AcceptHour;
		int m_AcceptMinute;
		int m_AcceptDurationTime;
		int m_ExecuteDurationTime;
		bool m_AcceptWeek[7];
		std::map<int, stLadderReward, std::less<int>, std::allocator<std::pair<int const, stLadderReward> > > m_LadderRewardList;
		unsigned int m_EntryFee;
		std::basic_string<char, std::char_traits<char>, std::allocator<char> > m_InfoMsg[3];
		std::basic_string<char, std::char_traits<char>, std::allocator<char> > m_LevelNoti[2];
};


