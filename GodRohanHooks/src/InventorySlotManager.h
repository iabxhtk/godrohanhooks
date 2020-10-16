#pragma once
#ifndef INVENTORY_SLOT_MANAGER_H
#define INVENTORY_SLOT_MANAGER_H
#include "stdafx.h"
#include "InventorySlot.h"

class InventorySlotManager {

public:
	int * vfptr1;
	InventorySlot *_inventorySlot;                               // CInventorySlot *m_pInventorySlot;
	int _inventoryCount;                                         // int m_nInventoryCount;
	IOCriticalSection _crit;                                     // CIOCriticalSection m_crit;


};
#endif