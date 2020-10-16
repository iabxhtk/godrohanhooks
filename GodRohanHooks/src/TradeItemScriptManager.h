#pragma once
class TradeItemScriptManager
{
public:
	std::map<int, NpcItemScriptManager *, std::less<int>, std::allocator<std::pair<int const, NpcItemScriptManager *> > > _mapNpcItemScriptManager;// std::map<int,CNpcItemScriptManager *,std::less<int>,std::allocator<std::pair<int const ,CNpcItemScriptManager *> > > m_mapNpcItemScriptManager;
	TradeItemList *_tradeItemList;                               // CTradeItemList *m_pTradeItemList;

};