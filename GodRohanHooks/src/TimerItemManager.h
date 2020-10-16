#pragma once
#include "IOCriticalSection.h"
#include <map>
#pragma pack(push, 8)
class CTimerItem
{
	RemainedTimer m_timerSave;
	RemainedTimer m_timerSync;
	int64_t m_TerminationTime;
	int32_t m_pItem;
	EpochID2 m_ItemID;
	int8_t m_bActive;
};
#pragma pack(pop)
class TimerItemManager {

private:
	int _count;                                                  // int m_nCount;
	CPlayer *_player;                                             // CPlayer *m_pPlayer;
	std::map<unsigned long, CTimerItem *, std::less<unsigned long>, std::allocator<std::pair<unsigned long const, CTimerItem *> > > _mapTimerItem;// std::map<unsigned long,CTimerItem *,std::less<unsigned long>,std::allocator<std::pair<unsigned long const ,CTimerItem *> > > m_mapTimerItem;
	IOCriticalSection _crit;                                     // CIOCriticalSection m_Crit;
};
class TimerEndItemManager {

private:
	IOCriticalSection _crit;                                     // CIOCriticalSection m_Crit;
	std::list<EpochItem *, std::allocator<EpochItem *> > _list;   // std::list<EpochItem *,std::allocator<EpochItem *> > m_list;
																  // CIOCriticalSection m_Crit;
};
