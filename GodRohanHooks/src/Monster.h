#pragma once
#include "CBiotic.h"
#include "Structs.h"
#include "MonsterScript.h"
#include "MonsterHostility.h"




class Biotic : public BioticBase {

public:
	//Zero<long> _mapRef;                                          // Zero<long> m_nMapRef;
	//ATL::CStringT<char, StrTraitMFC<char, ATL::ChTraitsCRT<char> > > m_szLogName; // ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > m_szLogName;
	char Pad[0x8];
	unsigned int _aIConnId;                                      // unsigned int m_dwAIConnId;
	int _mapIndex;                                               // int m_nMapIndex;
	int _genID;                                                  // int m_dwGenID;
	int _genPatrolIndex;                                         // int m_GenPatrolIndex;
	int _groupLinkIndex;                                         // int m_GroupLinkIndex;
	char _grade;                                                 // char m_nGrade;
	char _skillSlot[0x1B0];                                     // CSkillManager m_SkillSlot;
	char _ilBattleIndex[0x8];                                // CGOInterlocked m_ilBattleIndex;
	unsigned int _attackTargetID;                                // unsigned int m_dwAttackTargetID;
	int _attackType;                                             // int m_nAttackType;
	int _forceAttack;                                            // int m_bForceAttack;
	unsigned int _lifeManaIndex;                                 // unsigned int m_nLifeManaIndex;
	char _random[0x9CC];                                           // CGeoRandom m_random;
	int _timerRecovery;                                        // CTimer m_timerRecovery;
																 //IOAutoVar<CAIConnection> _aIConnection;                      // CIOAutoVar<CAIConnection> m_pAIConnection;
	int *m_pAIConnection;
	int _remainedTimerSkillDelay;                      // CRemainedTimer m_remainedTimerSkillDelay;
	int _deadCount;                                              // int m_nDeadCount;
	int _criticalAttack;                                         // int m_bCriticalAttack;
	int _criticalAttacked;                                       // int m_bCriticalAttacked;
	int _invincibleGuildMaster;                                  // int m_bInvincibleGuildMaster;
	int _removeEntity;                                           // int m_bRemoveEntity;
	int _invincibleBySBindston;                                  // int m_bInvincibleBySBindston;
	unsigned int _lastUpdateTime;                                // unsigned int m_LastUpdateTime;
	unsigned int _needUpdateElaspedTime;                         // unsigned int m_NeedUpdateElaspedTime;
	void RemoveBiotic(unsigned int dwDelayTime) {
		void(__thiscall *RemoveBiotic)(void*, unsigned int dwDelayTime) = (void(__thiscall*)(void*, unsigned int dwDelayTime))0x004D6260;//0x004C0EE0;
		return RemoveBiotic(this, dwDelayTime);
	}
	char* GetName() {
		char*(__thiscall *GetName)(void*) = (char*(__thiscall*)(void*))0x004F02A0;//0x004D9100;
		return GetName(this);
	}
};
#pragma pack(pop)







class Monster : public CBiotic {
public:

	MonsterHostility _hostility;                                 // CMonsterHostility m_hostility;
	MonsterScript *_script;                                      // CMonsterScript *m_pScript;
	
	
	char* GetMonsterName() {
		char*(__thiscall *GetKorName)(void*) = (char*(__thiscall*)(void*))0x005829C0;
		return GetKorName(this);
	}

	void CalAllAbility()
	{

		void(__thiscall *CalAllAbility)(void*) = (void(__thiscall*)(void*))0x00582C10;
		return CalAllAbility(this);
	}


};


