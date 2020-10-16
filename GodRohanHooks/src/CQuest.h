#pragma once
#include "QuestTemplate.h"
#include <map>



class CQuest 
{

public:
	QuestTemplate *QuestTemplate;
	CPlayerQuestManager *_pQuestMgr;
	int _bCompletion;
	int _bNeedSaveDB;
	int _iQuestID;
	int _iSubQuestCount;
	int _bIteration;
	bool _bTimerQuest;
	int _bFailed;
	int _ttEndExecuteDateTime;
	int _ttReacceptDateTime;
	int _nSeqNumber;
	__int16 _nCompletion;
	int _bLadderQuest;
	QuestTimer m_QuestTimer;
//	std::list<ISubQuest * , std::allocator<ISubQuest *> > _SubQuestList;
};

