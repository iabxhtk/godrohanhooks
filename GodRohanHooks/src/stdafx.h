// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
// Windows Header Files:
#include "windows.h"
#include <list>
#include <map>
#include <iostream>
#define _ATL_CSTRING_EXPLICIT_CONSTRUCTORS      // some CString constructors will be explicit

#include "detours.h"

#include "SkillEvent.h"
#include "CSkill.h"
#include "CCritMgr.h"


#include "TrapScript.h"
#include "EntityBaseStatus.h"
#include "TrapEntity.h"
#include "SkillSlot.h"
#include "Structs.h"
#include "GlobalSettings.h"
#include "Qualities.h"
#include "QualitiesOption.h"
#include "PlayerItemSlotManager.h"
#include "CBiotic.h"
#include "ByteBuffer.h"
#include "CMapConnection.h"

#include "Player.h"
#include "CCrime.h"
#include "ByteBuffer.h"
#include "SkillEvent.h"
#include "IOCriticalSection.h"
#include "GOInterlocked.h"
#include "Hooks.h"
#include "BattleManager.h"
#include "SkillManager.h"
#include "Timer.h"

#include "RohanConnection.h"
#include "RemainedTimer.h"
#include "AIConnection.h"
#include "EpochItemManager.h"
#include "Structs.h"

#pragma comment(lib,"winmm.lib ")
#pragma comment( lib, "detours.lib" )
// TODO: reference additional headers your program requires here
