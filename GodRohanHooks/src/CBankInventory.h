#pragma once
#include "CBiotic.h"
#include "AntiHackStructs.h"

class CBankInventory : IOBase {

public:
	__tagItem _inven[108];                                         // __tagItem m_Inven[108];
	unsigned int _userID;                                        // unsigned int m_dwUserID;
	unsigned int _charID;                                        // unsigned int m_dwCharID;
	int _load;                                                   // int m_bLoad;
	int _login;                                                  // int m_nLogin;
	int _maxSlot;                                                // int m_nMaxSlot;
	int _extendSlotCnt;                                          // int m_nExtendSlotCnt;
	int _expireTime;                                             // int m_nExpireTime;
	__int64 _bankMoney;                                          // __int64 m_nBankMoney;
	int GetItem(const int nSlot, __tagItem *pItem)
	{
		int(__thiscall *GetItem)(void*, const int nSlot, __tagItem *pItem) = (int(__thiscall*)(void*, const int nSlot, __tagItem *pItem))0x00550F30;//(0x00534980) 0x00550F30
		return GetItem(this, nSlot, pItem);
	}
};
class CBankMgr : IOObject {

public:
	CBankInventory * FindBank(const unsigned int dwUserID)
	{
		CBankInventory *(__thiscall *FindBank)(void*, const unsigned int dwUserID) = (CBankInventory *(__thiscall*)(void*, const unsigned int dwUserID))0x005533C0;//(0x00536FD0) 0x005533C0
		return FindBank(this, dwUserID);
	}
};
