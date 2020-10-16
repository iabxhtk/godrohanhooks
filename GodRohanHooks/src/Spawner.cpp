#include "stdafx.h"
#include "Spawner.h"
#include <iostream>
#include "Structs.h"
#include "MapEnums.h"
#include "EntityManager.h"
#include "Monster.h"
#include "MonsterHostility.h"
#include "MonsterScript.h"
#include "CURLplusplus.h"

//auto ___RTDynamicCast1 = (char *(__cdecl*)(void *inptr, int VfDelta, void *SrcType, void *TargetType, int isReference))0x00753FAB;//(0x006F3BEB) 0x00753FAB



int(__thiscall* Monster__spawnProcess)(void * tThis, int nType, int nIRID, EpochVector3 *pos, EpochVector3 *angle, unsigned int dwGenID, int genpatrolindex, int nLinkIndex, void *pItem, void *parentID, unsigned int dwOwnerID) =
(int(__thiscall*)(void * tThis, int nType, int nIRID, EpochVector3 *pos, EpochVector3 *angle, unsigned int dwGenID, int genpatrolindex, int nLinkIndex, void *pItem, void *parentID, unsigned int dwOwnerID))(0x004DD910);
int __fastcall dMonster__spawnProcess(void * This, void* notUsed, int nType, int nIRID, EpochVector3 *pos, EpochVector3 *angle, unsigned int dwGenID, int genpatrolindex, int nLinkIndex, void *pItem, void *parentID, unsigned int dwOwnerID)
{
	//std::cout << pos->x << " " << pos->y << " " << pos->z << "\n";
	//std::cout << angle->x << " " << angle->y  << " " << angle->z << "\n";

	switch (nType)
	{


	case 295161:
	{

		CURLplusplus client;
		std::string url("http://51.195.142.240/worldboss.php?id=2&bid=1");
		string urlx = client.Get(url);

		//std::cout << nType << " " << pos->x << "\n";
		pos->x = 171689; pos->y = 6423.5; pos->z = 1153638;
		
		
		auto summontimer1 = (void *(__thiscall*)(void*, unsigned int timer))5071744;
		void * summon1 = summontimer1(This, 7200000);
	

		
		std::string messageString1("[Aquarias] : ");
		messageString1.append("Will burn Mangrove to ground!");
		Toolset::SendNoticeMessageAllPlayers(messageString1, GMMESSAGE_TYPE::NOTICE_TEXT);
		return Monster__spawnProcess(This, nType, nIRID, pos, angle, dwGenID, genpatrolindex, nLinkIndex, pItem, parentID, dwOwnerID);


	}




	case 295156:
	{

		CURLplusplus client;
		std::string url("http://51.195.142.240/worldboss.php?id=2&bid=1");
		string urlx = client.Get(url);

		//std::cout << nType << " " << pos->x << "\n";
		pos->x = 171689; pos->y = 6423.5; pos->z = 1153638;
	//	angle->x = 0; angle->y = 2; angle->z = 0;


		auto summontimer1 = (void* (__thiscall*)(void*, unsigned int timer))5071744;
		void* summon1 = summontimer1(This, 7200000);


			
		std::string messageString1("[Mirebreath Kniedhogg] : ");
		messageString1.append("Will burn Mangrove to ground!");
		Toolset::SendNoticeMessageAllPlayers(messageString1, GMMESSAGE_TYPE::NOTICE_TEXT);
		return Monster__spawnProcess(This, nType, nIRID, pos, angle, dwGenID, genpatrolindex, nLinkIndex, pItem, parentID, dwOwnerID);


	}


	case 295168:
	{

		CURLplusplus client;
		std::string url("http://51.195.142.240/worldboss.php?id=1&bid=1");
		string urlx = client.Get(url);




		//std::cout << nType << " " << pos->x << "\n";
		 pos->x = 582142; pos->y = 4326.6; pos->z = 122989;
	

		
		
		




		auto summontimer1 = (void* (__thiscall*)(void*, unsigned int timer))5071744;
		void* summon1 = summontimer1(This, 7200000);



		std::string messageString1("[Stratus] : ");
		messageString1.append("GH Is mine now Fuck off all!");
		Toolset::SendNoticeMessageAllPlayers(messageString1, GMMESSAGE_TYPE::NOTICE_TEXT);
		return Monster__spawnProcess(This, nType, nIRID, pos, angle, dwGenID, genpatrolindex, nLinkIndex, pItem, parentID, dwOwnerID);


	}


	case 274198:
	{

		std::string messageString1("[System] : ");
		messageString1.append("Mining Mk.II is Alive");
		Toolset::SendNoticeMessageAllPlayers(messageString1, GMMESSAGE_TYPE::NOTICE_TEXT);
		return Monster__spawnProcess(This, nType, nIRID, pos, angle, dwGenID, genpatrolindex, nLinkIndex, pItem, parentID, dwOwnerID);


	}
	case 274199:
	{

		std::string messageString1("[System] : ");
		messageString1.append("Tabasco is Alive");
		Toolset::SendNoticeMessageAllPlayers(messageString1, GMMESSAGE_TYPE::NOTICE_TEXT);
		return Monster__spawnProcess(This, nType, nIRID, pos, angle, dwGenID, genpatrolindex, nLinkIndex, pItem, parentID, dwOwnerID);
	}
	case 274200:
	{

		std::string messageString1("[System] : ");
		messageString1.append("Twisted Multidimensional Guardian is Alive");
		Toolset::SendNoticeMessageAllPlayers(messageString1, GMMESSAGE_TYPE::NOTICE_TEXT);
		return Monster__spawnProcess(This, nType, nIRID, pos, angle, dwGenID, genpatrolindex, nLinkIndex, pItem, parentID, dwOwnerID);


	}

	case 274201:
	{

		std::string messageString1("[System] : ");
		messageString1.append("Minotaur is Alive");
		Toolset::SendNoticeMessageAllPlayers(messageString1, GMMESSAGE_TYPE::NOTICE_TEXT);
		return Monster__spawnProcess(This, nType, nIRID, pos, angle, dwGenID, genpatrolindex, nLinkIndex, pItem, parentID, dwOwnerID);


	}
	case 274202:
	{

		std::string messageString1("[System] : ");
		messageString1.append("Bloody Murderer is Alive");
		Toolset::SendNoticeMessageAllPlayers(messageString1, GMMESSAGE_TYPE::NOTICE_TEXT);
		return Monster__spawnProcess(This, nType, nIRID, pos, angle, dwGenID, genpatrolindex, nLinkIndex, pItem, parentID, dwOwnerID);


	}

	case 274203:
	{

		std::string messageString1("[System] : ");
		messageString1.append("Lazy Dungeon Keeper is Alive");
		Toolset::SendNoticeMessageAllPlayers(messageString1, GMMESSAGE_TYPE::NOTICE_TEXT);
		return Monster__spawnProcess(This, nType, nIRID, pos, angle, dwGenID, genpatrolindex, nLinkIndex, pItem, parentID, dwOwnerID);


	}

	case 274204:
	{

		std::string messageString1("[System] : ");
		messageString1.append("Reggiebell is Alive");
		Toolset::SendNoticeMessageAllPlayers(messageString1, GMMESSAGE_TYPE::NOTICE_TEXT);
		return Monster__spawnProcess(This, nType, nIRID, pos, angle, dwGenID, genpatrolindex, nLinkIndex, pItem, parentID, dwOwnerID);

	}

	case 274205:
	{

		std::string messageString1("[System] : ");
		messageString1.append("Drawjeff Gnome is Alive");
		Toolset::SendNoticeMessageAllPlayers(messageString1, GMMESSAGE_TYPE::NOTICE_TEXT);
		return Monster__spawnProcess(This, nType, nIRID, pos, angle, dwGenID, genpatrolindex, nLinkIndex, pItem, parentID, dwOwnerID);

	}
	case 274206:
	{

		std::string messageString1("[System] : ");
		messageString1.append("Taclaus is Alive");
		Toolset::SendNoticeMessageAllPlayers(messageString1, GMMESSAGE_TYPE::NOTICE_TEXT);
		return Monster__spawnProcess(This, nType, nIRID, pos, angle, dwGenID, genpatrolindex, nLinkIndex, pItem, parentID, dwOwnerID);

	}

	case 274207:
	{

		std::string messageString1("[System] : ");
		messageString1.append("Aquamoss is Alive");
		Toolset::SendNoticeMessageAllPlayers(messageString1, GMMESSAGE_TYPE::NOTICE_TEXT);
		return Monster__spawnProcess(This, nType, nIRID, pos, angle, dwGenID, genpatrolindex, nLinkIndex, pItem, parentID, dwOwnerID);

	}

	case 274208:
	{

		std::string messageString1("[System] : ");
		messageString1.append("Accratheater is Alive");
		Toolset::SendNoticeMessageAllPlayers(messageString1, GMMESSAGE_TYPE::NOTICE_TEXT);
		return Monster__spawnProcess(This, nType, nIRID, pos, angle, dwGenID, genpatrolindex, nLinkIndex, pItem, parentID, dwOwnerID);

	}





	case 375705: {

	//auto CreateBiotic1 = (CBiotic *(__thiscall*)(void*, int nType, int nIRID, EpochVector3 *pos, void *Angle, unsigned int dwGenID, int genpatrolindex, int nLinkIndex, void *pItem, void *parentID, unsigned int dwOwnerID))0x004DD910;
	//CBiotic * biotic1 = CreateBiotic1((void*)0x007F8A58, 335708, 0, pos, (void*)0x04B827DC, 0, 0, 0, 0, 0, 0);
	

		auto summontimer1 = (void *(__thiscall*)(void*, unsigned int timer))5071744;
		void * summon1 = summontimer1(This, 1800000);


	pos->y = 11865.5;
	return Monster__spawnProcess(This, nType, nIRID, pos, angle, dwGenID, genpatrolindex, nLinkIndex, pItem, parentID, dwOwnerID);


	}

	
	

	default:
		return Monster__spawnProcess(This, nType, nIRID, pos, angle, dwGenID, genpatrolindex, nLinkIndex, pItem, parentID, dwOwnerID);
	}
	
}







void(__thiscall* Monster__DeadProcess)(void * tThis, unsigned unsigned int dwAttackerID) = (void(__thiscall*)(void * tThis, unsigned int dwAttackerID))(0x00585450);
void __fastcall dMonster__DeadProcess(void* This, void* notUsed, unsigned int dwAttackerID)
{


	Monster * monster = (Monster*)This;
	


	switch (monster->GetEpochId()->type)
	{


	

	case 295161:
	{

		CURLplusplus client;
		std::string url("http://51.195.142.240/worldboss.php?id=2&bid=2");
		string urlx = client.Get(url);

		std::string messageString1("[Aquarias] : ");
		messageString1.append(" i Will Back to revange you noobs soon");
		Toolset::SendNoticeMessageAllPlayers(messageString1, GMMESSAGE_TYPE::NOTICE_TEXT);



		auto summontimer1 = (void *(__thiscall*)(void*, unsigned int timer))5071744;
		void * summon1 = summontimer1(This, 0);

		return Monster__DeadProcess(This, dwAttackerID);
	}




	case 295156:
	{

		CURLplusplus client;
		std::string url("http://51.195.142.240/worldboss.php?id=2&bid=2");
		string urlx = client.Get(url);

		std::string messageString1("[Mirebreath Kniedhogg] : ");
		messageString1.append(" i Will Back to revange you noobs soon");
		Toolset::SendNoticeMessageAllPlayers(messageString1, GMMESSAGE_TYPE::NOTICE_TEXT);



		auto summontimer1 = (void* (__thiscall*)(void*, unsigned int timer))5071744;
		void* summon1 = summontimer1(This, 0);

		return Monster__DeadProcess(This, dwAttackerID);
	}
	


	case 295168:
	{

		CURLplusplus client;
		std::string url("http://51.195.142.240/worldboss.php?id=1&bid=2");
		string urlx = client.Get(url);

		std::string messageString1("[Stratus] : ");
		messageString1.append(" i Will Back to revange you noobs soon");
		Toolset::SendNoticeMessageAllPlayers(messageString1, GMMESSAGE_TYPE::NOTICE_TEXT);



		auto summontimer1 = (void* (__thiscall*)(void*, unsigned int timer))5071744;
		void* summon1 = summontimer1(This, 0);

		return Monster__DeadProcess(This, dwAttackerID);
	}


	case 274198:
	case 274199:
	case 274200:
	case 274201:
	case 274202:
	case 274203:
	case 274204:
	case 274205:
	case 274206:
	case 274207:
	case 274208:

	{

		CEntityManager * mgr = (CEntityManager*)0x007F8A60;
		CBiotic * player = mgr->FindBiotic(dwAttackerID);

		if (player) {
			std::string messageString1("[System] : ");
			messageString1 += monster->GetMonsterName();
			messageString1.append(" is Killed by ");
			messageString1 += player->GetName();
			
			Toolset::SendNoticeMessageAllPlayers(messageString1, GMMESSAGE_TYPE::NOTICE_TEXT);
			return Monster__DeadProcess(This, dwAttackerID);
		}
	}


	case 295156999:
	{
		CEntityManager * mgr = (CEntityManager*)0x007F8A60;
		CBiotic * player = mgr->FindBiotic(dwAttackerID);
		
		if (player) {
			std::string messageString1("[World Boss] : ");
			messageString1 += monster->GetMonsterName();
			messageString1.append(" is Killed by ");
			messageString1 += player->GetName();
			Toolset::SendNoticeMessageAllPlayers(messageString1, GMMESSAGE_TYPE::NOTICE_TEXT);

			CURLplusplus client;
			std::string url("http://51.195.142.240/worldboss.php?mintime=480&playername=");
			url.append(player->GetName());
			url.append("&id=1");
			string urlx = client.Get(url);


		//	auto CreateBiotic = (Biotic *(__thiscall*)(void*, int nType, int nIRID, EpochVector3 * pos, float anx, float any, float anz, unsigned int dwGenID, int genpatrolindex, int nLinkIndex, void *pItem, void *parentID, unsigned int dwOwnerID))5101840;//0x004C7D50;
			//Biotic * biotic = CreateBiotic((void*)0x007F8A58, 9562659, 0, player->GetPos ,2222,2222,2222, 0, 0, 0, 0, 0, 0);//(void*)0x04B827DC

			return Monster__DeadProcess(This, dwAttackerID);

		}
	}



	default:
		return Monster__DeadProcess(This, dwAttackerID);
	}

}


void SpawnManagerHooks(HMODULE hModule)
{

	DisableThreadLibraryCalls(hModule);
	DetourTransactionBegin();
	DetourUpdateThread(GetCurrentThread());
	DetourAttach(&(PVOID&)Monster__spawnProcess, dMonster__spawnProcess);
	DetourAttach(&(PVOID&)Monster__DeadProcess, dMonster__DeadProcess);
	DetourTransactionCommit();
}