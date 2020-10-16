#pragma once
#include "CBiotic.h"
class CEntityManager 
{
public:



	CBiotic* FindBiotic(unsigned int dwEntityID) {
		CBiotic*(__thiscall *FindBiotic)(void*, unsigned int dwEntityID) = (CBiotic*(__thiscall*)(void*, unsigned int dwEntityID))0x004DE4E0;//(0x004C88D0) 0x004DE4E0
		return FindBiotic(this, dwEntityID);
	}
	CBiotic* FindBiotic(const char *pszName, unsigned int dwFlag) {
		CBiotic*(__thiscall *FindBiotic)(void*, const char *pszName, unsigned int dwFlag) = (CBiotic*(__thiscall*)(void*, const char *pszName, unsigned int dwFlag))0x004DE650;//(0x004C8A40) 0x004DE650
		return FindBiotic(this, pszName, dwFlag);
	}
	CBiotic* FindPlayer(const char *lpszName) {
		CBiotic*(__thiscall *FindPlayer)(void*, const char *lpszName) = (CBiotic*(__thiscall*)(void*, const char *lpszName))0x004DECE0;//(0x004C90D0) 0x004DECE0
		return FindPlayer(this, lpszName);
	}
	CPlayer* GetPlayer(unsigned int dwEntityID) {
		auto GetPlayer = (CPlayer*(__thiscall*)(void*, unsigned int dwEntityID))0x004DE5D0;//(0x004C89C0) 0x004DE5D0 
		return GetPlayer(this, dwEntityID);
	}
	void BroadcastAllPlayer(int nProtocal, void *pData, int nSize)
	{
		auto BroadcastAllPlayer = (void(__thiscall*)(void*, int nProtocal, void *pData, int nSize))0x004DED50;//(0x004C9140) 0x004DEE00
		return BroadcastAllPlayer(this, nProtocal, pData, nSize);
	}
};
