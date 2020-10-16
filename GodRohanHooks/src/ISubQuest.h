#pragma once
#include "CQuest.h"
#include "AntiHackStructs.h"
#include "Player.h"
#include "PlayerItemSlotManager.h"
#include "Structs.h"
#include "CPlayerQuestManager.h"
#include "MapEnums.h"

struct ISubQuest {

public:


	inline int GetReward()
	{
		return *(int*)((char*)this + 0x00000018);
	}


	CQuest *_pQuest;
	int _iMainQuestID;
	SubQuest_Template *_pSubQuestTemplate;
	int _iSubQuestID;
	int _iSubQuestType;
	int _bActivated;
	int _bReward;
	int _bSave;
	QuestTimer _QuestTimer;
	int _iItemType;
	int _iMaxItemCount;
	int _isKillMobType;
	stGetItemGiver _KillMonTypes[5];
	int _iMaxMobCount;
	int _iMobCount;
	unsigned int _equipWeaponType;

	

};


