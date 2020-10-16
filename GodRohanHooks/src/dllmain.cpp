#include "stdafx.h"
#include "AntiHack.h"
#include <stdio.h>
#include "PortalManager.h"
#include <concrt.h>
#include "AdvancedHK.h"
#include "VipManager.h"
#include "Spawner.h"
static HANDLE hConsole;
static HMODULE hModule;
void CreateConsole()
{
	
	AllocConsole();
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	freopen("CONOUT$", "w", stdout);
	freopen("CONIN$", "r", stdin);
}







char * test4 = "# ANTIHACK LOADED #";
char * test3 = "# ANTICRASH LOADED #";
char * test02 = "R.O.H.A.N. | Goddess Of Destruction";
//char * test2 = "BY KTHXBAI2";
char * roha = "Roha";




DWORD printAddy = 0x005E3930;//(0x005B5BA0) 0x005E3930
DWORD jmpBack = 0x004939CA;//(0x00483B0A) 0x004939CA
__declspec(naked) void printHello()
{
	_asm {
		/*push test4
		call printAddy
		push test3
		call printAddy*/
		push test02
		call printAddy
		add ESP, 0x24
		push roha
		jmp jmpBack
	}
}
void initAll()
{
	
	AdvancedHK::getInstance().ApplyHook(hModule);
	AdvancedHK::getInstance().readXMLConfig();
	VipManager::getInstance().LoadVips();
	VipManager::getInstance().StartReloadThread();
	GlobalSettings::ReadyGlobalSettings();
	GlobalSettings::hookGlobals();
	CPlayer::ApplyHooks(hModule);
	AntiHack::ApplyHooks(hModule);
	CMapConnectionHooks(hModule);
	SkillManagerHooks(hModule);
	SpawnManagerHooks(hModule);
	BattleManagerHooks(hModule);
	CBioticHooks(hModule);
	PetHooks(hModule);
	applyPortals(hModule);
	CPlayer::InitPlayerHooks(hModule);


/*
	if (applyPortals(hModule))
	{
		std::cout << "Hooking fail, quittting.." << std::endl;
		Sleep(100);
		ExitProcess(1);
	}
*/
	

}
BOOL APIENTRY DllMain(HMODULE _hModule,
	DWORD  ul_reason_for_call,
	LPVOID lpReserved
)
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
	{
		CreateConsole();
		hModule = _hModule;
		
		SetConsoleTitle(L"R.O.H.A.N. | Goddess Of Destruction");
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);

	
		CreateThread(0, 0, (LPTHREAD_START_ROUTINE)initAll, 0, 0, 0);
		std::cout << "Anti Hack loaded" << std::endl;
		std::cout << "Anti Crash loaded." << std::endl;
		Hooks::Hook((void*)0x004939C2, printHello, 8);
		

		break;
	}
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}

