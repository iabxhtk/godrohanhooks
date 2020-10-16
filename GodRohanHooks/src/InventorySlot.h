#pragma once
#include "stdafx.h"
#include "EpochItemBase.h"

// struct CInventorySlot
#pragma pack(push,4)
class InventorySlot {

public:
	EpochItemBase  * _item[512];                         // CIOAutoVar<EpochItemBase> m_pItem[512];
	EpochItemBase *  _bagItem;                           // CIOAutoVar<EpochItemBase> m_pBagItem;
	int _static;                                                 // int m_bStatic;
	int _allowCount;                                             // int m_nAllowCount;
	int _curCount;                                               // int m_nCurCount;
	int _noWeight;                                               // int m_bNoWeight;
	int _noDrop;                                                 // int m_bNoDrop;
};
#pragma pack(pop)