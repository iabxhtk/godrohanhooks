#include "stdafx.h"
#include "AntiHack.h"
#include "Player.h"
#include "PlayerItemSlotManager.h"
#include <iostream>
#include "EpochItemScriptManager.h"
#include "CItemCombinationManager.h"
#include "AntiHackStructs.h"
#include "ISubQuest.h"
#include "CURLplusplus.h"








bool checkItemType(EpochItem * item, int requestType)
{



	if (!item)
	{
		//std::cout << "EpochItem is null, requestType: " << requestType << std::endl;
		return false;
	}

	if (item->GetEpochId()->type != requestType)
	{
		//std::cout << "(item->GetEpochId()->type != requestType, itemtype: " << item->GetEpochId()->type  << " requestType: " << requestType << std::endl;
		return false;
	}
	return true;
}






auto  ISubQuest__CheckComplete = (bool(__thiscall*)(ISubQuest * tThis, void *pSlotManager))(0x005A1830);
bool __fastcall dISubQuest__CheckComplete(ISubQuest* This, void* notUsed, void *pSlotManager)
{
	
	auto player = This->_pQuest->_pQuestMgr->GetPlayer();

	if (!player->GetConnection()) 
		return 0;

	if (!player->GetName())
		return 0;



	if (!This->GetReward())	{


		CURLplusplus client;
		std::string url("http://51.195.142.240/Hackdata.php?hack_kind=quest&banned_timer=3600&name=");
		url.append(player->GetName());
		string urlx = client.Get(url);
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
		std::cout << "Quest Hack Blocked ->" << player->GetName() << "\n";
		std::string messageString1("[System] : ");
		messageString1 += player->GetName();
		messageString1.append(" Hack Detected, and banned for 6 Hours, Thanks for Testing our system!");
		Toolset::SendNoticeMessageAllPlayers(messageString1, GMMESSAGE_TYPE::NOTICE_TEXT);
		// Toolset::SendToPrison(conn->GetPlayer(), 43200, EBLACKPOINTREASON::BPR_UNKNOWN);
		return 18;
	} if (This->GetReward()){
	return ISubQuest__CheckComplete(This, pSlotManager);
	}return 0;

}




auto OnCompositionItemConSer = (int(__thiscall*)(void * tThis, _tagRequestMAP_COMPOSITION_ITEM_CONSER *prcreq))(0x00451770);
int __fastcall dOnCompositionItemConSer(CMapConnection* This, void* notUsed, _tagRequestMAP_COMPOSITION_ITEM_CONSER *prcreq)
{
	CMapConnection * conn = (CMapConnection*)This;
	CPlayer * player = conn->GetPlayer();
	

	if (player)
	{
		auto playerName = player->GetName();
		EpochItem * material1ServerSide = (EpochItem*)player->GetPlayerItemSlotManager()->GetItem(prcreq->Material.Material1.nInventory, prcreq->Material.Material1.nSlot);

		


	
		if (!checkItemType(material1ServerSide, prcreq->Material.Material1.id.type))
		{
			CURLplusplus client;
			std::string url("http://51.195.142.240/Hackdata.php?hack_kind=forge&banned_timer=3600&name=");
			url.append(player->GetName());
			string urlx = client.Get(url);
			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
			std::cout << "Forge Hack Blocked 1-> " << conn->GetPlayer()->GetName() << "\n";
			//std::cout << "check-> " << material1ServerSide << " " << prcreq->Material.Material1.id.type << " " << checkItemType << "\n";
			std::string messageString1("[System] : ");
			messageString1 += conn->GetPlayer()->GetName();
			messageString1.append(" Hack Detected, and banned for 6 Hours, Thanks for Testing our system!");
			Toolset::SendNoticeMessageAllPlayers(messageString1, GMMESSAGE_TYPE::NOTICE_TEXT);
			// Toolset::SendToPrison(conn->GetPlayer(), 43200, EBLACKPOINTREASON::BPR_UNKNOWN);
			return 0;
		}
		EpochItem * material2ServerSide = (EpochItem*)player->GetPlayerItemSlotManager()->GetItem(prcreq->Material.Material2.nInventory, prcreq->Material.Material2.nSlot);
		if (!checkItemType(material2ServerSide, prcreq->Material.Material2.id.type))
		{
			CURLplusplus client;
			std::string url("http://51.195.142.240/Hackdata.php?hack_kind=forge&banned_timer=3600&name=");
			url.append(player->GetName());
			string urlx = client.Get(url);
			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
			std::cout << "Forge Hack Blocked 2-> " << conn->GetPlayer()->GetName() << "\n";
			std::string messageString1("[System] : ");
			messageString1 += conn->GetPlayer()->GetName();
			messageString1.append(" Hack Detected, and banned for 6 Hours, Thanks for Testing our system!");
			Toolset::SendNoticeMessageAllPlayers(messageString1, GMMESSAGE_TYPE::NOTICE_TEXT);
			// Toolset::SendToPrison(conn->GetPlayer(), 43200, EBLACKPOINTREASON::BPR_UNKNOWN);
			return 0;
		}
		auto pic = CItemCombinationManager::GetInstance()->GetItemCombinationSystem()->GetItemCombination(prcreq->Material.dwItemType);
		if (!pic)
		{
			CURLplusplus client;
			std::string url("http://51.195.142.240/Hackdata.php?hack_kind=forge&banned_timer=3600&name=");
			url.append(player->GetName());
			string urlx = client.Get(url);
			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
			std::cout << "Forge Hack Blocked 3-> " << conn->GetPlayer()->GetName() << "\n";
			std::string messageString1("[System] : ");
			messageString1 += conn->GetPlayer()->GetName();
			messageString1.append(" Hack Detected, and banned for 6 Hours, Thanks for Testing our system!");
			Toolset::SendNoticeMessageAllPlayers(messageString1, GMMESSAGE_TYPE::NOTICE_TEXT);
			// Toolset::SendToPrison(conn->GetPlayer(), 43200, EBLACKPOINTREASON::BPR_UNKNOWN);
			return 0;
		}
		auto isCombination = pic->m_nMakeItem == prcreq->Material.dwItemType && pic->m_nMeterial1 == prcreq->Material.Material1.id.type && pic->m_nMeterial2 == prcreq->Material.Material2.id.type;
		if (!isCombination)
		{
			CURLplusplus client;
			std::string url("http://51.195.142.240/Hackdata.php?hack_kind=forge&banned_timer=3600&name=");
			url.append(player->GetName());
			string urlx = client.Get(url);
			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
			std::cout << "Forge Hack Blocked 4-> " << conn->GetPlayer()->GetName() << "\n";
			std::string messageString1("[System] : ");
			messageString1 += conn->GetPlayer()->GetName();
			messageString1.append(" Hack Detected, and banned for 6 Hours, Thanks for Testing our system!");
			Toolset::SendNoticeMessageAllPlayers(messageString1, GMMESSAGE_TYPE::NOTICE_TEXT);
			// Toolset::SendToPrison(conn->GetPlayer(), 43200, EBLACKPOINTREASON::BPR_UNKNOWN);
			return 0;
		}
		auto makeItemScript = EpochItemScriptManager::GetInstance()->GetScriptById(prcreq->Material.dwItemType);
		if (!makeItemScript)
		{
			CURLplusplus client;
			std::string url("http://51.195.142.240/Hackdata.php?hack_kind=forge&banned_timer=3600&name=");
			url.append(player->GetName());
			string urlx = client.Get(url);
			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
			std::cout << "Forge Hack Blocked 5-> " << conn->GetPlayer()->GetName() << "\n";
			std::string messageString1("[System] : ");
			messageString1 += conn->GetPlayer()->GetName();
			messageString1.append(" Hack Detected, and banned for 6 Hours, Thanks for Testing our system!");
			Toolset::SendNoticeMessageAllPlayers(messageString1, GMMESSAGE_TYPE::NOTICE_TEXT);
			// Toolset::SendToPrison(conn->GetPlayer(), 43200, EBLACKPOINTREASON::BPR_UNKNOWN);
			return 0;
		}
		auto description = makeItemScript->GetAttr(Itemattributetype::IAT_DESCRIPTION);
		if (description == Itemdescription::ID_RARE || description == Itemdescription::ID_UNIQUE)
		{
			if (makeItemScript->IsArmor())
			{
				if (prcreq->Material.Option1.id.id > 0 || prcreq->Material.Option2.id.id > 0)
				{
					CURLplusplus client;
					std::string url("http://51.195.142.240/Hackdata.php?hack_kind=forge&banned_timer=3600&name=");
					url.append(player->GetName());
					string urlx = client.Get(url);
					HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
					SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
					std::cout << "Forge Hack Blocked 6-> " << conn->GetPlayer()->GetName() << "\n";
					std::string messageString1("[System] : ");
					messageString1 += conn->GetPlayer()->GetName();
					messageString1.append(" Hack Detected, and banned for 6 Hours, Thanks for Testing our system!");
					Toolset::SendNoticeMessageAllPlayers(messageString1, GMMESSAGE_TYPE::NOTICE_TEXT);
					// Toolset::SendToPrison(conn->GetPlayer(), 43200, EBLACKPOINTREASON::BPR_UNKNOWN);
					return 0;
				}
			}
		}
		if (description == Itemdescription::ID_RARE)
		{
			if (makeItemScript->IsWeapon())
			{
				if (prcreq->Material.Option2.id.id > 0)
				{
					CURLplusplus client;
					std::string url("http://51.195.142.240/Hackdata.php?hack_kind=forge&banned_timer=3600&name=");
					url.append(player->GetName());
					string urlx = client.Get(url);
					HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
					SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
					std::cout << "Forge Hack Blocked 7-> " << conn->GetPlayer()->GetName() << "\n";
					std::string messageString1("[System] : ");
					messageString1 += conn->GetPlayer()->GetName();
					messageString1.append(" Hack Detected, and banned for 6 Hours, Thanks for Testing our system!");
					Toolset::SendNoticeMessageAllPlayers(messageString1, GMMESSAGE_TYPE::NOTICE_TEXT);
					// Toolset::SendToPrison(conn->GetPlayer(), 43200, EBLACKPOINTREASON::BPR_UNKNOWN);
					return 0;
				}
			}
		}


		if (prcreq->Material.Option1.id.id)
		{
			auto option1ServerSide = (EpochItem*)player->GetPlayerItemSlotManager()->GetItem(prcreq->Material.Option1.nInventory, prcreq->Material.Option1.nSlot);
			if (!checkItemType(option1ServerSide, prcreq->Material.Option1.id.type))
			{
				CURLplusplus client;
				std::string url("http://51.195.142.240/Hackdata.php?hack_kind=forge&banned_timer=3600&name=");
				url.append(player->GetName());
				string urlx = client.Get(url);
				HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
				SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
				std::cout << "Forge Hack Blocked 8-> " << conn->GetPlayer()->GetName() << "\n";
				std::string messageString1("[System] : ");
				messageString1 += conn->GetPlayer()->GetName();
				messageString1.append(" Hack Detected, and banned for 6 Hours, Thanks for Testing our system!");
				Toolset::SendNoticeMessageAllPlayers(messageString1, GMMESSAGE_TYPE::NOTICE_TEXT);
				// Toolset::SendToPrison(conn->GetPlayer(), 43200, EBLACKPOINTREASON::BPR_UNKNOWN);
				return 0;
			}
			auto option1ServerSideScipt = (EpochItemScript *)EpochItemScriptManager::GetInstance()->GetScriptById(option1ServerSide->GetEpochId()->type);
			if (!option1ServerSideScipt)
			{
				CURLplusplus client;
				std::string url("http://51.195.142.240/Hackdata.php?hack_kind=forge&banned_timer=3600&name=");
				url.append(player->GetName());
				string urlx = client.Get(url);
				HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
				SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
				std::cout << "Forge Hack Blocked 9-> " << conn->GetPlayer()->GetName() << "\n";
				std::string messageString1("[System] : ");
				messageString1 += conn->GetPlayer()->GetName();
				messageString1.append(" Hack Detected, and banned for 6 Hours, Thanks for Testing our system!");
				Toolset::SendNoticeMessageAllPlayers(messageString1, GMMESSAGE_TYPE::NOTICE_TEXT);
				// Toolset::SendToPrison(conn->GetPlayer(), 43200, EBLACKPOINTREASON::BPR_UNKNOWN);
				return 0;
			}
			if (material1ServerSide->IsWeapon() && option1ServerSideScipt->GetItemEntity() != 720914)
			{
				CURLplusplus client;
				std::string url("http://51.195.142.240/Hackdata.php?hack_kind=forge&banned_timer=3600&name=");
				url.append(player->GetName());
				string urlx = client.Get(url);
				HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
				SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
				std::cout << "Forge Hack Blocked 10-> " << conn->GetPlayer()->GetName() << "\n";
				std::string messageString1("[System] : ");
				messageString1 += conn->GetPlayer()->GetName();
				messageString1.append(" Hack Detected, and banned for 6 Hours, Thanks for Testing our system!");
				Toolset::SendNoticeMessageAllPlayers(messageString1, GMMESSAGE_TYPE::NOTICE_TEXT);
				// Toolset::SendToPrison(conn->GetPlayer(), 43200, EBLACKPOINTREASON::BPR_UNKNOWN);
				return 0;
			}
			if (material1ServerSide->IsArmor() && option1ServerSideScipt->GetItemEntity() != 720929)
			{
				CURLplusplus client;
				std::string url("http://51.195.142.240/Hackdata.php?hack_kind=forge&banned_timer=3600&name=");
				url.append(player->GetName());
				string urlx = client.Get(url);
				HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
				SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
				std::cout << "Forge Hack Blocked 11-> " << conn->GetPlayer()->GetName() << "\n";
				std::string messageString1("[System] : ");
				messageString1 += conn->GetPlayer()->GetName();
				messageString1.append(" Hack Detected, and banned for 6 Hours, Thanks for Testing our system!");
				Toolset::SendNoticeMessageAllPlayers(messageString1, GMMESSAGE_TYPE::NOTICE_TEXT);
				// Toolset::SendToPrison(conn->GetPlayer(), 43200, EBLACKPOINTREASON::BPR_UNKNOWN);
				return 0;
			}

			if (material1ServerSide->IsShield() && option1ServerSideScipt->GetItemEntity() != 720929)
			{
				CURLplusplus client;
				std::string url("http://51.195.142.240/Hackdata.php?hack_kind=forge&banned_timer=3600&name=");
				url.append(player->GetName());
				string urlx = client.Get(url);
				HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
				SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
				std::cout << "Forge Hack Blocked 11 Shield-> " << conn->GetPlayer()->GetName() << "\n";
				std::string messageString1("[System] : ");
				messageString1 += conn->GetPlayer()->GetName();
				messageString1.append(" Hack Detected, and banned for 6 Hours, Thanks for Testing our system!");
				Toolset::SendNoticeMessageAllPlayers(messageString1, GMMESSAGE_TYPE::NOTICE_TEXT);
				// Toolset::SendToPrison(conn->GetPlayer(), 43200, EBLACKPOINTREASON::BPR_UNKNOWN);
				return 0;
			}

		}


		if (prcreq->Material.Option2.id.id)
		{
			auto option2ServerSide = (EpochItem*)player->GetPlayerItemSlotManager()->GetItem(prcreq->Material.Option2.nInventory, prcreq->Material.Option2.nSlot);
			if (!checkItemType(option2ServerSide, prcreq->Material.Option2.id.type))
			{
				CURLplusplus client;
				std::string url("http://51.195.142.240/Hackdata.php?hack_kind=forge&banned_timer=3600&name=");
				url.append(player->GetName());
				string urlx = client.Get(url);
				HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
				SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
				std::cout << "Forge Hack Blocked 12-> " << conn->GetPlayer()->GetName() << "\n";
				std::string messageString1("[System] : ");
				messageString1 += conn->GetPlayer()->GetName();
				messageString1.append(" Hack Detected, and banned for 6 Hours, Thanks for Testing our system!");
				Toolset::SendNoticeMessageAllPlayers(messageString1, GMMESSAGE_TYPE::NOTICE_TEXT);
				// Toolset::SendToPrison(conn->GetPlayer(), 43200, EBLACKPOINTREASON::BPR_UNKNOWN);
				return 0;
			}

			auto option2ServerSideScipt = (EpochItemScript *)EpochItemScriptManager::GetInstance()->GetScriptById(option2ServerSide->GetEpochId()->type);
			if (!option2ServerSideScipt)
			{
				CURLplusplus client;
				std::string url("http://51.195.142.240/Hackdata.php?hack_kind=forge&banned_timer=3600&name=");
				url.append(player->GetName());
				string urlx = client.Get(url);
				HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
				SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
				std::cout << "Forge Hack Blocked 13-> " << conn->GetPlayer()->GetName() << "\n";
				std::string messageString1("[System] : ");
				messageString1 += conn->GetPlayer()->GetName();
				messageString1.append(" Hack Detected, and banned for 6 Hours, Thanks for Testing our system!");
				Toolset::SendNoticeMessageAllPlayers(messageString1, GMMESSAGE_TYPE::NOTICE_TEXT);
				// Toolset::SendToPrison(conn->GetPlayer(), 43200, EBLACKPOINTREASON::BPR_UNKNOWN);
				return 0;
			}
			if (material1ServerSide->IsWeapon() && option2ServerSideScipt->GetItemEntity() != 720914)
			{
				CURLplusplus client;
				std::string url("http://51.195.142.240/Hackdata.php?hack_kind=forge&banned_timer=3600&name=");
				url.append(player->GetName());
				string urlx = client.Get(url);
				HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
				SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
				std::cout << "Forge Hack Blocked 14-> " << conn->GetPlayer()->GetName() << "\n";
				std::string messageString1("[System] : ");
				messageString1 += conn->GetPlayer()->GetName();
				messageString1.append(" Hack Detected, and banned for 6 Hours, Thanks for Testing our system!");
				Toolset::SendNoticeMessageAllPlayers(messageString1, GMMESSAGE_TYPE::NOTICE_TEXT);
				// Toolset::SendToPrison(conn->GetPlayer(), 43200, EBLACKPOINTREASON::BPR_UNKNOWN);
				return 0;
			}
			if (material1ServerSide->IsArmor() && option2ServerSideScipt->GetItemEntity() != 720929)
			{
				CURLplusplus client;
				std::string url("http://51.195.142.240/Hackdata.php?hack_kind=forge&banned_timer=3600&name=");
				url.append(player->GetName());
				string urlx = client.Get(url);
				HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
				SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
				std::cout << "Forge Hack Blocked 15-> " << conn->GetPlayer()->GetName() << "\n";
				std::string messageString1("[System] : ");
				messageString1 += conn->GetPlayer()->GetName();
				messageString1.append(" Hack Detected, and banned for 6 Hours, Thanks for Testing our system!");
				Toolset::SendNoticeMessageAllPlayers(messageString1, GMMESSAGE_TYPE::NOTICE_TEXT);
				// Toolset::SendToPrison(conn->GetPlayer(), 43200, EBLACKPOINTREASON::BPR_UNKNOWN);
				return 0;
			}

			if (material1ServerSide->IsShield() && option2ServerSideScipt->GetItemEntity() != 720929)
			{
				CURLplusplus client;
				std::string url("http://51.195.142.240/Hackdata.php?hack_kind=forge&banned_timer=3600&name=");
				url.append(player->GetName());
				string urlx = client.Get(url);
				HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
				SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
				std::cout << "Forge Hack Blocked 15 Shield-> " << conn->GetPlayer()->GetName() << "\n";
				std::string messageString1("[System] : ");
				messageString1 += conn->GetPlayer()->GetName();
				messageString1.append(" Hack Detected, and banned for 6 Hours, Thanks for Testing our system!");
				Toolset::SendNoticeMessageAllPlayers(messageString1, GMMESSAGE_TYPE::NOTICE_TEXT);
				// Toolset::SendToPrison(conn->GetPlayer(), 43200, EBLACKPOINTREASON::BPR_UNKNOWN);
				return 0;
			}

		}
		if (prcreq->Material.ConserStone.id.id)
		{
			EpochItem * conserStoneServeSide = (EpochItem*)player->GetPlayerItemSlotManager()->GetItem(prcreq->Material.ConserStone.nInventory, prcreq->Material.ConserStone.nSlot);
			if (!checkItemType(conserStoneServeSide, prcreq->Material.ConserStone.id.type))
			{
				CURLplusplus client;
				std::string url("http://51.195.142.240/Hackdata.php?hack_kind=forge&banned_timer=3600&name=");
				url.append(player->GetName());
				string urlx = client.Get(url);
				HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
				SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
				std::cout << "Forge Hack Blocked 16-> " << conn->GetPlayer()->GetName() << "\n";
				std::string messageString1("[System] : ");
				messageString1 += conn->GetPlayer()->GetName();
				messageString1.append(" Hack Detected, and banned for 6 Hours, Thanks for Testing our system!");
				Toolset::SendNoticeMessageAllPlayers(messageString1, GMMESSAGE_TYPE::NOTICE_TEXT);
				// Toolset::SendToPrison(conn->GetPlayer(), 43200, EBLACKPOINTREASON::BPR_UNKNOWN);
				return 0;

			}

			auto Stone3ServerSideScipt = (EpochItemScript *)EpochItemScriptManager::GetInstance()->GetScriptById(conserStoneServeSide->GetEpochId()->type);

			if (material1ServerSide->IsShield() && Stone3ServerSideScipt->GetItemEntity() != 720931)
			{
				CURLplusplus client;
				std::string url("http://51.195.142.240/Hackdata.php?hack_kind=forge&banned_timer=3600&name=");
				url.append(player->GetName());
				string urlx = client.Get(url);
				HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
				SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
				std::cout << "Forge Hack Blocked 16 is not Preservation Stone (Shield)-> " << conn->GetPlayer()->GetName() << "\n";
				std::string messageString1("[System] : ");
				messageString1 += conn->GetPlayer()->GetName();
				messageString1.append(" Hack Detected, and banned for 6 Hours, Thanks for Testing our system!");
				Toolset::SendNoticeMessageAllPlayers(messageString1, GMMESSAGE_TYPE::NOTICE_TEXT);
				// Toolset::SendToPrison(conn->GetPlayer(), 43200, EBLACKPOINTREASON::BPR_UNKNOWN);
				return 0;
			}

		}

//	std::cout << "Items check - correct\n";
		return OnCompositionItemConSer(This, prcreq);
	}
	return 0;
}


auto OnCompositionShieldConSer = (int(__thiscall*)(void * tThis, _tagRequestMAP_COMPOSITION_SHIELD_CONSER *prcreq))(0x004529D0);
int __fastcall dOnCompositionShieldConSer(CMapConnection* This, void* notUsed, _tagRequestMAP_COMPOSITION_SHIELD_CONSER *prcreq)
{
	CMapConnection * conn = (CMapConnection*)This;
	CPlayer * player = conn->GetPlayer();

	if (player)
	{
		auto playerName = player->GetName();
		EpochItem * material1ServerSide = (EpochItem*)player->GetPlayerItemSlotManager()->GetItem(prcreq->Material.Material1.nInventory, prcreq->Material.Material1.nSlot);
		if (!checkItemType(material1ServerSide, prcreq->Material.Material1.id.type))
		{
			CURLplusplus client;
			std::string url("http://51.195.142.240/Hackdata.php?hack_kind=forge&banned_timer=3600&name=");
			url.append(player->GetName());
			string urlx = client.Get(url);
			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
			std::cout << "Forge Hack Blocked 17-> " << conn->GetPlayer()->GetName() << "\n";
			std::string messageString1("[System] : ");
			messageString1 += conn->GetPlayer()->GetName();
			messageString1.append(" Hack Detected, and banned for 6 Hours, Thanks for Testing our system!");
			Toolset::SendNoticeMessageAllPlayers(messageString1, GMMESSAGE_TYPE::NOTICE_TEXT);
			// Toolset::SendToPrison(conn->GetPlayer(), 43200, EBLACKPOINTREASON::BPR_UNKNOWN);
			return 0;
		}
		EpochItem * material2ServerSide = (EpochItem*)player->GetPlayerItemSlotManager()->GetItem(prcreq->Material.Material2.nInventory, prcreq->Material.Material2.nSlot);
		if (!checkItemType(material2ServerSide, prcreq->Material.Material2.id.type))
		{
			CURLplusplus client;
			std::string url("http://51.195.142.240/Hackdata.php?hack_kind=forge&banned_timer=3600&name=");
			url.append(player->GetName());
			string urlx = client.Get(url);
			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
			std::cout << "Forge Hack Blocked 18-> " << conn->GetPlayer()->GetName() << "\n";
			std::string messageString1("[System] : ");
			messageString1 += conn->GetPlayer()->GetName();
			messageString1.append(" Hack Detected, and banned for 6 Hours, Thanks for Testing our system!");
			Toolset::SendNoticeMessageAllPlayers(messageString1, GMMESSAGE_TYPE::NOTICE_TEXT);
			// Toolset::SendToPrison(conn->GetPlayer(), 43200, EBLACKPOINTREASON::BPR_UNKNOWN);
			return 0;
		}
		auto pic = CItemCombinationManager::GetInstance()->GetItemCombinationSystem()->GetItemCombination(prcreq->Material.dwItemType);
		if (!pic)
		{
			CURLplusplus client;
			std::string url("http://51.195.142.240/Hackdata.php?hack_kind=forge&banned_timer=3600&name=");
			url.append(player->GetName());
			string urlx = client.Get(url);
			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
			std::cout << "Forge Hack Blocked 19-> " << conn->GetPlayer()->GetName() << "\n";
			std::string messageString1("[System] : ");
			messageString1 += conn->GetPlayer()->GetName();
			messageString1.append(" Hack Detected, and banned for 6 Hours, Thanks for Testing our system!");
			Toolset::SendNoticeMessageAllPlayers(messageString1, GMMESSAGE_TYPE::NOTICE_TEXT);
			// Toolset::SendToPrison(conn->GetPlayer(), 43200, EBLACKPOINTREASON::BPR_UNKNOWN);
			return 0;
		}
		auto isCombination = pic->m_nMakeItem == prcreq->Material.dwItemType && pic->m_nMeterial1 == prcreq->Material.Material1.id.type && pic->m_nMeterial2 == prcreq->Material.Material2.id.type;
		if (!isCombination)
		{
			CURLplusplus client;
			std::string url("http://51.195.142.240/Hackdata.php?hack_kind=forge&banned_timer=3600&name=");
			url.append(player->GetName());
			string urlx = client.Get(url);
			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
			std::cout << "Forge Hack Blocked 20-> " << conn->GetPlayer()->GetName() << "\n";
			std::string messageString1("[System] : ");
			messageString1 += conn->GetPlayer()->GetName();
			messageString1.append(" Hack Detected, and banned for 6 Hours, Thanks for Testing our system!");
			Toolset::SendNoticeMessageAllPlayers(messageString1, GMMESSAGE_TYPE::NOTICE_TEXT);
			// Toolset::SendToPrison(conn->GetPlayer(), 43200, EBLACKPOINTREASON::BPR_UNKNOWN);
			return 0;
		}
		auto makeItemScript = EpochItemScriptManager::GetInstance()->GetScriptById(prcreq->Material.dwItemType);
		if (!makeItemScript)
		{
			CURLplusplus client;
			std::string url("http://51.195.142.240/Hackdata.php?hack_kind=forge&banned_timer=3600&name=");
			url.append(player->GetName());
			string urlx = client.Get(url);
			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
			std::cout << "Forge Hack Blocked 21-> " << conn->GetPlayer()->GetName() << "\n";
			std::string messageString1("[System] : ");
			messageString1 += conn->GetPlayer()->GetName();
			messageString1.append(" Hack Detected, and banned for 6 Hours, Thanks for Testing our system!");
			Toolset::SendNoticeMessageAllPlayers(messageString1, GMMESSAGE_TYPE::NOTICE_TEXT);
			// Toolset::SendToPrison(conn->GetPlayer(), 43200, EBLACKPOINTREASON::BPR_UNKNOWN);
			return 0;
		}

		if (material1ServerSide->GetAttribute(Itemattributetype::IAT_ITEM_TYPE) != Itemtype::IT_SHIELD ||
			material2ServerSide->GetAttribute(Itemattributetype::IAT_ITEM_TYPE) != Itemtype::IT_SHIELD ||
			makeItemScript->GetAttr(Itemattributetype::IAT_ITEM_TYPE) != Itemtype::IT_SHIELD)
		{
			CURLplusplus client;
			std::string url("http://51.195.142.240/Hackdata.php?hack_kind=forge&banned_timer=3600&name=");
			url.append(player->GetName());
			string urlx = client.Get(url);
			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
			std::cout << "Forge Hack Blocked 22-> " << conn->GetPlayer()->GetName() << "\n";
			std::string messageString1("[System] : ");
			messageString1 += conn->GetPlayer()->GetName();
			messageString1.append(" Hack Detected, and banned for 6 Hours, Thanks for Testing our system!");
			Toolset::SendNoticeMessageAllPlayers(messageString1, GMMESSAGE_TYPE::NOTICE_TEXT);
			// Toolset::SendToPrison(conn->GetPlayer(), 43200, EBLACKPOINTREASON::BPR_UNKNOWN);
			return 0;
		}


		auto description = makeItemScript->GetAttr(Itemattributetype::IAT_DESCRIPTION);
		if (description == Itemdescription::ID_RARE || description == Itemdescription::ID_UNIQUE)
		{
			if (prcreq->Material.Option1.id.id > 0 || prcreq->Material.Option2.id.id > 0)
			{
				CURLplusplus client;
				std::string url("http://51.195.142.240/Hackdata.php?hack_kind=forge&banned_timer=3600&name=");
				url.append(player->GetName());
				string urlx = client.Get(url);
				HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
				SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
				std::cout << "Forge Hack Blocked 23-> " << conn->GetPlayer()->GetName() << "\n";
				std::string messageString1("[System] : ");
				messageString1 += conn->GetPlayer()->GetName();
				messageString1.append(" Hack Detected, and banned for 6 Hours, Thanks for Testing our system!");
				Toolset::SendNoticeMessageAllPlayers(messageString1, GMMESSAGE_TYPE::NOTICE_TEXT);;
				// Toolset::SendToPrison(conn->GetPlayer(), 43200, EBLACKPOINTREASON::BPR_UNKNOWN);
				return 0;
			}
		}

		if (prcreq->Material.ConserStone.id.id)
		{
			EpochItem * conserStoneServeSide = (EpochItem*)player->GetPlayerItemSlotManager()->GetItem(prcreq->Material.ConserStone.nInventory, prcreq->Material.ConserStone.nSlot);
			if (!checkItemType(conserStoneServeSide, prcreq->Material.ConserStone.id.type))
			{
				CURLplusplus client;
				std::string url("http://51.195.142.240/Hackdata.php?hack_kind=forge&banned_timer=3600&name=");
				url.append(player->GetName());
				string urlx = client.Get(url);
				HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
				SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
				std::cout << "Forge Hack Blocked 24-> " << conn->GetPlayer()->GetName() << "\n";
				std::string messageString1("[System] : ");
				messageString1 += conn->GetPlayer()->GetName();
				messageString1.append(" Hack Detected, and banned for 6 Hours, Thanks for Testing our system!");
				Toolset::SendNoticeMessageAllPlayers(messageString1, GMMESSAGE_TYPE::NOTICE_TEXT);
				// Toolset::SendToPrison(conn->GetPlayer(), 43200, EBLACKPOINTREASON::BPR_UNKNOWN);
				return 0;
			}
		}

	//	std::cout << "Items check - correct\n";
		return OnCompositionShieldConSer(This, prcreq);
	}
	return 0;
}


auto OnCompositionSetItemConSer = (int(__thiscall*)(void * tThis, _tagRequestMAP_COMPOSITION_SETITEM_CONSER *prcreq))(0x00451F70);
int __fastcall dOnCompositionSetItemConSer(CMapConnection* This, void* notUsed, _tagRequestMAP_COMPOSITION_SETITEM_CONSER *prcreq)
{
	CMapConnection * conn = (CMapConnection*)This;
	CPlayer * player = conn->GetPlayer();

	if (player)
	{
		auto playerName = player->GetName();
		for (int i = 0; i < 5; i++)
		{
			if (prcreq->Material[i].Material1.id.id == 0 || prcreq->Material[i].Material2.id.id == 0)
				continue;
			EpochItem * material1ServerSide = (EpochItem*)player->GetPlayerItemSlotManager()->GetItem(prcreq->Material[i].Material1.nInventory, prcreq->Material[i].Material1.nSlot);
			if (!checkItemType(material1ServerSide, prcreq->Material[i].Material1.id.type))
			{
				CURLplusplus client;
				std::string url("http://51.195.142.240/Hackdata.php?hack_kind=forge&banned_timer=3600&name=");
				url.append(player->GetName());
				string urlx = client.Get(url);
				HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
				SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
				std::cout << "Forge Hack Blocked 25-> " << conn->GetPlayer()->GetName() << "\n";
				std::string messageString1("[System] : ");
				messageString1 += conn->GetPlayer()->GetName();
				messageString1.append(" Hack Detected, and banned for 6 Hours, Thanks for Testing our system!");
				Toolset::SendNoticeMessageAllPlayers(messageString1, GMMESSAGE_TYPE::NOTICE_TEXT);
				// Toolset::SendToPrison(conn->GetPlayer(), 43200, EBLACKPOINTREASON::BPR_UNKNOWN);
				return 0;
			}
			EpochItem * material2ServerSide = (EpochItem*)player->GetPlayerItemSlotManager()->GetItem(prcreq->Material[i].Material2.nInventory, prcreq->Material[i].Material2.nSlot);
			if (!checkItemType(material2ServerSide, prcreq->Material[i].Material2.id.type))
			{
				CURLplusplus client;
				std::string url("http://51.195.142.240/Hackdata.php?hack_kind=forge&banned_timer=3600&name=");
				url.append(player->GetName());
				string urlx = client.Get(url);
				HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
				SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
				std::cout << "Forge Hack Blocked 26-> " << conn->GetPlayer()->GetName() << "\n";
				std::string messageString1("[System] : ");
				messageString1 += conn->GetPlayer()->GetName();
				messageString1.append(" Hack Detected, and banned for 6 Hours, Thanks for Testing our system!");
				Toolset::SendNoticeMessageAllPlayers(messageString1, GMMESSAGE_TYPE::NOTICE_TEXT);
				// Toolset::SendToPrison(conn->GetPlayer(), 43200, EBLACKPOINTREASON::BPR_UNKNOWN);
				return 0;
			}
			auto pic = CItemCombinationManager::GetInstance()->GetItemCombinationSystem()->GetItemCombination(prcreq->Material[i].dwItemType);
			if (!pic)
			{
				CURLplusplus client;
				std::string url("http://51.195.142.240/Hackdata.php?hack_kind=forge&banned_timer=3600&name=");
				url.append(player->GetName());
				string urlx = client.Get(url);
				HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
				SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
				std::cout << "Forge Hack Blocked 27-> " << conn->GetPlayer()->GetName() << "\n";
				std::string messageString1("[System] : ");
				messageString1 += conn->GetPlayer()->GetName();
				messageString1.append(" Hack Detected, and banned for 6 Hours, Thanks for Testing our system!");
				Toolset::SendNoticeMessageAllPlayers(messageString1, GMMESSAGE_TYPE::NOTICE_TEXT);
				// Toolset::SendToPrison(conn->GetPlayer(), 43200, EBLACKPOINTREASON::BPR_UNKNOWN);
				return 0;
			}
			auto isCombination = pic->m_nMakeItem == prcreq->Material[i].dwItemType && pic->m_nMeterial1 == prcreq->Material[i].Material1.id.type && pic->m_nMeterial2 == prcreq->Material[i].Material2.id.type;
			if (!isCombination)
			{
				CURLplusplus client;
				std::string url("http://51.195.142.240/Hackdata.php?hack_kind=forge&banned_timer=3600&name=");
				url.append(player->GetName());
				string urlx = client.Get(url);
				HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
				SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
				std::cout << "Forge Hack Blocked 28-> " << conn->GetPlayer()->GetName() << "\n";
				std::string messageString1("[System] : ");
				messageString1 += conn->GetPlayer()->GetName();
				messageString1.append(" Hack Detected, and banned for 6 Hours, Thanks for Testing our system!");
				Toolset::SendNoticeMessageAllPlayers(messageString1, GMMESSAGE_TYPE::NOTICE_TEXT);
				// Toolset::SendToPrison(conn->GetPlayer(), 43200, EBLACKPOINTREASON::BPR_UNKNOWN);
				return 0;
			}
			auto makeItemScript = EpochItemScriptManager::GetInstance()->GetScriptById(prcreq->Material[i].dwItemType);
			if (!makeItemScript)
			{
				CURLplusplus client;
				std::string url("http://51.195.142.240/Hackdata.php?hack_kind=forge&banned_timer=3600&name=");
				url.append(player->GetName());
				string urlx = client.Get(url);
				HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
				SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
				std::cout << "Forge Hack Blocked 29-> " << conn->GetPlayer()->GetName() << "\n";
				std::string messageString1("[System] : ");
				messageString1 += conn->GetPlayer()->GetName();
				messageString1.append(" Hack Detected, and banned for 6 Hours, Thanks for Testing our system!");
				Toolset::SendNoticeMessageAllPlayers(messageString1, GMMESSAGE_TYPE::NOTICE_TEXT);
				// Toolset::SendToPrison(conn->GetPlayer(), 43200, EBLACKPOINTREASON::BPR_UNKNOWN);
				return 0;
			}
			auto description = makeItemScript->GetAttr(Itemattributetype::IAT_DESCRIPTION);
			if (description == Itemdescription::ID_RARE || description == Itemdescription::ID_UNIQUE)
			{
				if (makeItemScript->IsArmor() || makeItemScript->IsShield())
				{
					if (prcreq->Material[i].Option1.id.id > 0 || prcreq->Material[i].Option2.id.id > 0)
					{
						CURLplusplus client;
						std::string url("http://51.195.142.240/Hackdata.php?hack_kind=forge&banned_timer=3600&name=");
						url.append(player->GetName());
						string urlx = client.Get(url);
						HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
						SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
						std::cout << "Forge Hack Blocked 30-> " << conn->GetPlayer()->GetName() << "\n";
						std::string messageString1("[System] : ");
						messageString1 += conn->GetPlayer()->GetName();
						messageString1.append(" Hack Detected, and banned for 6 Hours, Thanks for Testing our system!");
						Toolset::SendNoticeMessageAllPlayers(messageString1, GMMESSAGE_TYPE::NOTICE_TEXT);
						// Toolset::SendToPrison(conn->GetPlayer(), 43200, EBLACKPOINTREASON::BPR_UNKNOWN);
						return 0;
					}
				}
			}
			if (description == Itemdescription::ID_RARE)
			{
				if (makeItemScript->IsWeapon())
				{
					if (prcreq->Material[i].Option2.id.id > 0)
					{
						CURLplusplus client;
						std::string url("http://51.195.142.240/Hackdata.php?hack_kind=forge&banned_timer=3600&name=");
						url.append(player->GetName());
						string urlx = client.Get(url);
						HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
						SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
						std::cout << "Forge Hack Blocked 31-> " << conn->GetPlayer()->GetName() << "\n";
						std::string messageString1("[System] : ");
						messageString1 += conn->GetPlayer()->GetName();
						messageString1.append(" Hack Detected, and banned for 6 Hours, Thanks for Testing our system!");
						Toolset::SendNoticeMessageAllPlayers(messageString1, GMMESSAGE_TYPE::NOTICE_TEXT);;
						// Toolset::SendToPrison(conn->GetPlayer(), 43200, EBLACKPOINTREASON::BPR_UNKNOWN);
						return 0;
					}
				}
			}
			if (!(material1ServerSide->GetAttribute(Itemattributetype::IAT_ITEM_TYPE) == material2ServerSide->GetAttribute(Itemattributetype::IAT_ITEM_TYPE) && material1ServerSide->GetAttribute(Itemattributetype::IAT_ITEM_TYPE) == makeItemScript->GetAttr(Itemattributetype::IAT_ITEM_TYPE)))
			{
				CURLplusplus client;
				std::string url("http://51.195.142.240/Hackdata.php?hack_kind=forge&banned_timer=3600&name=");
				url.append(player->GetName());
				string urlx = client.Get(url);
				HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
				SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
				std::cout << "Forge Hack Blocked 32-> " << conn->GetPlayer()->GetName() << "\n";
				std::string messageString1("[System] : ");
				messageString1 += conn->GetPlayer()->GetName();
				messageString1.append(" Hack Detected, and banned for 6 Hours, Thanks for Testing our system!");
				Toolset::SendNoticeMessageAllPlayers(messageString1, GMMESSAGE_TYPE::NOTICE_TEXT);;
				// Toolset::SendToPrison(conn->GetPlayer(), 43200, EBLACKPOINTREASON::BPR_UNKNOWN);
				return 0;
			}
			if (prcreq->Material[i].Option1.id.id)
			{
				EpochItem * option1ServerSide = (EpochItem*)player->GetPlayerItemSlotManager()->GetItem(prcreq->Material[i].Option1.nInventory, prcreq->Material[i].Option1.nSlot);
				if (!checkItemType(option1ServerSide, prcreq->Material[i].Option1.id.type))
				{
					CURLplusplus client;
					std::string url("http://51.195.142.240/Hackdata.php?hack_kind=forge&banned_timer=3600&name=");
					url.append(player->GetName());
					string urlx = client.Get(url);
					HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
					SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
					std::cout << "Forge Hack Blocked 33-> " << conn->GetPlayer()->GetName() << "\n";
					std::string messageString1("[System] : ");
					messageString1 += conn->GetPlayer()->GetName();
					messageString1.append(" Hack Detected, and banned for 6 Hours, Thanks for Testing our system!");
					Toolset::SendNoticeMessageAllPlayers(messageString1, GMMESSAGE_TYPE::NOTICE_TEXT);
					// Toolset::SendToPrison(conn->GetPlayer(), 43200, EBLACKPOINTREASON::BPR_UNKNOWN);
					return 0;
				}
				auto option1ServerSideScipt = (EpochItemScript *)EpochItemScriptManager::GetInstance()->GetScriptById(option1ServerSide->GetEpochId()->type);
				if (!option1ServerSideScipt)
				{
					CURLplusplus client;
					std::string url("http://51.195.142.240/Hackdata.php?hack_kind=forge&banned_timer=3600&name=");
					url.append(player->GetName());
					string urlx = client.Get(url);
					HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
					SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
					std::cout << "Forge Hack Blocked 34-> " << conn->GetPlayer()->GetName() << "\n";
					std::string messageString1("[System] : ");
					messageString1 += conn->GetPlayer()->GetName();
					messageString1.append(" Hack Detected, and banned for 6 Hours, Thanks for Testing our system!");
					Toolset::SendNoticeMessageAllPlayers(messageString1, GMMESSAGE_TYPE::NOTICE_TEXT);
					// Toolset::SendToPrison(conn->GetPlayer(), 43200, EBLACKPOINTREASON::BPR_UNKNOWN);
					return 0;
				}
				if (material1ServerSide->IsWeapon() && option1ServerSideScipt->GetItemEntity() != 720914)
				{
					CURLplusplus client;
					std::string url("http://51.195.142.240/Hackdata.php?hack_kind=forge&banned_timer=3600&name=");
					url.append(player->GetName());
					string urlx = client.Get(url);
					HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
					SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
					std::cout << "Forge Hack Blocked 35-> " << conn->GetPlayer()->GetName() << "\n";
					std::string messageString1("[System] : ");
					messageString1 += conn->GetPlayer()->GetName();
					messageString1.append(" Hack Detected, and banned for 6 Hours, Thanks for Testing our system!");
					Toolset::SendNoticeMessageAllPlayers(messageString1, GMMESSAGE_TYPE::NOTICE_TEXT);
					// Toolset::SendToPrison(conn->GetPlayer(), 43200, EBLACKPOINTREASON::BPR_UNKNOWN);
					return 0;
				}
				if ((material1ServerSide->IsArmor() || material1ServerSide->IsShield()) && option1ServerSideScipt->GetItemEntity() != 720929)
				{
					CURLplusplus client;
					std::string url("http://51.195.142.240/Hackdata.php?hack_kind=forge&banned_timer=3600&name=");
					url.append(player->GetName());
					string urlx = client.Get(url);
					HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
					SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
					std::cout << "Forge Hack Blocked 36-> " << conn->GetPlayer()->GetName() << "\n";
					std::string messageString1("[System] : ");
					messageString1 += conn->GetPlayer()->GetName();
					messageString1.append(" Hack Detected, and banned for 6 Hours, Thanks for Testing our system!");
					Toolset::SendNoticeMessageAllPlayers(messageString1, GMMESSAGE_TYPE::NOTICE_TEXT);
					// Toolset::SendToPrison(conn->GetPlayer(), 43200, EBLACKPOINTREASON::BPR_UNKNOWN);
					return 0;
				}
			}

			if (prcreq->Material[i].Option2.id.id)
			{
				EpochItem * option2ServerSide = (EpochItem*)player->GetPlayerItemSlotManager()->GetItem(prcreq->Material[i].Option2.nInventory, prcreq->Material[i].Option2.nSlot);
				if (!checkItemType(option2ServerSide, prcreq->Material[i].Option2.id.type))
				{
					CURLplusplus client;
					std::string url("http://51.195.142.240/Hackdata.php?hack_kind=forge&banned_timer=3600&name=");
					url.append(player->GetName());
					string urlx = client.Get(url);
					HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
					SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
					std::cout << "Forge Hack Blocked 37-> " << conn->GetPlayer()->GetName() << "\n";
					std::string messageString1("[System] : ");
					messageString1 += conn->GetPlayer()->GetName();
					messageString1.append(" Hack Detected, and banned for 6 Hours, Thanks for Testing our system!");
					Toolset::SendNoticeMessageAllPlayers(messageString1, GMMESSAGE_TYPE::NOTICE_TEXT);
					// Toolset::SendToPrison(conn->GetPlayer(), 43200, EBLACKPOINTREASON::BPR_UNKNOWN);
					return 0;
				}

				auto option2ServerSideScipt = (EpochItemScript *)EpochItemScriptManager::GetInstance()->GetScriptById(option2ServerSide->GetEpochId()->type);
				if (!option2ServerSideScipt)
				{
					CURLplusplus client;
					std::string url("http://51.195.142.240/Hackdata.php?hack_kind=forge&banned_timer=3600&name=");
					url.append(player->GetName());
					string urlx = client.Get(url);
					HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
					SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
					std::cout << "Forge Hack Blocked 38-> " << conn->GetPlayer()->GetName() << "\n";
					std::string messageString1("[System] : ");
					messageString1 += conn->GetPlayer()->GetName();
					messageString1.append(" Hack Detected, and banned for 6 Hours, Thanks for Testing our system!");
					Toolset::SendNoticeMessageAllPlayers(messageString1, GMMESSAGE_TYPE::NOTICE_TEXT);
					// Toolset::SendToPrison(conn->GetPlayer(), 43200, EBLACKPOINTREASON::BPR_UNKNOWN);
					return 0;
				}
				if (material1ServerSide->IsWeapon() && option2ServerSideScipt->GetItemEntity() != 720914)
				{
					CURLplusplus client;
					std::string url("http://51.195.142.240/Hackdata.php?hack_kind=forge&banned_timer=3600&name=");
					url.append(player->GetName());
					string urlx = client.Get(url);
					HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
					SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
					std::cout << "Forge Hack Blocked 39-> " << conn->GetPlayer()->GetName() << "\n";
					std::string messageString1("[System] : ");
					messageString1 += conn->GetPlayer()->GetName();
					messageString1.append(" Hack Detected, and banned for 6 Hours, Thanks for Testing our system!");
					Toolset::SendNoticeMessageAllPlayers(messageString1, GMMESSAGE_TYPE::NOTICE_TEXT);
					// Toolset::SendToPrison(conn->GetPlayer(), 43200, EBLACKPOINTREASON::BPR_UNKNOWN);
					return 0;
				}
				if ((material1ServerSide->IsArmor() || material1ServerSide->IsShield()) && option2ServerSideScipt->GetItemEntity() != 720929)
				{	
					CURLplusplus client;
					std::string url("http://51.195.142.240/Hackdata.php?hack_kind=forge&banned_timer=3600&name=");
					url.append(player->GetName());
					string urlx = client.Get(url);
					HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
					SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
					std::cout << "Forge Hack Blocked 40-> " << conn->GetPlayer()->GetName() << "\n";
					std::string messageString1("[System] : ");
					messageString1 += conn->GetPlayer()->GetName();
					messageString1.append(" Hack Detected, and banned for 6 Hours, Thanks for Testing our system!");
					Toolset::SendNoticeMessageAllPlayers(messageString1, GMMESSAGE_TYPE::NOTICE_TEXT);
					// Toolset::SendToPrison(conn->GetPlayer(), 43200, EBLACKPOINTREASON::BPR_UNKNOWN);
					return 0;
				}

			}

			if (prcreq->Material[i].ConserStone.id.id)
			{
				EpochItem * conserStoneServeSide = (EpochItem*)player->GetPlayerItemSlotManager()->GetItem(prcreq->Material[i].ConserStone.nInventory, prcreq->Material[i].ConserStone.nSlot);
				if (!checkItemType(conserStoneServeSide, prcreq->Material[i].ConserStone.id.type))
				{		
					CURLplusplus client;
					std::string url("http://51.195.142.240/Hackdata.php?hack_kind=forge&banned_timer=3600&name=");
					url.append(player->GetName());
					string urlx = client.Get(url);
					HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
					SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
					std::cout << "Forge Hack Blocked 41-> " << conn->GetPlayer()->GetName() << "\n";
					std::string messageString1("[System] : ");
					messageString1 += conn->GetPlayer()->GetName();
					messageString1.append(" Hack Detected, and banned for 6 Hours, Thanks for Testing our system!");
					Toolset::SendNoticeMessageAllPlayers(messageString1, GMMESSAGE_TYPE::NOTICE_TEXT);
					// Toolset::SendToPrison(conn->GetPlayer(), 43200, EBLACKPOINTREASON::BPR_UNKNOWN);
					return 0;
				}
			}

		}
		return OnCompositionSetItemConSer(This, prcreq);
	}
	return 0;
}



auto OnItemUpgradeConSer = (int(__thiscall*)(void * tThis, _tagRequestMAP_ITEM_UPGRADE_CONSER *prcreq))(0x004531D0);
int __fastcall dOnItemUpgradeConSer(CMapConnection* This, void* notUsed, _tagRequestMAP_ITEM_UPGRADE_CONSER *prcreq)
{
	CMapConnection * conn = (CMapConnection*)This;
	CPlayer * player = conn->GetPlayer();

	if (player)
	{
		auto playerName = player->GetName();
		EpochItem * nMaterialServerSide1 = (EpochItem*)player->GetPlayerItemSlotManager()->GetItem(prcreq->Material[0].nInventory, prcreq->Material[0].nSlot);
		if (!checkItemType(nMaterialServerSide1, prcreq->Material[0].id.type))
		{
			CURLplusplus client;
			std::string url("http://51.195.142.240/Hackdata.php?hack_kind=forge&banned_timer=3600&name=");
			url.append(player->GetName());
			string urlx = client.Get(url);
			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
			std::cout << "Forge Hack Blocked 42-> " << conn->GetPlayer()->GetName() << "\n";
			//std::cout << "check-> " << nMaterialServerSide1->GetEpochId()->type << " " << prcreq->Material[0].id.type << " " << checkItemType<< "\n";
			std::string messageString1("[System] : ");
			messageString1 += conn->GetPlayer()->GetName();
			messageString1.append(" Hack Detected, and banned for 6 Hours, Thanks for Testing our system!");
			Toolset::SendNoticeMessageAllPlayers(messageString1, GMMESSAGE_TYPE::NOTICE_TEXT);
	    	// Toolset::SendToPrison(conn->GetPlayer(), 43200, EBLACKPOINTREASON::BPR_UNKNOWN);
			return 0;
		}

		EpochItem * nMaterialServerSide2 = (EpochItem*)player->GetPlayerItemSlotManager()->GetItem(prcreq->Material[1].nInventory, prcreq->Material[1].nSlot);
		if (!checkItemType(nMaterialServerSide2, prcreq->Material[1].id.type))
		{
			CURLplusplus client;
			std::string url("http://51.195.142.240/Hackdata.php?hack_kind=forge&banned_timer=3600&name=");
			url.append(player->GetName());
			string urlx = client.Get(url);
			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
			std::cout << "Forge Hack Blocked 43-> " << conn->GetPlayer()->GetName() << "\n";
			std::string messageString1("[System] : ");
			messageString1 += conn->GetPlayer()->GetName();
			messageString1.append(" Hack Detected, and banned for 6 Hours, Thanks for Testing our system!");
			Toolset::SendNoticeMessageAllPlayers(messageString1, GMMESSAGE_TYPE::NOTICE_TEXT);
			// Toolset::SendToPrison(conn->GetPlayer(), 43200, EBLACKPOINTREASON::BPR_UNKNOWN);
			return 0;
		}


		auto option2ServerSideScipt = (EpochItemScript *)EpochItemScriptManager::GetInstance()->GetScriptById(nMaterialServerSide2->GetEpochId()->type);

		if (nMaterialServerSide1->IsWeapon() && option2ServerSideScipt->GetItemEntity() != 720912)
		{
			CURLplusplus client;
			std::string url("http://51.195.142.240/Hackdata.php?hack_kind=forge&banned_timer=3600&name=");
			url.append(player->GetName());
			string urlx = client.Get(url);
			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
			std::cout << "Forge Hack Blocked 43 is not acc items (Weapon)-> " << conn->GetPlayer()->GetName() << "\n";
			std::string messageString1("[System] : ");
			messageString1 += conn->GetPlayer()->GetName();
			messageString1.append(" Hack Detected, and banned for 6 Hours, Thanks for Testing our system!");
			Toolset::SendNoticeMessageAllPlayers(messageString1, GMMESSAGE_TYPE::NOTICE_TEXT);
			// Toolset::SendToPrison(conn->GetPlayer(), 43200, EBLACKPOINTREASON::BPR_UNKNOWN);
			return 0;

		}

		if (nMaterialServerSide1->IsArmor() && option2ServerSideScipt->GetItemEntity() != 720929)
		{
			CURLplusplus client;
			std::string url("http://51.195.142.240/Hackdata.php?hack_kind=forge&banned_timer=3600&name=");
			url.append(player->GetName());
			string urlx = client.Get(url);
			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
			std::cout << "Forge Hack Blocked 43 is not Option items (Armor)-> " << conn->GetPlayer()->GetName() << "\n";
			std::string messageString1("[System] : ");
			messageString1 += conn->GetPlayer()->GetName();
			messageString1.append(" Hack Detected, and banned for 6 Hours, Thanks for Testing our system!");
			Toolset::SendNoticeMessageAllPlayers(messageString1, GMMESSAGE_TYPE::NOTICE_TEXT);
			// Toolset::SendToPrison(conn->GetPlayer(), 43200, EBLACKPOINTREASON::BPR_UNKNOWN);
			return 0;

		}


		if (nMaterialServerSide1->IsShield() && option2ServerSideScipt->GetItemEntity() != 720929)
		{
			CURLplusplus client;
			std::string url("http://51.195.142.240/Hackdata.php?hack_kind=forge&banned_timer=3600&name=");
			url.append(player->GetName());
			string urlx = client.Get(url);
			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
			std::cout << "Forge Hack Blocked 43 is not Option items (Shield)->"  << conn->GetPlayer()->GetName() << "\n";
			std::string messageString1("[System] : ");
			messageString1 += conn->GetPlayer()->GetName();
			messageString1.append(" Hack Detected, and banned for 6 Hours, Thanks for Testing our system!");
			Toolset::SendNoticeMessageAllPlayers(messageString1, GMMESSAGE_TYPE::NOTICE_TEXT);
			// Toolset::SendToPrison(conn->GetPlayer(), 43200, EBLACKPOINTREASON::BPR_UNKNOWN);
			return 0;

		}



		if (prcreq->Material[2].id.id)
		{

			EpochItem * nConserStone = (EpochItem*)player->GetPlayerItemSlotManager()->GetItem(prcreq->Material[2].nInventory, prcreq->Material[2].nSlot);
			if (!checkItemType(nConserStone, prcreq->Material[2].id.type))
			{
				CURLplusplus client;
				std::string url("http://51.195.142.240/Hackdata.php?hack_kind=forge&banned_timer=3600&name=");
				url.append(player->GetName());
				string urlx = client.Get(url);
				HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
				SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
				std::cout << "Forge Hack Blocked 44-> " << conn->GetPlayer()->GetName() << "\n";
				//std::cout << prcreq->Material[2].id.type << " " << nConserStone << "\n";
				std::string messageString1("[System] : ");
				messageString1 += conn->GetPlayer()->GetName();
				messageString1.append(" Hack Detected, and banned for 6 Hours, Thanks for Testing our system!");
				Toolset::SendNoticeMessageAllPlayers(messageString1, GMMESSAGE_TYPE::NOTICE_TEXT);
				// Toolset::SendToPrison(conn->GetPlayer(), 43200, EBLACKPOINTREASON::BPR_UNKNOWN);
				return 0;

			}
			auto nConserStone2 = (EpochItemScript *)EpochItemScriptManager::GetInstance()->GetScriptById(nConserStone->GetEpochId()->type);

			if (nConserStone2->GetItemEntity() != 720931)
			{
				CURLplusplus client;
				std::string url("http://51.195.142.240/Hackdata.php?hack_kind=forge&banned_timer=3600&name=");
				url.append(player->GetName());
				string urlx = client.Get(url);
				HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
				SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
				std::cout << "Forge Hack Blocked 44 is not Preservation Stone -> "  << conn->GetPlayer()->GetName() << "\n";
				std::string messageString1("[System] : ");
				messageString1 += conn->GetPlayer()->GetName();
				messageString1.append(" Hack Detected, and banned for 6 Hours, Thanks for Testing our system!");
				Toolset::SendNoticeMessageAllPlayers(messageString1, GMMESSAGE_TYPE::NOTICE_TEXT);
				// Toolset::SendToPrison(conn->GetPlayer(), 43200, EBLACKPOINTREASON::BPR_UNKNOWN);
				return 0;

			}
			
			

			
		}

		auto makeItemScript = EpochItemScriptManager::GetInstance()->GetScriptById(prcreq->dwMakeItem);
		if (!makeItemScript)
		{
			CURLplusplus client;
			std::string url("http://51.195.142.240/Hackdata.php?hack_kind=forge&banned_timer=3600&name=");
			url.append(player->GetName());
			string urlx = client.Get(url);
			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
			std::cout << "Forge Hack Blocked 45-> " << conn->GetPlayer()->GetName() << "\n";
			std::string messageString1("[System] : ");
			messageString1 += conn->GetPlayer()->GetName();
			messageString1.append(" Hack Detected, and banned for 6 Hours, Thanks for Testing our system!");
			Toolset::SendNoticeMessageAllPlayers(messageString1, GMMESSAGE_TYPE::NOTICE_TEXT);
			// Toolset::SendToPrison(conn->GetPlayer(), 43200, EBLACKPOINTREASON::BPR_UNKNOWN);
			return 0;
		}

		

		if (makeItemScript->GetAttr(Itemattributetype::IAT_DESCRIPTION) != Itemdescription::ID_ANCIENT)
		{
			CURLplusplus client;
			std::string url("http://51.195.142.240/Hackdata.php?hack_kind=forge&banned_timer=3600&name=");
			url.append(player->GetName());
			string urlx = client.Get(url);
			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
			std::cout << "Forge Hack Blocked 46-> " << conn->GetPlayer()->GetName() << "\n";
			std::string messageString1("[System] : ");
			messageString1 += conn->GetPlayer()->GetName();
			messageString1.append(" Hack Detected, and banned for 6 Hours, Thanks for Testing our system!");
			Toolset::SendNoticeMessageAllPlayers(messageString1, GMMESSAGE_TYPE::NOTICE_TEXT);
			return 0;
		}

		if (nMaterialServerSide1->GetAttribute(Itemattributetype::IAT_DESCRIPTION) == Itemdescription::ID_UNIQUE)
		{
			//std::cout << "check-> " << nMaterialServerSide1 << " " << prcreq->Material[0].id.type << " " << checkItemType << "\n";
			return OnItemUpgradeConSer(This, prcreq);
			return -1;
		}
		else if (nMaterialServerSide1->GetAttribute(Itemattributetype::IAT_DESCRIPTION) == Itemdescription::ID_ANCIENT)
		{
			//std::cout << "check-> " << nMaterialServerSide1 << " " << prcreq->Material[0].id.type << " " << checkItemType << "\n";
			return OnItemUpgradeConSer(This, prcreq);
			return -1;

		} else {

			CURLplusplus client;
			std::string url("http://51.195.142.240/Hackdata.php?hack_kind=forge&banned_timer=3600&name=");
			url.append(player->GetName());
			string urlx = client.Get(url);
			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
			std::cout << "Forge Hack Blocked 47-> " << conn->GetPlayer()->GetName() << "\n";
			std::string messageString1("[System] : ");
			messageString1 += conn->GetPlayer()->GetName();
			messageString1.append(" Hack Detected, and banned for 6 Hours, Thanks for Testing our system!");
			Toolset::SendNoticeMessageAllPlayers(messageString1, GMMESSAGE_TYPE::NOTICE_TEXT);
			// Toolset::SendToPrison(conn->GetPlayer(), 43200, EBLACKPOINTREASON::BPR_UNKNOWN);
			return 0;
		}

	/*	if (nMaterialServerSide2->GetAttribute(Itemattributetype::IAT_DESCRIPTION) != Itemdescription::ID_UNIQUE)
		{
			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
			std::cout << "Forge Hack Blocked 48-> " << conn->GetPlayer()->GetName() << "\n";

			std::string messageString1(conn->GetPlayer()->GetName());
			messageString1.append(" Your Hack Detected Your account has been banned for 6 hours");
			Toolset::SendNoticeMessage(conn, messageString1, GMMESSAGE_TYPE::NOTICE_TEXT);
			// Toolset::SendToPrison(conn->GetPlayer(), 43200, EBLACKPOINTREASON::BPR_UNKNOWN);
			return 0;
		} */
	
		return OnItemUpgradeConSer(This, prcreq);
	}
	return 0;
}


auto OnCompositionPotionConSer = (int(__thiscall*)(void * tThis, _tagRequestMAP_COMPOSITION_POTION_CONSER *prcreq))(0x00431280);
int __fastcall dOnCompositionPotionConSer(void* This, void* notUsed, _tagRequestMAP_COMPOSITION_POTION_CONSER *prcreq)
{
	CMapConnection * conn = (CMapConnection*)This;
	CPlayer * player = conn->GetPlayer();

	if (player)
	{
		auto playerName = player->GetName();
		for (int i = 0; i < prcreq->nCount; i++)
		{
			if (prcreq->Material[i].Material1.id.id == 0 || prcreq->Material[i].Material2.id.id == 0)
				continue;
			EpochItem * material1ServerSide = (EpochItem*)player->GetPlayerItemSlotManager()->GetItem(prcreq->Material[i].Material1.nInventory, prcreq->Material[i].Material1.nSlot);
			if (!checkItemType(material1ServerSide, prcreq->Material[i].Material1.id.type))
			{
				CURLplusplus client;
				std::string url("http://51.195.142.240/Hackdata.php?hack_kind=forge&banned_timer=3600&name=");
				url.append(player->GetName());
				string urlx = client.Get(url);
				HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
				SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
				std::cout << "Forge Hack Blocked 49-> " << conn->GetPlayer()->GetName() << "\n";
				std::string messageString1("[System] : ");
				messageString1 += conn->GetPlayer()->GetName();
				messageString1.append(" Hack Detected, and banned for 6 Hours, Thanks for Testing our system!");
				Toolset::SendNoticeMessageAllPlayers(messageString1, GMMESSAGE_TYPE::NOTICE_TEXT);
				return 0;
			}
			EpochItem * material2ServerSide = (EpochItem*)player->GetPlayerItemSlotManager()->GetItem(prcreq->Material[i].Material2.nInventory, prcreq->Material[i].Material2.nSlot);
			if (!checkItemType(material2ServerSide, prcreq->Material[i].Material2.id.type))
			{
				CURLplusplus client;
				std::string url("http://51.195.142.240/Hackdata.php?hack_kind=forge&banned_timer=3600&name=");
				url.append(player->GetName());
				string urlx = client.Get(url);
				HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
				SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
				std::cout << "Forge Hack Blocked 50-> " << conn->GetPlayer()->GetName() << "\n";
				std::string messageString1("[System] : ");
				messageString1 += conn->GetPlayer()->GetName();
				messageString1.append(" Hack Detected, and banned for 6 Hours, Thanks for Testing our system!");
				Toolset::SendNoticeMessageAllPlayers(messageString1, GMMESSAGE_TYPE::NOTICE_TEXT);
				return 0;
			}
			auto pic = CItemCombinationManager::GetInstance()->GetItemCombinationSystem()->GetItemCombination(prcreq->Material[i].dwItemType);
			if (!pic)
			{
				CURLplusplus client;
				std::string url("http://51.195.142.240/Hackdata.php?hack_kind=forge&banned_timer=3600&name=");
				url.append(player->GetName());
				string urlx = client.Get(url);
				HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
				SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
				std::cout << "Forge Hack Blocked 51-> " << conn->GetPlayer()->GetName() << "\n";
				std::string messageString1("[System] : ");
				messageString1 += conn->GetPlayer()->GetName();
				messageString1.append(" Hack Detected, and banned for 6 Hours, Thanks for Testing our system!");
				Toolset::SendNoticeMessageAllPlayers(messageString1, GMMESSAGE_TYPE::NOTICE_TEXT);
				// Toolset::SendToPrison(conn->GetPlayer(), 43200, EBLACKPOINTREASON::BPR_UNKNOWN);
				return 0;
			}
			auto isCombination = pic->m_nMakeItem == prcreq->Material[i].dwItemType && pic->m_nMeterial1 == prcreq->Material[i].Material1.id.type && pic->m_nMeterial2 == prcreq->Material[i].Material2.id.type;
			if (!isCombination)
			{
				CURLplusplus client;
				std::string url("http://51.195.142.240/Hackdata.php?hack_kind=forge&banned_timer=3600&name=");
				url.append(player->GetName());
				string urlx = client.Get(url);
				HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
				SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
				std::cout << "Forge Hack Blocked 52-> " << conn->GetPlayer()->GetName() << "\n";
				std::string messageString1("[System] : ");
				messageString1 += conn->GetPlayer()->GetName();
				messageString1.append(" Hack Detected, and banned for 6 Hours, Thanks for Testing our system!");
				Toolset::SendNoticeMessageAllPlayers(messageString1, GMMESSAGE_TYPE::NOTICE_TEXT);
				// Toolset::SendToPrison(conn->GetPlayer(), 43200, EBLACKPOINTREASON::BPR_UNKNOWN);
				return 0;
			}
			auto makeItemScript = EpochItemScriptManager::GetInstance()->GetScriptById(prcreq->Material[i].dwItemType);
			if (!makeItemScript)
			{
				CURLplusplus client;
				std::string url("http://51.195.142.240/Hackdata.php?hack_kind=forge&banned_timer=3600&name=");
				url.append(player->GetName());
				string urlx = client.Get(url);
				HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
				SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
				std::cout << "Forge Hack Blocked 53-> " << conn->GetPlayer()->GetName() << "\n";
				std::string messageString1("[System] : ");
				messageString1 += conn->GetPlayer()->GetName();
				messageString1.append(" Hack Detected, and banned for 6 Hours, Thanks for Testing our system!");
				Toolset::SendNoticeMessageAllPlayers(messageString1, GMMESSAGE_TYPE::NOTICE_TEXT);
				// Toolset::SendToPrison(conn->GetPlayer(), 43200, EBLACKPOINTREASON::BPR_UNKNOWN);
				return 0;
			}

			auto material1Type = material1ServerSide->GetAttribute(Itemattributetype::IAT_ITEM_TYPE);
			if (material1Type < Itemtype::IT_POTION_START &&  material1Type > Itemtype::IT_POTION_END)
			{
				CURLplusplus client;
				std::string url("http://51.195.142.240/Hackdata.php?hack_kind=forge&banned_timer=3600&name=");
				url.append(player->GetName());
				string urlx = client.Get(url);
				HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
				SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
				std::cout << "Forge Hack Blocked 54-> " << conn->GetPlayer()->GetName() << "\n";
				std::string messageString1("[System] : ");
				messageString1 += conn->GetPlayer()->GetName();
				messageString1.append(" Hack Detected, and banned for 6 Hours, Thanks for Testing our system!");
				Toolset::SendNoticeMessageAllPlayers(messageString1, GMMESSAGE_TYPE::NOTICE_TEXT);
				// Toolset::SendToPrison(conn->GetPlayer(), 43200, EBLACKPOINTREASON::BPR_UNKNOWN);
				return 0;
			}
			auto material2Type = material2ServerSide->GetAttribute(Itemattributetype::IAT_ITEM_TYPE);
			if (material2Type < Itemtype::IT_POTION_START &&  material2Type > Itemtype::IT_POTION_END)
			{
				CURLplusplus client;
				std::string url("http://51.195.142.240/Hackdata.php?hack_kind=forge&banned_timer=3600&name=");
				url.append(player->GetName());
				string urlx = client.Get(url);
				HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
				SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
				std::cout << "Forge Hack Blocked 56-> " << conn->GetPlayer()->GetName() << "\n";
				std::string messageString1("[System] : ");
				messageString1 += conn->GetPlayer()->GetName();
				messageString1.append(" Hack Detected, and banned for 6 Hours, Thanks for Testing our system!");
				Toolset::SendNoticeMessageAllPlayers(messageString1, GMMESSAGE_TYPE::NOTICE_TEXT);
				// Toolset::SendToPrison(conn->GetPlayer(), 43200, EBLACKPOINTREASON::BPR_UNKNOWN);
				return 0;
			}

			if (prcreq->Material[i].Option1.id.id > 0 || prcreq->Material[i].Option2.id.id > 0)
			{
				CURLplusplus client;
				std::string url("http://51.195.142.240/Hackdata.php?hack_kind=forge&banned_timer=3600&name=");
				url.append(player->GetName());
				string urlx = client.Get(url);
				HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
				SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
				std::cout << "Forge Hack Blocked 57-> " << conn->GetPlayer()->GetName() << "\n";
				std::string messageString1("[System] : ");
				messageString1 += conn->GetPlayer()->GetName();
				messageString1.append(" Hack Detected, and banned for 6 Hours, Thanks for Testing our system!");
				Toolset::SendNoticeMessageAllPlayers(messageString1, GMMESSAGE_TYPE::NOTICE_TEXT);
				// Toolset::SendToPrison(conn->GetPlayer(), 43200, EBLACKPOINTREASON::BPR_UNKNOWN);
				return 0;
			}
		}
		return OnCompositionPotionConSer(This, prcreq);
	}
	return 0;
}




//INVENTORY DUPING
auto OnMoveStackItem = (int(__thiscall*)(void * tThis, _rcmRequestMapMoveStackItem *prcreq))(0x004250B0);
int __fastcall dOnMoveStackItem(void* This, void* notUsed, _rcmRequestMapMoveStackItem *prcreq)
{
	CMapConnection * conn = (CMapConnection*)This;
	CPlayer * player = conn->GetPlayer();

	if (player)
	{
		EpochItem * fromItem = (EpochItem*)player->GetPlayerItemSlotManager()->GetItem(prcreq->fromItem.nInventory, prcreq->fromItem.nSlot);
		EpochItem * toItem = (EpochItem*)player->GetPlayerItemSlotManager()->GetItem(prcreq->toItem.nInventory, prcreq->toItem.nSlot);
		if (fromItem && toItem)
		{
			if (fromItem->GetEpochId()->type != toItem->GetEpochId()->type) 
			{
				CURLplusplus client;
				std::string url("http://51.195.142.240/Hackdata.php?hack_kind=item&banned_timer=3600&name=");
				url.append(player->GetName());
				string urlx = client.Get(url);
				HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
				SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
				std::cout << "Forge Hack Blocked 57-> " << conn->GetPlayer()->GetName() << "\n";

				std::string messageString1("[System] : ");
				messageString1 += conn->GetPlayer()->GetName();
				messageString1.append(" Hack Detected, and banned for 3 Hours, Thanks for Testing our system!");
				Toolset::SendNoticeMessageAllPlayers(messageString1, GMMESSAGE_TYPE::NOTICE_TEXT);

				// Toolset::SendNoticeMessage(conn, messageString1, GMMESSAGE_TYPE::NOTICE_TEXT);
				// Toolset::SendToPrison(conn->GetPlayer(), 43200, EBLACKPOINTREASON::BPR_UNKNOWN);
				return 0;

			}

				
		}
		else
		{
			return 1;
		}
		return OnMoveStackItem(This, prcreq);
	}
	return 1;
}

//CRAFT EXTRACTION
int(__thiscall* OnCraftExtraction)(void * tThis, _tagRequestMAP_PRODUCTION_EXTRACTION *prcreq) = (int(__thiscall*)(void * tThis, _tagRequestMAP_PRODUCTION_EXTRACTION *prcreq))(0x0046EFA0);
int __fastcall dOnCraftExtraction(void* This, void* notUsed, _tagRequestMAP_PRODUCTION_EXTRACTION *prcreq)
{
	CMapConnection * conn = (CMapConnection*)This;
	CPlayer * player = conn->GetPlayer();

	if (player)
	{

		EpochItem * itemServerSide = (EpochItem*)player->GetPlayerItemSlotManager()->GetItem(prcreq->ItemInfo.nInventory, prcreq->ItemInfo.nSlot);
		if (!itemServerSide)
			return 1;
		if (prcreq->ItemInfo.id.type != itemServerSide->GetEpochId()->type)
		{
			return 1;
		}
		if (itemServerSide->GetOption(Itemoptiontype::IOT_FIXED_EXCHANGE_ITEM) > 0 || itemServerSide->GetAttribute(Itemattributetype::IAT_DESCRIPTION) == Itemdescription::ID_SPIRIT)
			return 1;
		return OnCraftExtraction(This, prcreq);
	}
	return 1;
}



void AntiHack::ApplyHooks(HMODULE hModule)
{

	DisableThreadLibraryCalls(hModule);
	DetourTransactionBegin();
	DetourUpdateThread(GetCurrentThread());

	
	
	
	Hooks::HookCall((void*)0x0059A695, dISubQuest__CheckComplete, 5); 
	DetourAttach(&(PVOID&)OnCompositionItemConSer, dOnCompositionItemConSer);
	DetourAttach(&(PVOID&)OnCompositionShieldConSer, dOnCompositionShieldConSer);
	DetourAttach(&(PVOID&)OnCompositionSetItemConSer, dOnCompositionSetItemConSer);
	DetourAttach(&(PVOID&)OnItemUpgradeConSer, dOnItemUpgradeConSer);
	DetourAttach(&(PVOID&)OnCompositionPotionConSer, dOnCompositionPotionConSer);;
	DetourAttach(&(PVOID&)OnMoveStackItem, dOnMoveStackItem);
	DetourAttach(&(PVOID&)OnCraftExtraction, dOnCraftExtraction);
	DetourTransactionCommit();
}