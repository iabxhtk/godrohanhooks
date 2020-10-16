#pragma once
#include "stdafx.h"

class GOConnection
{
public:
	int SendPacket(unsigned __int16 nType, const void *pData, unsigned int nSize)
	{
		int(__thiscall *SendPacket)(void*, unsigned __int16 nType, const void *pData, unsigned int nSize) = (int(__thiscall*)(void*, unsigned __int16 nType, const void *pData, unsigned int nSize))0x00661850;//(0x006240B0) 0x00661850
		return SendPacket(this, nType, pData, nSize);
	}
};
// struct CRohanConnection
#pragma pack(push,4)
class RohanConnection : GOConnection {

public:
	//rc4_key_st _rC4Key;                                          // rc4_key_st m_RC4Key;
	char pad[0x4E4];
	

	int _keyInitialized;                                         // int m_bKeyInitialized;
	GOConnection *_logConnection;                                // CGOConnection *m_pLogConnection;
	GOConnection *_dBConnection;                                 // CGOConnection *m_pDBConnection;
	unsigned int _userId;                                        // unsigned int m_dwUserId;
	int * strngPtrcharName;// ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > m_szCharName;
	GOInterlocked _ilReconnecting;                               // CGOInterlocked m_ilReconnecting;
	int SendPacketEx(unsigned __int16 nType, void *pData, unsigned int nSize)
	{
		int(__thiscall *SendPacketEx)(void*, unsigned __int16, void *, unsigned int) = (int(__thiscall*)(void*, unsigned __int16, void *, unsigned int))0x0066A2C0;//(0x0062CE10) 0x0066A2C0
		return SendPacketEx(this, nType, pData, nSize);
	}
};
#pragma pack(pop)
