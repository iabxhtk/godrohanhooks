#pragma once
#include <map>
#include <list>
#include "Structs.h"
#include "EpochItemScriptManager.h"
#include "NpcItemScriptManager.h"

class TradeItemList {

public:
	std::map<int, std::list<STRADEITEM, std::allocator<STRADEITEM> > *, std::less<int>, std::allocator<std::pair<int const, std::list<STRADEITEM, std::allocator<STRADEITEM> > *> > > _mapTradeItem;// std::map<int,std::list<STRADEITEM,std::allocator<STRADEITEM> > *,std::less<int>,std::allocator<std::pair<int const ,std::list<STRADEITEM,std::allocator<STRADEITEM> > *> > > m_mapTradeItem;
	EpochItemScriptManager *_epochItemScriptManager;             // CEpochItemScriptManager *m_pEpochItemScriptManager;

	NpcItemScriptManager * GetList(int nNpcID)
	{
		NpcItemScriptManager *(__thiscall *GetList)(void*, int nNpcID) = (NpcItemScriptManager*(__thiscall*)(void*, int nNpcID))0x006B73F0;
		return GetList(this, nNpcID);
	}
	
};
