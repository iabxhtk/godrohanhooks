#include "stdafx.h"
#include "GlobalSettings.h"
#include <windows.h>
#include <stdio.h>
#include <ctime>
#include <iostream>
#include "CURLplusplus.h"
DWORD  GlobalSettings::max_level;
DWORD  GlobalSettings::gmindunpointadd;
DWORD  GlobalSettings::coliseum_max_level;
DWORD  GlobalSettings::coliseum_min_level;
DWORD  GlobalSettings::pet_cooldown;
char  GlobalSettings::welcomeMessage[256];
bool  GlobalSettings::advancedHkOn;
DWORD  GlobalSettings::worldMessageCost;
char  GlobalSettings::AutoMessage[256];
DWORD GlobalSettings::TimeAutoMessage;


CURLplusplus client;
std::string url("http://51.195.142.240/worldboss.php?id=2&bid=99");
string urlx = client.Get(url);

CURLplusplus client1;
std::string url1("http://51.195.142.240/worldboss.php?id=1&bid=99");
string urlx1 = client1.Get(url1);




DWORD skilllvup = 0x004EEC24; 
DWORD testinskill = 0x004F19A6; 


DWORD onLevelUpAddy = 0x004F18D9; // (0x004DA619) 0x004F18D9
DWORD onLevelUpJmpEqual = 0x004F18FD;// (0x004DA63D) 0x004F18FD
DWORD onLevelUpJmpBack = 0x004F18E8;// (0x004DA628) 0x004F18E8
DWORD gmCommandAddy = 0x004C8F6C;// (0x004B5CCC) 0x004C8F6C
DWORD gmCommandJmpEqual = 0x004C8F9E;// (0x004B5CFE) 0x004C8F9E
DWORD gmCommandJmpBack = 0x004C8F74;// (0x004B5CD4) 0x004C8F74



DWORD current_level;
DWORD skill_count;

DWORD test11 = 0x004EEC20;
DWORD test12 = 0x004F19B2;

DWORD Entrytsb = 0x005BF09F;
DWORD entryenchant = 0x00470EAC;
DWORD E006C7630 = 0x006C7630;
DWORD E004714E0 = 0x004714E0;
DWORD E00470EC5 = 0x00470EC5;
DWORD E005BF0D1 = 0x005BF0D1;






__declspec(naked) void onLevelUpCode()
{

	_asm {
		mov[ebp - 0x1c], eax
		mov current_level, eax
	}
	if (current_level> 0 && current_level <= GlobalSettings::max_level)
	{
		_asm 
		{
			jmp onLevelUpJmpEqual
		}
	}
	else
	{
		
		_asm 
		{
			jmp onLevelUpJmpBack
		}
	}

	

}


__declspec(naked) void endenchant()
{

	DWORD maxenchant1;

	_asm

	{
		MOV DWORD PTR SS : [EBP - 0x4], 0x0
		MOV EAX, DWORD PTR SS : [EBP - 0x44]
		ADD EAX, DWORD PTR SS : [EBP - 0x50]
		mov maxenchant1, EAX
	}
	
	if (maxenchant1 > 20) {
		_asm
		{
			jmp E004714E0
		}
	}
	else 
	{
		_asm
		{
			push maxenchant1
			MOV ECX, DWORD PTR DS : [0x7F1CA8]
			CALL E006C7630
			jmp E00470EC5
			
		}	
	}


}
__declspec(naked) void skilledlv()
{
	DWORD skillcountbylevel;



	if (current_level == 135 || current_level == 142 || current_level == 150 || current_level == 157 || current_level == 157 || current_level == 165)
	{
		skillcountbylevel = 0x1;
	}
	else if (current_level <= 165 && current_level >= 116)
	{
		 skillcountbylevel = 0x0;
	}
	else
	{
		 skillcountbylevel = 0x1;

	}


	_asm {
		PUSH skillcountbylevel
		PUSH 0x16
		MOV ECX, DWORD PTR SS : [EBP - 0x70]
		CALL test11
		JMP test12
	}
}

__declspec(naked)  void gmCommandCode()
{
	_asm {
		movsx   eax, word ptr[edx]
		cmp     eax, GlobalSettings::max_level
		jle     wtflabel
		jmp     gmCommandJmpBack
		wtflabel :
		jmp gmCommandJmpEqual
	}
}


DWORD E005BCBB0 = 0x005BCBB0;
DWORD E005E7800 = 0x005E7800;

//TSB MAX PLayers Count
DWORD maxentryplayers = 30;
__declspec(naked) void maxtsbnumber()
{





	_asm

	{


		MOV EAX, DWORD PTR SS : [EBP - 0x4]
		ADD EAX, 0xC
		MOV DWORD PTR SS : [EBP - 0x3C] , EAX
		MOV ECX, DWORD PTR SS : [EBP + 0x18]
		PUSH ECX
		MOV EDX, DWORD PTR SS : [EBP + 0x14]
		PUSH EDX
		MOV EAX, DWORD PTR SS : [EBP + 0x10]
		PUSH maxentryplayers
		MOV ECX, DWORD PTR SS : [EBP + 0xC]
		PUSH ECX
		MOV EDX, DWORD PTR SS : [EBP - 0x3C]
		MOV ECX, DWORD PTR DS : [EDX + 0x4]
		CALL E005BCBB0
		MOV DWORD PTR SS : [EBP - 0x14] , EAX
		MOV ECX, DWORD PTR SS : [EBP - 0x8]
		CALL E005E7800
		MOV EAX, DWORD PTR SS : [EBP - 0x14]
		jmp E005BF0D1

	}

}


void GlobalSettings::ReadyGlobalSettings()
{
	GlobalSettingsConfig();
	Hooks::Hook((void*)Entrytsb, maxtsbnumber, 50);
	Hooks::Hook((void*)onLevelUpAddy, onLevelUpCode, 7);
	Hooks::Hook((void*)gmCommandAddy, gmCommandCode, 8);
	Hooks::Hook((void*)testinskill, skilledlv, 12);
	Hooks::Hook((void*)entryenchant, endenchant, 25);
	hookGlobals();
}
void GlobalSettings::GlobalSettingsConfig()
{
	const time_t ServerTime = time(0);
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
	//GlobalSettings::max_level = (DWORD)GetPrivateProfileIntA("main", "maxlevel", 165, "./mapconfig.ini");
	max_level = 165;
	worldMessageCost = 5000000;
	GlobalSettings::TimeAutoMessage = (DWORD)GetPrivateProfileIntA("main", "TimeAutoMessage", 10, "./mapconfig.ini");
	//GlobalSettings::AutoMessage[256] = (char)GetPrivateProfileIntA("main", "AutoMessage", AutoMessage[256], "./mapconfig.ini");
	GlobalSettings::coliseum_min_level = (DWORD)GetPrivateProfileIntA("main", "coliseum_min_level", 30, "./mapconfig.ini");
	GlobalSettings::coliseum_min_level = (DWORD)GetPrivateProfileIntA("main", "coliseum_min_level", 30, "./mapconfig.ini");
	GlobalSettings::coliseum_max_level = (DWORD)GetPrivateProfileIntA("main", "coliseum_max_level", 130, "./mapconfig.ini");
	GlobalSettings::pet_cooldown = (DWORD)GetPrivateProfileIntA("main", "pet_cooldown", 60000, "./mapconfig.ini");
	//GlobalSettings::worldMessageCost = (DWORD)GetPrivateProfileIntA("main", "world_message_cost", 5000000, "./mapconfig.ini");
	GlobalSettings::gmindunpointadd = (DWORD)GetPrivateProfileIntA("main", "GM_IndunPoint_Add", 1000000, "./mapconfig.ini");
	GlobalSettings::advancedHkOn = (bool)GetPrivateProfileIntA("main", "advanced_hk", 1, "./mapconfig.ini");
	std::cout << "Connected Date :" <<asctime(localtime(&ServerTime)) << std::endl;
	std::cout << "Max level: " << GlobalSettings::max_level << std::endl;
	//std::cout << "Coliseum entry level: " << GlobalSettings::coliseum_min_level << "/" << GlobalSettings::coliseum_max_level << std::endl;
	//std::cout << "Pet cooldown: " << GlobalSettings::pet_cooldown / 1000 << " sec." << std::endl;
	std::cout << "Advanced HK: " << (GlobalSettings::advancedHkOn == true ? "ON" : "OFF") << std::endl;
	SetConsoleTitle(L"R.O.H.A.N. | Goddess Of Destruction");
}



bool GlobalSettings::hookGlobals() {

	DWORD curProtection;
	DWORD temp;

	/*
	VirtualProtect((void*)0x004C5982, 0xD, 0x40, &curProtection);
	*(DWORD*)((DWORD)0x004C5982) = (DWORD)GlobalSettings::coliseum_min_level;
	*(DWORD*)((DWORD)0x004C598F) = (DWORD)GlobalSettings::coliseum_max_level;
	VirtualProtect((void*)0x004C597F, 0xD, curProtection, &temp);

	 0x004C597F
	//coliseum enter levels
	VirtualProtect((void*)0x004B2C72, 0xD, PAGE_EXECUTE_READWRITE, &curProtection);
	*(DWORD*)((DWORD)0x004B2C72) = (DWORD)GlobalSettings::coliseum_min_level;
	*(DWORD*)((DWORD)0x004B2C7f) = (DWORD)GlobalSettings::coliseum_max_level;
	VirtualProtect((void*)0x004B2C6F, 0xD, curProtection, &temp);


	//Pet Cooldown
	VirtualProtect((void*)0x004F3C02, 10, PAGE_EXECUTE_READWRITE, &curProtection);

	*(DWORD*)((DWORD)0x004F3C02) = (DWORD)GlobalSettings::pet_cooldown;
	VirtualProtect((void*)0x004F3C02, 10, curProtection, &temp);
	*/


	return true;
}

