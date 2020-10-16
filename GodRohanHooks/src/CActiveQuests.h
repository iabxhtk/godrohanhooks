#pragma once
#include "CQuest.h"
#include <map>
#include <vector>
#include <list>
using namespace std;
class CActiveQuests
{
public:
	
	//map<int, CQuest *, less<int>, allocator<pair<int const , CQuest * > > > *map;
	CTimer m_timerQuestCheck;
};

