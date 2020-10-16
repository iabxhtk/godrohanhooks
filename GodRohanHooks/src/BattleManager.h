#pragma once
#include <deque>
#include "Structs.h"


#pragma pack(push,4)
template <class T>
class OrderQueue {

public:
	std::deque<T, std::allocator<T> > _queue;
	int _size;
	IOCriticalSection _lock;
};


class BattleManager {

public:
	SATTACKRESULT _sar;
	CBiotic * _attacker;
	std::vector<CBiotic *, std::allocator<CBiotic *> > _vecAttackee;
	OrderQueue<SATTACKORDER> _queue;
	IOCriticalSection _crit;
};
void BattleManagerHooks(HMODULE hModule);
#pragma pack(pop)