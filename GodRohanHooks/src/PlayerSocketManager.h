#pragma once
#include "IOCriticalSection.h"
#include <map>
#pragma pack(push, 1)
struct tagGRSOCKETSLOT {
	char pos;                                                // char nPos;
	unsigned int type;                                       // unsigned int nType;
	unsigned int attach;                                     // unsigned int tAttach;
};
#pragma pack(pop)
#pragma pack (push,4)
struct _tagSocketAbuilityInfo
{
	int value;                                               // int nValue;
	char update;                                             // char bUpdate;
};
struct tagSOCKETITEMINFO {
	unsigned int lastAffect;                                 // unsigned int dwLastAffect;
	tagGRSOCKETSLOT slot;                                    // _tagGR_SOCKETSLOT Slot;
};
#pragma pack(pop)
class SocketSlot {

private:
	std::map<unsigned char, tagSOCKETITEMINFO, std::less<unsigned char>, std::allocator<std::pair<unsigned char const, tagSOCKETITEMINFO> > > _mapSocketItemInfo;// std::map<unsigned char,_tagSOCKETITEMINFO,std::less<unsigned char>,std::allocator<std::pair<unsigned char const ,_tagSOCKETITEMINFO> > > m_mapSocketItemInfo;
	IOCriticalSection _crit;                                     // CIOCriticalSection m_crit;

};
class PlayerSocketManager {

private:
	CPlayer *_player;                                             // CPlayer *m_pPlayer;
	IOCriticalSection _crit;                                     // CIOCriticalSection m_crit;
	char playersocketmgrpad[0x30];
	//std::map<unsigned long, SocketSlot *, std::less<unsigned long>, std::allocator<std::pair<unsigned long const, SocketSlot *> > > _mapPlayerSocketSlot;// std::map<unsigned long,CSocketSlot *,std::less<unsigned long>,std::allocator<std::pair<unsigned long const ,CSocketSlot *> > > m_mapPlayerSocketSlot;
	//std::map<unsigned long, unsigned long, std::less<unsigned long>, std::allocator<std::pair<unsigned long const, unsigned long> > > _mapEquip;// std::map<unsigned long,unsigned long,std::less<unsigned long>,std::allocator<std::pair<unsigned long const ,unsigned long> > > m_mapEquip;
	//std::map<unsigned long, _tagSocketAbuilityInfo, std::less<unsigned long>, std::allocator<std::pair<unsigned long const, _tagSocketAbuilityInfo> > > _mapEquipAttribute;// std::map<unsigned long,_tagSocketAbuilityInfo,std::less<unsigned long>,std::allocator<std::pair<unsigned long const ,_tagSocketAbuilityInfo> > > m_mapEquipAttribute;
	//std::map<unsigned long, _tagSocketAbuilityInfo, std::less<unsigned long>, std::allocator<std::pair<unsigned long const, _tagSocketAbuilityInfo> > > _mapEquipOption;// std::map<unsigned long,_tagSocketAbuilityInfo,std::less<unsigned long>,std::allocator<std::pair<unsigned long const ,_tagSocketAbuilityInfo> > > m_mapEquipOption;
	IOCriticalSection _critAbilityInfo;                          // CIOCriticalSection m_critAbilityInfo;



};
