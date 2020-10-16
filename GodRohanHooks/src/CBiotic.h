#pragma once
#ifndef BIOTIC_H
#define BIOTIC_H
#include "stdafx.h"
#include "SkillManager.h"
#include "GOInterlocked.h"
#include "GeoRandom.h"
#include "AIConnection.h"
#include "Timer.h"
#include "RemainedTimer.h"
#include "EpochItemScriptManager.h"
#pragma pack(push,1)
struct StateID2
{
	int nType;
};
#pragma pack(pop,1)
#pragma pack(push,4)
class IOObject {

private:
	int * vfptr1;
	int _ref;                                                    // int m_nRef;
	int _systemRef;                                              // int m_nSystemRef;
	int _generalRef;                                             // int m_nGeneralRef;
};

class IOBase : IOObject {

private:
	unsigned int _bits;                                          // unsigned int m_dwBits;
	int _tempRef;                                                // int m_nTempRef;
	int _varRef;                                                 // int m_nVarRef;
};


class EntityBase : IOBase {

public:
	EpochID2 * GetEpochId()
	{
		return (EpochID2*)((char*)this + 0x0000002C);
	}
	_RTL_CRITICAL_SECTION  * GetCriticalSection()
	{
		return (_RTL_CRITICAL_SECTION*)((char*)this + 0x00000064);
	}
};

class BioticBase : public EntityBase {

public:
	StateID2 * GetState()
	{
		return (StateID2*)((char*)this + 0x00000084);
	}
	int GetAbility(int Ability)
	{
		int(__thiscall *GetAbility)(void*, int Ability) = (int(__thiscall*)(void*, int Ability))0x004EEC50; // (0x004D7D40) 0x004EEC50
		return GetAbility(this, Ability);
	}
	void SetAbility(int nAbility, int nValue)
	{
		void(__thiscall *SetAbility)(void*, int nAbility, int nValue) = (void(__thiscall*)(void*, int nAbility, int nValue))0x004EEBF0; //(0x004D7CE0) 0x004EEBF0
		return SetAbility(this, nAbility, nValue);
	}
	void ClearSkillCondition(unsigned int dwCondition, unsigned __int16 wSkillKind)
	{

		void(__thiscall *ClearSkillCondition)(void*, unsigned int dwCondition, unsigned __int16 wSkillKind) = (void(__thiscall*)(void*, unsigned int dwCondition, unsigned __int16 wSkillKind))0x004EF120;//(0x004D81F0) 0x004EF120
		return ClearSkillCondition(this, dwCondition, wSkillKind);

	}
};
;
class CBiotic : public BioticBase {

public:
	CSkillManager * GetSkillManager()
	{
		
		return (CSkillManager*)((char*)this + 0x00000100);
	}
	unsigned int GetRandom(int nStart, int nEnd)
	{
		auto GetRandom = (unsigned int(__thiscall*)(void*, int nStart, int nEnd))0x004D7A30; //(0x004C25A0) 0x004D7A30 
		return GetRandom(this, nStart, nEnd);
	}
	void ChangeConditionBySkill(unsigned int dwCondition, int nMilliSecond, unsigned __int16 wSkillKInd)
	{

		void(__thiscall *ChangeConditionBySkill)(void*, unsigned int dwCondition, int nMilliSecond, unsigned __int16 wSkillKInd) = (void(__thiscall*)(void*, unsigned int dwCondition, int nMilliSecond, unsigned __int16 wSkillKInd))0x004DAD00;//(0x004C54F0) 0x004DAD00
		return ChangeConditionBySkill(this, dwCondition, nMilliSecond, wSkillKInd);

	}
	void CalAllAbility()
	{

		void(__thiscall *CalAllAbility)(void*) = (void(__thiscall*)(void*))0x004D63C0;//(0x004C0F20) 0x004D63C0
		return CalAllAbility(this);
	}

	void BroadcastAddLife(int nDiff, char nReason)
	{

		void(__thiscall *BroadcastAddLife)(void*, int nDiff, char nReason) = (void(__thiscall*)(void*, int nDiff, char nReason))0x004D6590;//(0x004C10D0) 0x004D6590
		return BroadcastAddLife(this,  nDiff,  nReason);
	}

	char* GetName() {
		char*(__thiscall *GetName)(void*) = (char*(__thiscall*)(void*))0x004F02A0;//0x004D9100;
		return GetName(this);
	}

	EpochVector3 * GetPos()
	{
		EpochVector3*(__thiscall *GetPos)(void*) = (EpochVector3*(__thiscall*)(void*))5404576;
		return(EpochVector3 *)GetPos(this);
	}


};
bool CBioticHooks(HMODULE hModule);
#pragma pack(pop)
#endif
