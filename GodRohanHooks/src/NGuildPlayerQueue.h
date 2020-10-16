#pragma once
#include "IOCriticalSection.h"
#include <deque>
#pragma pack(push,4)
struct SGUILDPLAYERQUEUENODE
{
	int16_t dwPacketID;

};
#pragma pack(pop)
class NGuildPlayerQueue {

private:
	std::deque<SGUILDPLAYERQUEUENODE, std::allocator<SGUILDPLAYERQUEUENODE> > _queue;// std::deque<SGUILDPLAYERQUEUENODE,std::allocator<SGUILDPLAYERQUEUENODE> > m_queue;
	IOCriticalSection _lock;                                     // CIOCriticalSection m_lock;



};
