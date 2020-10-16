#pragma once
#include "CPlayerQuestManager.h"
class CCompletedQuests
{
public:
	std::map<int, short, std::less<int>, std::allocator<std::pair<int const, short> > > m_map;
};
