#pragma once

#include <vector>
#include "Structs.h"
#include "SkillScript.h"

// struct CSkill
#pragma pack(push,4)
class CSkill {

public:
	// $A795906CB7EB9D2F97526BE82431F506 ___u0;
	//union $A795906CB7EB9D2F97526BE82431F506
	union {
		SkillScript baseclass0;                              // CSkillScript baseclass_0;
		float clientskilltimer;                              // float m_ClientSkillTimer;
	} _u0;

	float _fClientStateTimeStamp;                                // float m_fClientStateTimeStamp;
	//std::vector<tagITEMINFO, std::allocator<tagITEMINFO> > _arrUseSkillItemInfo;// std::vector<_tagITEM_INFO,std::allocator<_tagITEM_INFO> > m_arrUseSkillItemInfo;
	char vectPad[0x10];
	tagSkill _skillState;                                        // _tagSkill m_SkillState;
	EpochID2 _epochId;                                           // EpochID2 m_EpochId;
	unsigned int _manaPerSecEvent;                               // unsigned int m_dwManaPerSecEvent;
	unsigned int _targetEntity;                                  // unsigned int m_dwTargetEntity;
	int _forceAttack;                                            // int m_bForceAttack;
	EpochVector3 _targetPos;                                  // _tagEpochVector3 m_TargetPos;
	unsigned int _cancelReason;                                  // unsigned int m_dwCancelReason;
	unsigned int _requestCancelReason;                           // unsigned int m_dwRequestCancelReason;
	tagITEMINFO _useItem;                                        // _tagITEM_INFO m_useItem;
	int _scrollBind;                                             // int m_nScrollBind;
	int _useStack;                                               // int m_nUseStack;
	int _learnGuildSkill;                                        // int m_nLearnGuildSkill;
	int _currRemainCoolingTime;                                  // int m_nCurrRemainCoolingTime;
	char _maxAvailableLevel;                                     // char m_nMaxAvailableLevel;
	int _igoreCooling;                                           // int m_bIgoreCooling;
	tagSkillLevelInfo * GetSkillLevelInfo()
	{

		tagSkillLevelInfo *(__thiscall *GetSkillLevelInfo)(void*) = (tagSkillLevelInfo *(__thiscall*)(void*))0x00437070;//(0x00433500) 0x00437070
		return GetSkillLevelInfo(this);

	}
};
#pragma pack(pop)