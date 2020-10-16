#pragma once
#include "stdafx.h"
#include "RohanConnection.h"

#pragma pack(push,4)
class AIConnection : RohanConnection {

public:
	int _aIIndex;                                                // int m_nAIIndex;
	volatile int _iRCount;                                       // volatile int m_nIRCount;
	char _aIMapInfo[256];                                        // char m_nAIMapInfo[256];

};
#pragma pack(pop)