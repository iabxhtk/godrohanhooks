#pragma once
#include "EpochItem.h"
void PetHooks(HMODULE hModule);
class PetBase {

public:
	intptr_t * vfptr;
	CPlayer *_owner;                                              // CPlayer *m_pOwner;
	EpochItem *_petItem;                                         // EpochItem *m_pPetItem;
	int _level;                                                  // int m_nLevel;
	int _feedCount;                                              // int m_nFeedCount;
	int _lifeTimeMinute;                                         // int m_nLifeTimeMinute;
	int _hungryCount;                                            // int m_nHungryCount;
	int _maxHungryCount;                                         // int m_nMaxHungryCount;
	int _hungryTime;                                             // int m_nHungryTime;
	int _feedTime;                                               // int m_nFeedTime;
	int _isHealingPet;                                           // int m_bIsHealingPet;
	int _isTelePet;                                              // int m_bIsTelePet;
	int _positionMemorize;                                       // int m_bPositionMemorize;
	int _summon;                                                 // int m_bSummon;
	int _deadWarning;                                            // int m_bDeadWarning;
	int _active;                                                 // int m_bActive;
	int m_bTimerAlarm;
	int m_bTimerEffect;
	RemainedTimer _timerPetLife;                                 // CRemainedTimer m_timerPetLife;
	RemainedTimer _timerPetTimerSync;                            // CRemainedTimer m_timerPetTimerSync;
	RemainedTimer _timerHungry;                                  // CRemainedTimer m_timerHungry;
	RemainedTimer _timerEffect;                                  // CRemainedTimer m_timerEffect;
	RemainedTimer _timerAlarm;                                   // CRemainedTimer m_timerAlarm;
	RemainedTimer _timerAction1;                                 // CRemainedTimer m_timerAction1;
	RemainedTimer _timerTeleportCoolTime;                        // CRemainedTimer m_timerTeleportCoolTime;
	IOCriticalSection _crit;                                     // CIOCriticalSection m_Crit;
	void SetDamagePet(int bOnOff)
	{

		void(__thiscall *SetDamagePet)(void*, int bOnOff) = (void(__thiscall*)(void*, int bOnOff))0x005C1BC0;
		return SetDamagePet(this, bOnOff);
	}
};

class Pet : public PetBase {


public:
};
