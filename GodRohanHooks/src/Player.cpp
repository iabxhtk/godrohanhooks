#include "stdafx.h"
#include "Player.h"
#include <chrono>
#include "timeAPI.h"
#include <iomanip>
#include "Hooks.h"
auto CEntityProcess__PlayerRemove = (void(__stdcall*)(CBiotic *pBiotic))(0x004E1580);
void __stdcall dCEntityProcess__PlayerRemove(CBiotic *pBiotic)
{

	CPlayer * player = (CPlayer *)Toolset::DynamicCast(pBiotic, 0, (void *)0x7E9608, (void *)0x7E9638, 0);
	if (player)
	{

		player->DeletePlayerExtension();

	//	std::cout << "Player log off " << ((CPlayer*)pBiotic)->GetName() << std::endl;
	}
	CEntityProcess__PlayerRemove(pBiotic);
}
auto CPlayer__GetEntityPlayerGR = (void(__thiscall*)(void * tThis, _tagGR_ENTITY_PLAYER * playerGR))(0x004FC090);
void __fastcall dCPlayer__GetEntityPlayerGR(void * This, void* notUsed, _tagGR_ENTITY_PLAYER * playerGR)
{
	CPlayer__GetEntityPlayerGR(This, playerGR);
	playerGR->nTitleID = -1;
}
auto CPlayer__InitChar = (void(__thiscall*)(void * tThis, void *pdbres))(0x004F0A40);
void __fastcall dCPlayer__InitChar(void * This, void* notUsed, void *pdbres)
{
	CPlayer__InitChar(This, pdbres);
	CPlayer * player = (CPlayer*)This;
	if (player)
	{
		PlayerExtensions * extsn = new PlayerExtensions(player);
		player->SetPlayerExtensions(extsn);
		if (extsn)
		{

			auto now = std::chrono::system_clock::now();
			auto now_c = std::chrono::system_clock::to_time_t(now);
			//std::cout << std::put_time(std::localtime(&now_c), "%c") << " Money :" << player->GetUserId() << " UserID " << player->GetUserId() << " Char ID: " << player->GetEpochId()->id << " " << player->GetName() << " has logged in, VIP: " << extsn->isVip << ".\n";
		}


	}
}
void CPlayer::ApplyHooks(HMODULE hModule)
{

	//Add 4 more bytes to CPlayer for extension pointer and lang info
	Hooks::PatchBytes((void*)0x004DCB54, 0x2058u + sizeof(PlayerExtensions *));

	DisableThreadLibraryCalls(hModule);
	DetourTransactionBegin();
	DetourUpdateThread(GetCurrentThread());
	DetourAttach(&(PVOID&)CPlayer__GetEntityPlayerGR, dCPlayer__GetEntityPlayerGR);
	DetourAttach(&(PVOID&)CEntityProcess__PlayerRemove, dCEntityProcess__PlayerRemove);
	DetourAttach(&(PVOID&)CPlayer__InitChar, dCPlayer__InitChar);
	DetourTransactionCommit();
}

