#pragma once
#include "CQuest.h"
#include "AntiHackStructs.h"
#include "Player.h"
#include "PlayerItemSlotManager.h"
#include "Structs.h"
#include "ISubQuest.h"
#include "CMobSubQuestMap.h"
#include "CActiveQuests.h"
#include "IOCriticalSection.h"
#include "CCompletedQuests.h"







class CPlayerQuestManager

{

public:
	CPlayer * GetPlayer()
	{
		return (CPlayer*)*(int*)((char*)this + 0x40);
	}

	CCompletedQuests _completedQuests;
	CActiveQuests _activeQuests;
	CMobSubQuestMap _MobSubQuestMap;
	IOCriticalSection m_crit;
	CPlayer *_pPlayer;
	bool m_isTitleQuest;
};