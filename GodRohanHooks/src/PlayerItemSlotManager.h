#pragma once
#ifndef PLAYER_ITEM_SLOT_MANAGER_H
#define PLAYER_ITEM_SLOT_MANAGER_H
#include "PlayerItemSlotBaseManager.h"
#pragma pack(push,8)
class CPlayer;
class PlayerItemSlotManager : PlayerItemSlotBaseManager {

public:
	CPlayer *_player;                                             // CPlayer *m_pPlayer;
	QualitiesOption _optionAttr;                                 // CQualitiesOption m_optionAttr;
	QualitiesOption _optionMagic;                                // CQualitiesOption m_optionMagic;
	IOCriticalSection _crit;                                     // CIOCriticalSection m_crit;
	int _totalWeight;                                            // int m_nTotalWeight;
	char _weightState;                                           // char m_nWeightState;
	int _timerItemCheck;                                         // int m_bTimerItemCheck;
	//SetItem::SetItemManager _mgrSetItem;                         // SetItem::SetItemManager m_mgrSetItem;
	char pad1[0x14];
	__int64 _charmItemMask;                                      // __int64 m_nCharmItemMask;
	__int64 _charmItemApplyMask;                                 // __int64 m_nCharmItemApplyMask;
	char pad[0x20];                                        // RepairMgr m_mgrRepair;
	EpochItemBase * GetItem(int nInventory, int nSlot)
	{
		EpochItemBase *(__thiscall *GetItem)(void*, int nInventory, int nSlot) = (EpochItemBase *(__thiscall*)(void*, int nInventory, int nSlot))0x006998B0;//(0x0063F1B0) 0x006998B0
		return GetItem(this, nInventory, nSlot);
	}
	

	int CreateMallItem(int nItemType, int nCount, tagItem *itemPingMall, int *bAddCurStack)
	{
		auto CreateMallItem = (int(__thiscall*)(void*, int nItemType, int nCount, tagItem * itemPingMall, int *bAddCurStack))0x00572480;
		return CreateMallItem(this, nItemType, nCount, itemPingMall, bAddCurStack);
	}



	

};



#pragma pack(pop)
#endif