#pragma once
#ifndef IOCRITICALSECTION_H
#define IOCRITICALSECTION_H
#include <winnt.h>

class IOCriticalSection {

public:
	_RTL_CRITICAL_SECTION _criticalSection;                      // _RTL_CRITICAL_SECTION m_critical_section;

};

#endif