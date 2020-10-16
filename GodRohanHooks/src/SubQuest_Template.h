#pragma once
#include "ISubQuest.h"
#include "CQuest.h"
#include "AntiHackStructs.h"
#include "Player.h"
#include "PlayerItemSlotManager.h"
#include "Structs.h"
#include "CPlayerQuestManager.h"




class CPlayer;
class SubQuest_Template 
{
	//SubQuest_TemplateVtbl *vfptr;
	unsigned int m_ParentQuestID;
	//enumSubQuest_Type m_subquestType;
	char m_subquestID;
	std::vector<char, std::allocator<char> > m_presubquestIDs;
	char m_nextsubquestID;
	std::basic_string<char, std::char_traits<char>, std::allocator<char> > m_subquestTitle;
	bool m_immediateReward;
	unsigned int m_reward_xp;
	unsigned int m_reward_money;
	int m_iTimeLimit;
	//Quest_Special_condition m_special_complete_condition;
};