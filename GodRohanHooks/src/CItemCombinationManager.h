#pragma once

struct CItemCombination
{
	int m_nMakeItem;
	int m_nMeterial1;
	int m_nMeterial2;
	int m_nSet;
	int m_nSuccessRate;
	int m_nCost;
};


class CItemCombinationSystem
{
public:

	CItemCombination * GetItemCombination(const int nMakeItem)
	{
		auto GetItemCombination = (CItemCombination *(__thiscall*)(void*, const int nMakeItem))0x006C6AE0;
		return GetItemCombination(this, nMakeItem);
	}
};
struct _RTL_CRITICAL_SECTION;
class CItemCombinationManager
{
public:


	static CItemCombinationManager * GetInstance()
	{
		return (CItemCombinationManager*)*(int*)0x007F1C8C;
	}
	CItemCombinationSystem * GetItemCombinationSystem()
	{
		return (CItemCombinationSystem*)*(int*)((char*)this + 0x4);
	}
	int GetSuccessRate(const int nMakeItem)
	{
		auto GetSuccessRate = (int(__thiscall*)(void*, const int nMakeItem))0x0055E250;
		return GetSuccessRate(this, nMakeItem);
	}
	_RTL_CRITICAL_SECTION  * GetCriticalSection()
	{
		return (_RTL_CRITICAL_SECTION*)((char*)this + 0x8);
	}

	 
};
