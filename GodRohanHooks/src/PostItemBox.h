#pragma once
#include "IOCriticalSection.h"
#include <map>
#include "EpochItem.h"
#include "Structs.h"

class PostItemBox {

private:
	std::map<unsigned long, tagItem *, std::less<unsigned long>, std::allocator<std::pair<unsigned long const, tagItem *> > > _mapLoadedAttachedItem;// std::map<unsigned long,__tagItem *,std::less<unsigned long>,std::allocator<std::pair<unsigned long const ,__tagItem *> > > m_mapLoadedAttachedItem;
	std::map<unsigned long, EpochItem *, std::less<unsigned long>, std::allocator<std::pair<unsigned long const, EpochItem *> > > _mapPlayerItem;// std::map<unsigned long,EpochItem *,std::less<unsigned long>,std::allocator<std::pair<unsigned long const ,EpochItem *> > > m_mapPlayerItem;
	IOCriticalSection _lock;                                     // CIOCriticalSection m_lock;



};
