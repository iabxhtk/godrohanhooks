#pragma once
#include "stdafx.h"
#include "Qualities.h"
class EntityBaseStatus
{

public:
	CQualities _qual;                                             // CQualities m_qual;
	int _type;                                                   // int m_nType;
	void incAbi(int nAbilityType, int nAddValue)
	{
		//function pointer here using any of the styles mentioned above
		void(__thiscall *incAbi)(void*, int, int) = (void(__thiscall*)(void*, int, int))0x006C00E0;//(0x00673930) 0x006C00E0
		return incAbi(this, nAbilityType, nAddValue);
	}
	int get(int nAbilityType)
	{
		//function pointer here using any of the styles mentioned above
		int(__thiscall *get)(void*, int) = (int(__thiscall*)(void*, int))0x004EAC40; //(0x004D3DA0) 0x004EAC40 //not sure
		return get(this, nAbilityType);
	}
};