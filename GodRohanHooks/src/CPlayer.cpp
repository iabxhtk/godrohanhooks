#include "stdafx.h"
#include "Player.h"
#include "MapEnums.h"
#include "EntityManager.h"
#include "Toolset.h"
#include <string>


auto CPlayer_LevelUpPocess = (void(__thiscall*)(void * tThis, int addLevel))(0x004F18A0);//(0x004DA5E0) 0x004F18A0;
void __fastcall dCPlayer_LevelUpPocess(void* This, void* notUsed, int addLevel)
{


	//CMapConnection * conn = (CMapConnection*)This;

	CPlayer_LevelUpPocess(This, addLevel);
	CPlayer * player = (CPlayer*)This;


	int currentLevel = player->GetAbility(Characterability::CA_LEVEL);

	if (currentLevel > 150)
	{
		int conlv = currentLevel - 115;
		int realv = 115;
		std::string charName(player->GetName());
		std::string message = "Congratulations " + charName + " For Reaching " + std::to_string(realv) + "(+" + std::to_string(conlv) + ")" + " Level";
		Toolset::SendNoticeMessageAllPlayers(message, GMMESSAGE_TYPE::NOTICE_TEXT);
	}








	/*
	std::string messageStringg(player->GetName());
	messageStringg.append(", Congratulations for reaching level " + std::to_string(currentLevel) + "! Check your Event Inventory for 10 million Crones! ");

	Toolset::SendNoticeMessagelv(player->GetConnection(), messageStringg, GMMESSAGE_TYPE::NOTICE_TEXT);





	if (currentLevel >= 120 && currentLevel <= 125)
	{

		std::string charName(player->GetName());
		std::string message = "Congratulations " + charName + " For Reaching " + std::to_string(currentLevel) + " Level";
		Toolset::SendNoticeMessageAllPlayers(message, GMMESSAGE_TYPE::NOTICE_TEXT);

	}
	else if (currentLevel >= 126 && currentLevel <= 129)

	{
		std::string charName(player->GetName());
		std::string message = "Big Congratulations " + charName + " For Reaching " + std::to_string(currentLevel) + " Level";
		Toolset::SendNoticeMessageAllPlayers(message, GMMESSAGE_TYPE::NOTICE_TEXT);

	}
	else if (currentLevel == 130)
	{
		std::string charName(player->GetName());
		std::string message = "Big Congratulations " + charName + " For Reaching Max level in Server 130 Level";
		Toolset::SendNoticeMessageAllPlayers(message, GMMESSAGE_TYPE::NOTICE_TEXT);
	}


	if (currentLevel == 40)
	{

		std::string messageStringg(player->GetName());
		messageStringg.append(", Congratulations for reaching level " + std::to_string(currentLevel) + "! Check your Event Inventory for Costume Hat! ");
		Toolset::SendNoticeMessagelv(player->m_pConnection, messageStringg, GMMESSAGE_TYPE::NOTICE_TEXT);

	}
	else if (currentLevel == 50)
	{
		std::string messageStringg(player->GetName());
		messageStringg.append(", Congratulations for reaching level " + std::to_string(currentLevel) + "! Check your Event Inventory for Costume Tunic! ");
		Toolset::SendNoticeMessagelv(player->m_pConnection, messageStringg, GMMESSAGE_TYPE::NOTICE_TEXT);

	}

	else if (currentLevel == 60)
	{
		std::string messageStringg(player->GetName());
		messageStringg.append(", Congratulations for reaching level " + std::to_string(currentLevel) + "! Check your Event Inventory for 10 million Crones! ");
		Toolset::SendNoticeMessagelv(player->m_pConnection, messageStringg, GMMESSAGE_TYPE::NOTICE_TEXT);

	}
	else if (currentLevel == 70)
	{
		std::string messageStringg(player->GetName());
		messageStringg.append(", Congratulations for reaching level " + std::to_string(currentLevel) + "! Check your Event Inventory for 50K SexyG4m3rZ Money! ");
		Toolset::SendNoticeMessagelv(player->m_pConnection, messageStringg, GMMESSAGE_TYPE::NOTICE_TEXT);

	}
	else if (currentLevel == 80)
	{
		std::string messageStringg(player->GetName());
		messageStringg.append(", Congratulations for reaching level " + std::to_string(currentLevel) + "! Check your Event Inventory for 10 ARS! ");
		Toolset::SendNoticeMessagelv(player->m_pConnection, messageStringg, GMMESSAGE_TYPE::NOTICE_TEXT);

	}
	else if (currentLevel == 90)
	{
		std::string messageStringg(player->GetName());
		messageStringg.append(", Congratulations for reaching level " + std::to_string(currentLevel) + "! Check your Event Inventory for 10 Deluxe ERA! ");
		Toolset::SendNoticeMessagelv(player->m_pConnection, messageStringg, GMMESSAGE_TYPE::NOTICE_TEXT);

	}
	else if (currentLevel == 95)
	{
		std::string messageStringg(player->GetName());
		messageStringg.append(", Congratulations for reaching level " + std::to_string(currentLevel) + "! Check your Event Inventory for 10 24HR Pet Food! ");
		Toolset::SendNoticeMessagelv(player->m_pConnection, messageStringg, GMMESSAGE_TYPE::NOTICE_TEXT);

	}
	else if (currentLevel == 100)
	{
		std::string messageStringg(player->GetName());
		messageStringg.append(", Congratulations for reaching level " + std::to_string(currentLevel) + "! Check your Event Inventory for 3 Tightly bag ");
		Toolset::SendNoticeMessagelv(player->m_pConnection, messageStringg, GMMESSAGE_TYPE::NOTICE_TEXT);

	}
	else if (currentLevel == 105)
	{
		std::string messageStringg(player->GetName());
		messageStringg.append(", Congratulations for reaching level " + std::to_string(currentLevel) + "! Check your Event Inventory for 4 Walter Medal +3 ");
		Toolset::SendNoticeMessagelv(player->m_pConnection, messageStringg, GMMESSAGE_TYPE::NOTICE_TEXT);

	}
	else if (currentLevel == 110)
	{
		std::string messageStringg(player->GetName());
		messageStringg.append(", Congratulations for reaching level " + std::to_string(currentLevel) + "! Check your Event Inventory for Some Forging Stones ");
		Toolset::SendNoticeMessagelv(player->m_pConnection, messageStringg, GMMESSAGE_TYPE::NOTICE_TEXT);

	}
	else if (currentLevel == 115)
	{
		std::string messageStringg(player->GetName());
		messageStringg.append(", Congratulations for reaching level " + std::to_string(currentLevel) + "! Check your Event Inventory for Some Money Tickets ");
		Toolset::SendNoticeMessagelv(player->m_pConnection, messageStringg, GMMESSAGE_TYPE::NOTICE_TEXT);

	}
	else if (currentLevel == 120)
	{
		std::string messageStringg(player->GetName());
		messageStringg.append(", Congratulations for reaching level " + std::to_string(currentLevel) + "! Check your Account We insert 3000 Free Point ");
		Toolset::SendNoticeMessagelv(player->m_pConnection, messageStringg, GMMESSAGE_TYPE::NOTICE_TEXT);

	}
	else if (currentLevel == 121)
	{
		std::string messageStringg(player->GetName());
		messageStringg.append(", Congratulations for reaching level " + std::to_string(currentLevel) + "! Check your Account We insert 1000 Free Point ");
		Toolset::SendNoticeMessagelv(player->m_pConnection, messageStringg, GMMESSAGE_TYPE::NOTICE_TEXT);

	}
	else if (currentLevel == 122)
	{
		std::string messageStringg(player->GetName());
		messageStringg.append(", Congratulations for reaching level " + std::to_string(currentLevel) + "! Check your Account We insert 1000 Free Point ");
		Toolset::SendNoticeMessagelv(player->m_pConnection, messageStringg, GMMESSAGE_TYPE::NOTICE_TEXT);

	}
	else if (currentLevel == 123)
	{
		std::string messageStringg(player->GetName());
		messageStringg.append(", Congratulations for reaching level " + std::to_string(currentLevel) + "! Check your Account We insert 1000 Free Point ");
		Toolset::SendNoticeMessagelv(player->m_pConnection, messageStringg, GMMESSAGE_TYPE::NOTICE_TEXT);

	}
	else if (currentLevel == 124)
	{
		std::string messageStringg(player->GetName());
		messageStringg.append(", Congratulations for reaching level " + std::to_string(currentLevel) + "! Check your Account We insert 1000 Free Point ");
		Toolset::SendNoticeMessagelv(player->m_pConnection, messageStringg, GMMESSAGE_TYPE::NOTICE_TEXT);

	}
	else if (currentLevel == 125)
	{
		std::string messageStringg(player->GetName());
		messageStringg.append(", Congratulations for reaching level " + std::to_string(currentLevel) + "! Check your Account We insert 3000 IPS and FP ");
		Toolset::SendNoticeMessagelv(player->m_pConnection, messageStringg, GMMESSAGE_TYPE::NOTICE_TEXT);

	}
	else if (currentLevel == 126)
	{
		std::string messageStringg(player->GetName());
		messageStringg.append(", Congratulations for reaching level " + std::to_string(currentLevel) + "! Check your Account We insert 5000 Free Point ");
		Toolset::SendNoticeMessagelv(player->m_pConnection, messageStringg, GMMESSAGE_TYPE::NOTICE_TEXT);

	}
	else if (currentLevel == 127)
	{
		std::string messageStringg(player->GetName());
		messageStringg.append(", Congratulations for reaching level " + std::to_string(currentLevel) + "! Check your Account We insert 5000 Free Point ");
		Toolset::SendNoticeMessagelv(player->m_pConnection, messageStringg, GMMESSAGE_TYPE::NOTICE_TEXT);

	}
	else if (currentLevel == 128)
	{
		std::string messageStringg(player->GetName());
		messageStringg.append(", Congratulations for reaching level " + std::to_string(currentLevel) + "! Check your Account We insert 5000 Free Point ");
		Toolset::SendNoticeMessagelv(player->m_pConnection, messageStringg, GMMESSAGE_TYPE::NOTICE_TEXT);

	}
	else if (currentLevel == 129)
	{
		std::string messageStringg(player->GetName());
		messageStringg.append(", Congratulations for reaching level " + std::to_string(currentLevel) + "! Check your Account We insert 5000 Free Point ");
		Toolset::SendNoticeMessagelv(player->m_pConnection, messageStringg, GMMESSAGE_TYPE::NOTICE_TEXT);

	}
	else if (currentLevel == 130)
	{
		std::string messageStringg(player->GetName());
		messageStringg.append(", Congratulations for reaching level " + std::to_string(currentLevel) + "! Check your Account We insert 10.000 IPS and FP ");
		Toolset::SendNoticeMessagelv(player->m_pConnection, messageStringg, GMMESSAGE_TYPE::NOTICE_TEXT);

	}

	if (currentLevel == 50)
	{
		std::string charName(player->GetName());
		std::string messageStringg("Good Job "+ charName +" you're now Level " + std::to_string(currentLevel) + " Relog to change job and if you want the other job use the changejob stone from your Event Inventory ");
		//messageStringg.append(", in Level " + std::to_string(currentLevel) + "! ");
		Toolset::SendNoticeMessagelv(player->m_pConnection, messageStringg, GMMESSAGE_TYPE::NOTICE_BOX);

	}
	if (currentLevel == 60)
	{
		std::string charName(player->GetName());
		std::string messageStringg(" Use The 10M from your Event Inventory to buy New weapon from Newibe Weapon Shop ");
		//messageStringg.append(", in Level " + std::to_string(currentLevel) + "! ");
		Toolset::SendNoticeMessagelv(player->m_pConnection, messageStringg, GMMESSAGE_TYPE::NOTICE_BOX);

	}



	if (currentLevel >= 70 && currentLevel <= 114 )
	{
		std::string charName(player->GetName());
		std::string messageStringg(" We Recommend you " + charName + " The Best Area for Leveling at level " + std::to_string(currentLevel) + " are upper its safe with Anti-PK Guards ");
		//messageStringg.append(", in Level " + std::to_string(currentLevel) + "! ");
		Toolset::SendNoticeMessagelv(player->m_pConnection, messageStringg, GMMESSAGE_TYPE::NOTICE_BOX);

	}

	if (currentLevel == 115)
	{
		std::string charName(player->GetName());
		std::string messageStringg(" Great Job " + charName + " you're now level 115 go meet Kim There story quests with great Rewards ");
		//messageStringg.append(", in Level " + std::to_string(currentLevel) + "! ");
		Toolset::SendNoticeMessagelv(player->m_pConnection, messageStringg, GMMESSAGE_TYPE::NOTICE_BOX);

	}



	*/


}

void CPlayer::DeletePlayerExtension()
{
	PlayerExtensions * extsn = GetPlayerExtensions();
	delete extsn;
	extsn = nullptr;
	*(int*)((char*)this + 0x2058u) = (int)0;
}

void CPlayer::SetPlayerExtensions(PlayerExtensions * extsn)
{

	*(int*)((char*)this + 0x2058u) = (int)extsn;
}


void CPlayer::InitPlayerHooks(HMODULE hModule)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);

	DisableThreadLibraryCalls(hModule);
	DetourTransactionBegin();
	DetourUpdateThread(GetCurrentThread());
	DetourAttach(&(PVOID&)CPlayer_LevelUpPocess, dCPlayer_LevelUpPocess);
	DetourTransactionCommit();
}