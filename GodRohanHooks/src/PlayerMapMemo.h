#pragma once

#include <vector>
#include "IOCriticalSection.h"
#include "Structs.h"

class CPlayerMapMemo
{
public :
	IOCriticalSection _crit;                                     // CIOCriticalSection m_Crit;
	std::vector<_tagGR_MAP_MEMO, std::allocator<_tagGR_MAP_MEMO> > _memo;// std::vector<_tagGR_MAP_MEMO,std::allocator<_tagGR_MAP_MEMO> > m_Memo;
	int _load;                                                   // int m_bLoad;
	int _request;                                                // int m_bRequest;
};
