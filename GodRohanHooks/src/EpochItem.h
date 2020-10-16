#pragma once
#include "MapEnums.h"
class EpochItem : public EpochItemBase {

public:
	int GetOption(int nOptionType)
	{

		int(__thiscall *GetOption)(void*, int nOptionType) = (int(__thiscall*)(void*, int nOptionType))0x0068B460;
		return GetOption(this, nOptionType);
	}
	bool IsArmor()
	{
		int nItemType = GetAttribute(Itemattributetype::IAT_ITEM_TYPE);
		if (nItemType >= Itemtype::IT_ARMOR_START && nItemType <= Itemtype::IT_ARMOR_END)
			return true;
		return false;
	}

	bool IsShield()
	{
		return GetAttribute(Itemattributetype::IAT_ITEM_TYPE) == Itemtype::IT_SHIELD;
	}
	bool IsWeapon()
	{
		int nItemType = GetAttribute(Itemattributetype::IAT_ITEM_TYPE);
		if (nItemType >= Itemtype::IT_WEAPON_START && nItemType <= Itemtype::IT_WEAPON_END)
			return true;
		return false;
	}

};
