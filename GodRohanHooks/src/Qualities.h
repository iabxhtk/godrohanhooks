#pragma once
#ifndef QUALITIES_H
#define QUALITIES_H
#include "stdafx.h"
#pragma pack(push,4)
class CQualities {

public:
	//std::map<int, int, std::less<int>, std::allocator<std::pair<int const, int> > > _mapIntStore;// std::map<int,int,std::less<int>,std::allocator<std::pair<int const ,int> > > m_mapIntStore;
	char cqpad[0xC];
	IOCriticalSection *_lock;                                    // CIOCriticalSection *m_pLock;

};
#pragma pack(pop)
#endif