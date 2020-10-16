#pragma once
#include "IOCriticalSection.h"
#include "Structs.h"
#include "Qualities.h"
#include "EpochItemScript.h"
#pragma pack(push,4)
class EpochItemBase
{
public:
	EpochID2 * GetEpochId()
	{
		return (EpochID2*)((char*)this + 0x00000020);
	}

	EpochItemScript * GetScript()
	{
		return (EpochItemScript*)*(int*)((char*)this + 0x0000001C);

	}
	int GetAttribute(int nAttributeType)
	{

		int(__thiscall *GetAttribute)(void*, int nAttributeType) = (int(__thiscall*)(void*, int nAttributeType))0x0068B2E0; //(0x006336D0) 0x0068B2E0
		return GetAttribute(this, nAttributeType);
	}
	int SetOption(int nOptionType, int nValue)
	{

		int(__thiscall *SetOption)(void*, int nOptionType, int nValue) = (int(__thiscall*)(void*, int nOptionType, int nValue))0x0068B490; //(0x00633880) 0x0068B490
		return SetOption(this, nOptionType , nValue);
	}
	void GetItemGR(tagItem *item)
	{
		auto GetItemGR = (void(__thiscall*)(void*, tagItem *item))0x0068B5C0; //(0x006339B0) 0x0068B5C0
		return GetItemGR(this, item);
	}
};
#pragma pack(pop)   