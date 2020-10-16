#pragma once
#include  "stdafx.h"

class  GlobalSettings
{
public:
	GlobalSettings()
	{
		
	}
	static DWORD max_level;
	static DWORD coliseum_min_level;
	static DWORD coliseum_max_level;
	static DWORD pet_cooldown;
	static DWORD worldMessageCost;
	static DWORD gmindunpointadd;
	static bool advancedHkOn;
	static char  welcomeMessage[256];
	static void GlobalSettingsConfig();
	static void ReadyGlobalSettings();
	static char  AutoMessage[256];
	static DWORD TimeAutoMessage;
	static bool hookGlobals();

};




