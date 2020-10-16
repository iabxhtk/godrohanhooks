#include "stdafx.h"
#include "PortalManager.h"
#include "OldStlContainers.h"
void(__thiscall* PortalManager__RegistAllUniqueValue)(void * tThis) = (void(__thiscall*)(void * tThis))(0x006A1AE0);
void __fastcall dPortalManager__RegistAllUniqueValue(void* This, void* notUsed)
{
	PortalManager * portalMgr = (PortalManager *)This;

	oldstd::basic_string uniqueStr;

	/*
	uniqueStr.assign("PORTAL_GJ2F01");
	portalMgr->_RegistUniqueValue(&uniqueStr, 0x191);
	uniqueStr.assign("PORTAL_GJ2F02");
	portalMgr->_RegistUniqueValue(&uniqueStr, 0x192);
	uniqueStr.assign("PORTAL_GJ2F02");
	portalMgr->_RegistUniqueValue(&uniqueStr, 0x194);
	uniqueStr.assign("RANDOM_PORTAL_SurvivalArena");
	portalMgr->_RegistUniqueValue(&uniqueStr, 0x1A6);
	uniqueStr.assign("RANDOM_PORTAL_TRINITY_Tutorial");
	portalMgr->_RegistUniqueValue(&uniqueStr, 446);
	uniqueStr.assign("PORTAL_TRINITY_01");
	portalMgr->_RegistUniqueValue(&uniqueStr, 447);
	uniqueStr.assign("PORTAL_TRINITY_02");
	portalMgr->_RegistUniqueValue(&uniqueStr, 448);*/


	uniqueStr.assign("PORTAL_ENT_MIRROR_DUN_01");
	portalMgr->_RegistUniqueValue(&uniqueStr, 449);
	uniqueStr.assign("PORTAL_EXT_MIRROR_DUN_01");
	portalMgr->_RegistUniqueValue(&uniqueStr, 450);
	uniqueStr.assign("PORTAL_ENT_MIRROR_DUN_02_1");
	portalMgr->_RegistUniqueValue(&uniqueStr, 451);
	uniqueStr.assign("PORTAL_EXT_MIRROR_DUN_02_1");
	portalMgr->_RegistUniqueValue(&uniqueStr, 452);
	uniqueStr.assign("PORTAL_ENT_MIRROR_DUN_02_2");
	portalMgr->_RegistUniqueValue(&uniqueStr, 453);
	uniqueStr.assign("PORTAL_EXT_MIRROR_DUN_02_2");
	portalMgr->_RegistUniqueValue(&uniqueStr, 454);
	uniqueStr.assign("PORTAL_ENT_MIRROR_DUN_03_1");
	portalMgr->_RegistUniqueValue(&uniqueStr, 455);
	uniqueStr.assign("PORTAL_EXT_MIRROR_DUN_03_1");
	portalMgr->_RegistUniqueValue(&uniqueStr, 456);
	uniqueStr.assign("PORTAL_ENT_MIRROR_DUN_03_2");
	portalMgr->_RegistUniqueValue(&uniqueStr, 457);
	uniqueStr.assign("PORTAL_EXT_MIRROR_DUN_03_2");
	portalMgr->_RegistUniqueValue(&uniqueStr, 458);
	uniqueStr.assign("PORTAL_ENT_MIRROR_DUN_04");
	portalMgr->_RegistUniqueValue(&uniqueStr, 459);
	uniqueStr.assign("PORTAL_EXT_MIRROR_DUN_04");
	portalMgr->_RegistUniqueValue(&uniqueStr, 460);
	uniqueStr.assign("PORTAL_ENT_Phlox_01");
	portalMgr->_RegistUniqueValue(&uniqueStr, 461);
	uniqueStr.assign("PORTAL_ENT_Phlox_02");
	portalMgr->_RegistUniqueValue(&uniqueStr, 462);
	uniqueStr.assign("PORTAL_EXT_Phlox");
	portalMgr->_RegistUniqueValue(&uniqueStr, 463);
	uniqueStr.assign("PORTAL_EXT_Phlox_01");
	portalMgr->_RegistUniqueValue(&uniqueStr, 464);
	uniqueStr.assign("PORTAL_EXT_Phlox_01");
	portalMgr->_RegistUniqueValue(&uniqueStr, 465);
	





	PortalManager__RegistAllUniqueValue(This);
}
std::basic_string<char, std::char_traits<char>, std::allocator<char> >  v485;
char * upper = "PORTAL_GJ2F01";

std::basic_string<char, std::char_traits<char>, std::allocator<char> >  v486;
char * lower = "PORTAL_GJ2F02";

/*std::basic_string<char, std::char_traits<char>, std::allocator<char> >  v487;
char * MIRROR_DUN_01 = "PORTAL_ENT_MIRROR_DUN_01";*/




bool applyPortals(HMODULE hModule)
{
	DWORD hookAddress3 = 0x006A1B00;//0x0064DE40;
	//((void*)hookAddress3, registPortalValue, 7);
	DisableThreadLibraryCalls(hModule);
	DetourTransactionBegin();
	DetourUpdateThread(GetCurrentThread());
	DetourAttach(&(PVOID&)PortalManager__RegistAllUniqueValue, dPortalManager__RegistAllUniqueValue);
	DetourTransactionCommit();

	return true;
}