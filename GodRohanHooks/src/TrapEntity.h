// struct CTrapEntity
#pragma once
#ifndef TRAPENTITY_H
#define TRAPENTITY_H
#include "stdafx.h"
#include "RemainedTimer.h"
#include "Timer.h"


class TrapEntity  {

public:
	char pad[0xCC0];
	std::string _strName;// ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > m_strName;
	unsigned int _ownerID;                                       // unsigned int m_dwOwnerID;
	unsigned __int16 _skillKind;                                 // unsigned __int16 m_wSkillKind;
	int _skillLevel;                                             // int m_nSkillLevel;
	int _param1;                                                 // int m_nParam1;
	int _param2;                                                 // int m_nParam2;
	int _param3;                                                 // int m_nParam3;
	int _param4;                                                 // int m_nParam4;
	int _forceAttack;                                            // int m_bForceAttack;
	int _fireAuraSkill;                                          // int m_bFireAuraSkill;
	unsigned __int16 _auraSkill;                                 // unsigned __int16 m_wAuraSkill;
	unsigned __int16 _randomAffectSkill;                         // unsigned __int16 m_wRandomAffectSkill;
	int _randomAttack;                                           // int m_bRandomAttack;
	int _randomTargetIndex;                                      // int m_nRandomTargetIndex;
	Timer _timerSkillAct;                                        // CTimer m_timerSkillAct;
	TrapScript *_script;                                         // CTrapScript *m_pScript;
	int _attackType;                                             // int m_nAttackType;
	int _onlyOnceFire;                                           // int m_bOnlyOnceFire;
	int _allAttack;                                              // int m_bAllAttack;
	unsigned __int16 _allAffectSkill;                            // unsigned __int16 m_wAllAffectSkill;
	unsigned int _processingCount;                               // unsigned int m_dwProcessingCount;
	unsigned int _affectSkillPointer;                            // unsigned int m_dwAffectSkillPointer;
	RemainedTimer _timerAlive;                                   // CRemainedTimer m_timerAlive;

};
#endif