
#include "stdafx.h"
#include "CMapConnection.h"
#include "time.h"
#include <chrono>
#include <thread>
#include "Toolset.h"
#include "MapEnums.h"
#include "AdvancedHK.h"
#include "CRegionAndRoomManager.h"
#include <ctime>
#include <stdio.h>
#include "CURLplusplus.h"


/*
	Mostly fixes to protocols and packets like chat, kiosk etc.
*/




#pragma pack( push,1)
struct _tagGR_LINK_CHAT
{
	__int16 nLen;
	__int16 nLinkInfoLen;
	char bType[3];
	char szMsg[1];
};

#pragma pack(pop)
struct chatPacketNew
{
	unsigned int dwChar;
	_tagGR_LINK_CHAT chat;
};
void CMapConnection::SystemShutdown(UINT nSDType)
{
	HANDLE           hToken;
	TOKEN_PRIVILEGES tkp;
	::OpenProcessToken(::GetCurrentProcess(), TOKEN_ADJUST_PRIVILEGES | TOKEN_QUERY, &hToken);
	::LookupPrivilegeValue(NULL, SE_SHUTDOWN_NAME, &tkp.Privileges[0].Luid);
	tkp.PrivilegeCount = 1;
	tkp.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;
	::AdjustTokenPrivileges(hToken, FALSE, &tkp, 0, (PTOKEN_PRIVILEGES)NULL, 0);

	switch (nSDType)
	{
	case 0: ::ExitWindowsEx(EWX_SHUTDOWN | EWX_FORCE, 0); break;
	case 1: ::ExitWindowsEx(EWX_POWEROFF | EWX_FORCE, 0); break;
	case 2: ::ExitWindowsEx(EWX_REBOOT | EWX_FORCE, 0); break;
	}
}
int(__thiscall* SendPacketEx)(void * tThis, unsigned __int16, const void*, unsigned int) = (int(__thiscall*)(void * tThis, unsigned __int16, const void*, unsigned int))(0x0066A2C0);//(0x0062CE10) 0x0066A2C0
int __fastcall dSendPacketEx(void* This, void* notUsed, unsigned __int16 nType, const void *pData, unsigned int nSize)
{
	//std::cout << "1- " << nType << "\n";
	CMapConnection * conn = (CMapConnection*)This;
	CPlayer * player = (CPlayer*)conn->GetPlayer();

	if (nType && !conn->GetPlayer()) {
		if (nType == 57345 || nType == 57346 || nType == 57348 || nType == 53505 || nType == 40961 || nType == 40962
			|| nType == 40963 || nType == 40964 || nType == 40965 || nType == 40966 || nType == 1281 || nType == 57351) {
			return  SendPacketEx(This, nType, pData, nSize);
		}
		else {

			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
			//std::cout << "4- Packet Blocked Non Player! " << nType << "\n";
			return 0;

		}
	}
	switch (nType)
	{

	case 65014:
	case 6217:
	case 6218:
	{
		return 0;
	
	}







	case 7430:
	{
		char * buff = new char[nSize + 10];
		memcpy(buff, (char*)pData, 101);
		buff[101] = 228;
		buff[102] = 4;
		buff[103] = 0;
		buff[104] = 0;
		buff[105] = 0;
		buff[106] = 0;
		buff[107] = 0;
		buff[108] = 0;
		buff[109] = 9;
		buff[110] = 4;
		memcpy(buff + 111, (char*)pData + 101, nSize - 101);

		SendPacketEx(This, nType, (void *)buff, nSize + 10);
		delete[] buff;
		return 0;
	}





	case 7945:
	case 7946:
	{
		char * buff = new char[nSize + 10];
		memcpy(buff, (char*)pData, 3);
		buff[3] = 228;
		buff[4] = 4;
		buff[5] = 0;
		buff[6] = 0;
		buff[7] = 0;
		buff[8] = 0;
		buff[9] = 0;
		buff[10] = 0;
		buff[11] = 9;
		buff[12] = 4;
		memcpy(buff + 13, (char*)pData + 3, nSize - 3);

		SendPacketEx(This, nType, (void *)buff, nSize + 10);
		delete[] buff;
		return 0;
	}
	
	case 7939:
	case 7940:
	case 7942:
	case 7943:
	case 7944:
	{
		char * buff = new char[nSize + 10];
		memcpy(buff, (char*)pData, 26);
		memset(buff + 26, 0, 10);
		memcpy(buff + 36, (char*)pData + 26, nSize - 26);
		SendPacketEx(This, nType, (void *)buff, nSize + 10);
		delete buff;
		return 0;
	}



	case 7941:
	{
		char * buff = new char[nSize + 10];
		memcpy(buff, (char*)pData, 51);
		memset(buff + 51, 0, 10);
		memcpy(buff + 61, (char*)pData + 51, nSize - 51);
		SendPacketEx(This, nType, (void *)buff, nSize + 10);
		return 0;
	}
	default:
		return  SendPacketEx(This, nType, pData, nSize);
	}
}


HRESULT(__thiscall* Comm_OnMsgPacket)(void * tThis, _tagGOPacket *pPacket) = (HRESULT(__thiscall*)(void * tThis, _tagGOPacket *pPacket))(0x00404EC0);// (0x00404E10) 0x00404EC0
HRESULT __fastcall dComm_OnMsgPacket(void* This, void* notUsed, _tagGOPacket *pPacket)
{

	CMapConnection * conn = (CMapConnection*)This;

	CPlayer * player = (CPlayer*)conn->GetPlayer();

	if (pPacket->type && !conn->GetPlayer()) {

		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
		//std::cout << "3- Packet Blocked Non Player! " << pPacket->type << "\n";
		return 0;

	}

	switch (pPacket->type)

	{




	case 6218:
	case 6217:
	{

		return 0;
	}



	case 20465:
	{

		if (pPacket->size >= 17) {

			//const char kArabicSampleText[] = { -40, -89, -39, -124, -40, -71, -40, -79, -40, -88, -39, -118, -40, -87, 0 };

			char * cBuff = pPacket->data;
			std::vector<char> buffVec(4);
			__int16 ogPacketSize = pPacket->size;
			pPacket->size -= 10;
			buffVec.at(0) = *((unsigned char*)&pPacket->type + 0);
			buffVec.at(1) = *((unsigned char*)&pPacket->type + 1);
			buffVec.at(2) = *((unsigned char*)&pPacket->size + 0);
			buffVec.at(3) = *((unsigned char*)&pPacket->size + 1);
			buffVec.insert(buffVec.begin() + 4, cBuff, cBuff + ogPacketSize);
			buffVec.erase(buffVec.begin() + 8, buffVec.begin() + 18);
			pPacket = (_tagGOPacket*)&buffVec[0];;
			if (conn->HandleCommand(pPacket))
				return 1;
			Comm_OnMsgPacket(This, pPacket);


			chatPacketNew * chatpck = (chatPacketNew*)pPacket->data;
			std::string chatMssgString((char*)chatpck->chat.szMsg, chatpck->chat.nLen);
			std::istringstream stringStream(chatMssgString);
			std::string commandName;
			stringStream >> commandName;

			std::string buff;
			std::string worldMssg = "[System] :";

			while (stringStream >> buff)
			{
				worldMssg += " " + buff;
			}

			Toolset::SendNoticeMessageAllPlayers(worldMssg, GMMESSAGE_TYPE::NOTICE_TEXT);
			return true;

		}
	}
	case 7939:
	case 7940:
	case 7942:
	case 7943:
	case 7944:

	{

		if (pPacket->size >= 17) {

			//const char kArabicSampleText[] = { -40, -89, -39, -124, -40, -71, -40, -79, -40, -88, -39, -118, -40, -87, 0 };

			char * cBuff = pPacket->data;
			std::vector<char> buffVec(4);
			__int16 ogPacketSize = pPacket->size;
			pPacket->size -= 10;
			buffVec.at(0) = *((unsigned char*)&pPacket->type + 0);
			buffVec.at(1) = *((unsigned char*)&pPacket->type + 1);
			buffVec.at(2) = *((unsigned char*)&pPacket->size + 0);
			buffVec.at(3) = *((unsigned char*)&pPacket->size + 1);
			buffVec.insert(buffVec.begin() + 4, cBuff, cBuff + ogPacketSize);
			buffVec.erase(buffVec.begin() + 8, buffVec.begin() + 18);
			pPacket = (_tagGOPacket*)&buffVec[0];;
			if (conn->HandleCommand(pPacket))
				return 1;
			Comm_OnMsgPacket(This, pPacket);
		}
		break;

	}

	case 7970:
	case 9990:
	case 9992:
	case 9220:
	case 10247:
		break;
	case 7941:
	{
		if (pPacket->size >= 43) {





			char * cBuff = pPacket->data;
			std::vector<char> buffVec(4);
			__int16 ogPacketSize = pPacket->size;
			pPacket->size -= 10;
			buffVec.at(0) = *((unsigned char*)&pPacket->type + 0);
			buffVec.at(1) = *((unsigned char*)&pPacket->type + 1);
			buffVec.at(2) = *((unsigned char*)&pPacket->size + 0);
			buffVec.at(3) = *((unsigned char*)&pPacket->size + 1);
			buffVec.insert(buffVec.begin() + 4, cBuff, cBuff + ogPacketSize);
			buffVec.erase(buffVec.begin() + 25, buffVec.begin() + 35);
			pPacket = (_tagGOPacket*)&buffVec[0];;
			Comm_OnMsgPacket(This, pPacket);
		}
		break;
	}


	default:
		Comm_OnMsgPacket(This, pPacket);
	}
	return 1;
}

long int getTimeStamp()
{
	time_t t = std::time_t(0);
	long int now = static_cast<long int> (t);
	return now / 10000000L;
}
HRESULT(__thiscall* OnCryptPacket)(void * tThis, _tagGOPacket *) = (HRESULT(__thiscall*)(void * tThis, _tagGOPacket *))(0x00418DB0);// (0x00417390) 0x00418DB0
HRESULT __fastcall dOnCryptPacket(void* This, void* notUsed, _tagGOPacket *pPacket)
{
	CMapConnection * conn = (CMapConnection *)This;
	CPlayer * player = (CPlayer*)conn->GetPlayer();


	if (pPacket->type && !conn->GetPlayer()) {

		if (pPacket->type == 57345 || pPacket->type == 57346 || pPacket->type == 57348 || pPacket->type == 53505 || pPacket->type == 40961 || pPacket->type == 40962
			|| pPacket->type == 40963 || pPacket->type == 40964 || pPacket->type == 40965 || pPacket->type == 40966 || pPacket->type == 1281 || pPacket->type == 57351) {

			return OnCryptPacket(This, pPacket);
		}
		else {
			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
			//std::cout << "2- Packet Blocked Non Player! " << pPacket->type << "\n";
			return 0;
		}

	}

	switch (pPacket->type)
	{

	default:
		return OnCryptPacket(This, pPacket);
	}
}



auto CMapConnection__SendChar = (int(__thiscall*)(void * tThis, void * dummy))(0x0047AB40); //(0x0046E6C0) 0x0047AB40
int __fastcall dCMapConnection__SendChar(void* This, void* notUsed, void * dummy)
{
	CMapConnection * conn = (CMapConnection*)This;


	conn->SetBillLogin(conn->GetBillLogin() + 1);
	return CMapConnection__SendChar(This, dummy);


}
HRESULT(__thiscall* OnPlainPacket)(void * tThis, _tagGOPacket *) = (HRESULT(__thiscall*)(void * tThis, _tagGOPacket *))(0x00419230);//(0x00417810) 0x00419230 
HRESULT __fastcall dOnPlainPacket(void* This, void* notUsed, _tagGOPacket *pPacket)
{
	CMapConnection * conn = (CMapConnection*)This;
	CPlayer * player = (CPlayer*)conn->GetPlayer();

	if (pPacket->type && !conn->GetPlayer()) {

		if (pPacket->type == 8193 || pPacket->type == 8194 || pPacket->type == 7937) {
			return OnPlainPacket(This, pPacket);
		}
		else {
			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
			//std::cout << "1- Packet Blocked Non Player! " << pPacket->type << "\n";
			return 0;
		}

	}


	//std::cout << "6- " << pPacket->type << "\n";
	switch (pPacket->type)
	{

	

	case 7939:
	case 7940:
	case 7942:
	case 7943:
	case 7944:
	{
		// std::cout << pPacket->data[21] << " " << pPacket->data[22] << " " << pPacket->data[23] << " " << pPacket->data[24] << " " << pPacket->data[25] << " " << pPacket->data[26] << " " << pPacket->data[27] << " "  << "\n";

		if (pPacket->data[21] == '.' && pPacket->data[22] == 's' && pPacket->data[23] == 't' && pPacket->data[24] == 'a' 
			&& pPacket->data[25] == 'y' && pPacket->data[26] == 'o' && pPacket->data[27] == 'n')
		{ 
			
		
		pPacket->type = 5179;
		pPacket->size = 4;
		
		
		return OnPlainPacket(This, pPacket);
		
		}
		else 
		{
			return OnPlainPacket(This, pPacket);

		}

	}

	case 6217:
	case 6218:
	{

		
		return 0;
	}





	case _MAP_ITEM_PROTOCOL::RCM_MAP_ITEM_UPGRADE:
	case _MAP_ITEM_PROTOCOL::RCM_MAP_COMPOSITION_ITEM:
	case _MAP_ITEM_PROTOCOL::RCM_MAP_COMPOSITION_SETITEM:
	case _MAP_ITEM_PROTOCOL::RCM_MAP_COMPOSITION_SHIELD:
	case _MAP_ITEM_PROTOCOL::RCM_MAP_ITEM_UPGRADE_1:
	case _MAP_ITEM_PROTOCOL::RCM_MAP_COMPOSITION_ITEM_1:
	case _MAP_ITEM_PROTOCOL::RCM_MAP_COMPOSITION_SETITEM_1:
	case _MAP_ITEM_PROTOCOL::RCM_MAP_COMPOSITION_SHIELD_1:
	case _MAP_ITEM_PROTOCOL::RCM_MAP_COMPOSITION_POTION_2:
	case 0x1D29:

	{
		return 1;
	}


	case 5139:
	
	{
		struct PVPBOSS { float x; float y = 2; float z; };
		struct BOSS { float x; float y = 2; float z; };
		BOSS * angle[] = { 0,angle[1],0 };
		
		
		struct _tagRequestMAP_USEPOTION_1
		{
#pragma pack(push,1)
			_tagEpochID2 itemID;
			char nInventory;
			char nSlot;
		};
#pragma pack(pop)

		auto packet = reinterpret_cast<_tagRequestMAP_USEPOTION_1*>(pPacket->data);
		if (!player)
		{
			return -1;
		}


		if (packet->itemID.type == 2818775) {
			EpochItem * checkitemslot = (EpochItem*)player->GetPlayerItemSlotManager()->GetItem(packet->nInventory, packet->nSlot);
			if (checkitemslot && checkitemslot->GetEpochId()->id == packet->itemID.id)
			{

				auto peace = (CBiotic * (__thiscall*)(void*, int nType, int nIRID, void* pos, BOSS * angle[], unsigned int dwGenID, int genpatrolindex, int nLinkIndex, void* pItem, void* parentID, unsigned int dwOwnerID))0x004DD910;
				CBiotic* peace0 = peace((void*)0x007F8A58, 347680, 0, player->GetPos(), angle, 0, 0, 0, 0, 0, 0);
				auto summontimer1 = (void *(__thiscall*)(void*, unsigned int timer))5071744;
				void * summon1 = summontimer1(peace0, 60000);

				return OnPlainPacket(This, pPacket);
			}
		}
			if (packet->itemID.type == 2818776) {
				EpochItem * checkitemslot = (EpochItem*)player->GetPlayerItemSlotManager()->GetItem(packet->nInventory, packet->nSlot);
				if (checkitemslot && checkitemslot->GetEpochId()->id == packet->itemID.id)
				{

					auto peace = (CBiotic * (__thiscall*)(void*, int nType, int nIRID, void* pos, BOSS * angle[], unsigned int dwGenID, int genpatrolindex, int nLinkIndex, void* pItem, void* parentID, unsigned int dwOwnerID))0x004DD910;
					CBiotic* peace0 = peace((void*)0x007F8A58, 375708, 0, player->GetPos(), angle, 0, 0, 0, 0, 0, 0);
					auto summontimer1 = (void *(__thiscall*)(void*, unsigned int timer))5071744;
					void * summon1 = summontimer1(peace0, 60000);

					return OnPlainPacket(This, pPacket);
				}

		}
			return OnPlainPacket(This, pPacket);
	}
	case 5201:
	{
#pragma pack(push,1)
		struct  _tagRequestMAP_EXCHANGEMALL_SENDTOMARKET
		{
			unsigned __int16 nItemTotalCount;
			tagItem items[5];
		};
#pragma pack(pop)

		auto packet = reinterpret_cast<_tagRequestMAP_EXCHANGEMALL_SENDTOMARKET*>(pPacket->data);
		if (!player)
		{
			std::cout << __FUNCTION__ << " " << __LINE__ << std::endl;
			return -1;
		}
		if (packet->nItemTotalCount > 5)
		{
			std::cout << __FUNCTION__ << " " << __LINE__ << std::endl;
			return -1;
		}


		if (packet->nItemTotalCount == 5)
		{

			EpochItem * checkitemslot = (EpochItem*)player->GetPlayerItemSlotManager()->GetItem(packet->items[0].nInventory, packet->items[0].nSlot);
			EpochItem * checkitemslot2 = (EpochItem*)player->GetPlayerItemSlotManager()->GetItem(packet->items[1].nInventory, packet->items[1].nSlot);
			EpochItem * checkitemslot3 = (EpochItem*)player->GetPlayerItemSlotManager()->GetItem(packet->items[2].nInventory, packet->items[2].nSlot);
			EpochItem * checkitemslot4 = (EpochItem*)player->GetPlayerItemSlotManager()->GetItem(packet->items[3].nInventory, packet->items[3].nSlot);
			EpochItem * checkitemslot5 = (EpochItem*)player->GetPlayerItemSlotManager()->GetItem(packet->items[4].nInventory, packet->items[4].nSlot);
			if (checkitemslot5 && checkitemslot4 && checkitemslot3 && checkitemslot2 && checkitemslot && checkitemslot->GetEpochId()->id == packet->items[0].id.id && checkitemslot2->GetEpochId()->id == packet->items[1].id.id && checkitemslot3->GetEpochId()->id == packet->items[2].id.id
				&& checkitemslot4->GetEpochId()->id == packet->items[3].id.id && checkitemslot5->GetEpochId()->id == packet->items[4].id.id) {

				return OnPlainPacket(This, pPacket);
			}
			else
			{
				CURLplusplus client;
				std::string url("http://51.195.142.240/Hackdata.php?hack_kind=em&banned_timer=3600&name=");
				url.append(player->GetName());
				//	string urlx = client.Get(url);

				HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
				SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
				std::cout << "Exchange Mall Hack Blocked 5-> " << conn->GetPlayer()->GetName() << "\n";
				std::string messageString1("[System] : ");
				messageString1 += conn->GetPlayer()->GetName();
				messageString1.append(" Hack Detected, and banned for 1 Hour, Thanks for Testing our system!");
				//	Toolset::SendNoticeMessageAllPlayers(messageString1, GMMESSAGE_TYPE::NOTICE_TEXT);


					/*std::string messageString1(conn->GetPlayer()->GetName());
					messageString1.append(" Your Hack Detected Your account has been banned for 1 hour");
					Toolset::SendNoticeMessage(conn, messageString1, GMMESSAGE_TYPE::NOTICE_TEXT);*/
				return 0;
			}

		}
		else
			if (packet->nItemTotalCount == 4)
			{

				EpochItem * checkitemslot = (EpochItem*)player->GetPlayerItemSlotManager()->GetItem(packet->items[0].nInventory, packet->items[0].nSlot);
				EpochItem * checkitemslot2 = (EpochItem*)player->GetPlayerItemSlotManager()->GetItem(packet->items[1].nInventory, packet->items[1].nSlot);
				EpochItem * checkitemslot3 = (EpochItem*)player->GetPlayerItemSlotManager()->GetItem(packet->items[2].nInventory, packet->items[2].nSlot);
				EpochItem * checkitemslot4 = (EpochItem*)player->GetPlayerItemSlotManager()->GetItem(packet->items[3].nInventory, packet->items[3].nSlot);
				if (checkitemslot4 && checkitemslot3 && checkitemslot2 && checkitemslot && checkitemslot->GetEpochId()->id == packet->items[0].id.id && checkitemslot2->GetEpochId()->id == packet->items[1].id.id && checkitemslot3->GetEpochId()->id == packet->items[2].id.id
					&& checkitemslot4->GetEpochId()->id == packet->items[3].id.id) {

					return OnPlainPacket(This, pPacket);
				}
				else
				{
					CURLplusplus client;
					std::string url("http://51.195.142.240/Hackdata.php?hack_kind=em&banned_timer=3600&name=");
					url.append(player->GetName());
					string urlx = client.Get(url);

					HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
					SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
					//std::cout << "Exchange Mall Hack Blocked 4-> " << conn->GetPlayer()->GetName() << "\n";

					std::string messageString1("[System] : ");
					messageString1 += conn->GetPlayer()->GetName();
					messageString1.append(" Hack Detected, and banned for 1 hour, Thanks for Testing our system!");
					//Toolset::SendNoticeMessageAllPlayers(messageString1, GMMESSAGE_TYPE::NOTICE_TEXT);
					return 0;
				}

			}
			else

				if (packet->nItemTotalCount == 3)
				{

					EpochItem * checkitemslot = (EpochItem*)player->GetPlayerItemSlotManager()->GetItem(packet->items[0].nInventory, packet->items[0].nSlot);
					EpochItem * checkitemslot2 = (EpochItem*)player->GetPlayerItemSlotManager()->GetItem(packet->items[1].nInventory, packet->items[1].nSlot);
					EpochItem * checkitemslot3 = (EpochItem*)player->GetPlayerItemSlotManager()->GetItem(packet->items[2].nInventory, packet->items[2].nSlot);
					if (checkitemslot3 && checkitemslot2 && checkitemslot && checkitemslot->GetEpochId()->id == packet->items[0].id.id && checkitemslot2->GetEpochId()->id == packet->items[1].id.id && checkitemslot3->GetEpochId()->id == packet->items[2].id.id) {

						return OnPlainPacket(This, pPacket);
					}
					else
					{
						CURLplusplus client;
						std::string url("http://51.195.142.240/Hackdata.php?hack_kind=em&banned_timer=3600&name=");
						url.append(player->GetName());
						//string urlx = client.Get(url);
						HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
						SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
						std::cout << "Exchange Mall Hack Blocked 3-> " << conn->GetPlayer()->GetName() << "\n";

						std::string messageString1("[System] : ");
						messageString1 += conn->GetPlayer()->GetName();
						messageString1.append(" Hack Detected, and banned for 1 hour, Thanks for Testing our system!");
						//Toolset::SendNoticeMessageAllPlayers(messageString1, GMMESSAGE_TYPE::NOTICE_TEXT);
						return 0;
					}

				}
				else

					if (packet->nItemTotalCount == 2)
					{

						EpochItem * checkitemslot = (EpochItem*)player->GetPlayerItemSlotManager()->GetItem(packet->items[0].nInventory, packet->items[0].nSlot);
						EpochItem * checkitemslot2 = (EpochItem*)player->GetPlayerItemSlotManager()->GetItem(packet->items[1].nInventory, packet->items[1].nSlot);

						if (checkitemslot2 && checkitemslot && checkitemslot->GetEpochId()->id == packet->items[0].id.id && checkitemslot2->GetEpochId()->id == packet->items[1].id.id) {

							return OnPlainPacket(This, pPacket);
						}
						else
						{
							CURLplusplus client;
							std::string url("http://51.195.142.240/Hackdata.php?hack_kind=em&banned_timer=3600&name=");
							url.append(player->GetName());
							//	string urlx = client.Get(url);

							HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
							SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
							std::cout << "Exchange Mall Hack Blocked 2-> " << conn->GetPlayer()->GetName() << "\n";

							std::string messageString1("[System] : ");
							messageString1 += conn->GetPlayer()->GetName();
							messageString1.append(" Hack Detected, and banned for 1 hour, Thanks for Testing our system!");
							//Toolset::SendNoticeMessageAllPlayers(messageString1, GMMESSAGE_TYPE::NOTICE_TEXT);
							return 0;
						}

					}

					else if (packet->nItemTotalCount == 1)
					{

						EpochItem * checkitemslot = (EpochItem*)player->GetPlayerItemSlotManager()->GetItem(packet->items[0].nInventory, packet->items[0].nSlot);



	

						
						if (checkitemslot && checkitemslot->GetEpochId()->id == packet->items[0].id.id) {

							return OnPlainPacket(This, pPacket);

						}
						else
						{
							CURLplusplus client;
							std::string url("http://51.195.142.240/Hackdata.php?hack_kind=em&banned_timer=3600&name=");
							url.append(player->GetName());
							//	string urlx = client.Get(url);
							HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
							SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
							std::cout << "Exchange Mall Hack Blocked 1-> " << conn->GetPlayer()->GetName() << "\n";

							std::string messageString1("[System] : ");
							messageString1 += conn->GetPlayer()->GetName();
							messageString1.append(" Hack Detected, and banned for 1 hour, Thanks for Testing our system!");
							//	Toolset::SendNoticeMessageAllPlayers(messageString1, GMMESSAGE_TYPE::NOTICE_TEXT);
							return 0;

						}

					}


	}




	case 5148:
	{

		if (!conn->GetPlayer()) {
			return 0;
		}
		int currentLevel = conn->GetPlayer()->GetAbility(Characterability::CA_LEVEL);
		if (currentLevel == 165)
		{
			std::string messageString("Sorry you can't Change your Job on level 115(+50)");
			Toolset::SendNoticeMessage(conn, messageString, GMMESSAGE_TYPE::NOTICE_TEXT);
			return 1;
		}
		else if (currentLevel > 116 && currentLevel < 165)
		{
			std::string messageString("Sorry you can't Change your Job in conqueror level");
			Toolset::SendNoticeMessage(conn, messageString, GMMESSAGE_TYPE::NOTICE_TEXT);
			return 1;
		}
		else
		{
			return OnPlainPacket(This, pPacket);
			//return true;
		}


	}
	case 9500:
	{
		if (!conn->GetPlayer()) {
			return 0;
		}
		else if (((char*)pPacket)[21] != 1)
		{
			CURLplusplus client;
			std::string url("http://51.195.142.240/Hackdata.php?hack_kind=ip&banned_timer=3600&name=");
			url.append(player->GetName());
			string urlx = client.Get(url);
			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
			std::cout << "IP Mall Hack Blocked -> " << conn->GetPlayer()->GetName() << "\n";

			std::string messageString1("[System] : ");
			messageString1 += conn->GetPlayer()->GetName();
			messageString1.append(" Hack Detected, and banned for 1 Hour, Thanks for Testing our system!");
			Toolset::SendNoticeMessageAllPlayers(messageString1, GMMESSAGE_TYPE::NOTICE_TEXT);
			//Toolset::SendToPrison(conn->GetPlayer(), 3600, EBLACKPOINTREASON::BPR_UNKNOWN);
			return 0;
		}
		else if (((char*)pPacket)[21] == 1)
		{
			return OnPlainPacket(This, pPacket);
		}
	}




	case 10250:
	{


		if (!conn->GetPlayer()) {
			return 0;
		}
		else if (((char*)pPacket)[12] != 1)
		{
			CURLplusplus client;
			std::string url("http://51.195.142.240/Hackdata.php?hack_kind=badge&banned_timer=3600&name=");
			url.append(player->GetName());
			string urlx = client.Get(url);
			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
			std::cout << "Badge Mall Hack Blocked -> " << conn->GetPlayer()->GetName() << "\n";

			std::string messageString1("[System] : ");
			messageString1 += conn->GetPlayer()->GetName();
			messageString1.append(" Hack Detected, and banned for 1 Hour, Thanks for Testing our system!");
			Toolset::SendNoticeMessageAllPlayers(messageString1, GMMESSAGE_TYPE::NOTICE_TEXT);
			//Toolset::SendToPrison(conn->GetPlayer(), 3600, EBLACKPOINTREASON::BPR_UNKNOWN);
			return 0;
		}
		else if (((char*)pPacket)[12] == 1)
		{
			//std::cout << "Badge Mall Hack Blocked -> " << conn->GetPlayer()->GetName() << "\n";

			return OnPlainPacket(This, pPacket);
		}
	}



	case 0x1466:
	case 0x146A:
	case 0x1463:
	case 0x1468:
	case 0x1469:
	case 0x122:
	case 0x1B33:
	case 0x1A1A:
	case 0x2110:
	case 0x2111:
	case 0x210F:
	{
		if (conn->GetPlayer()) {
			return  OnPlainPacket(This, pPacket);
		}
		else {
			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
			std::cout << "Crash Attack Blocked Non Player " << "\n";
			return 0;
		}
	}


	case 8973:

		if (conn->GetPlayer()) {

			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
			std::cout << "Crash Attack Blocked From Player -> " << conn->GetPlayer()->GetName() << "\n";
			return 0;
		}
		else
		{
			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
			std::cout << "Crash Attack Blocked Non Player " << "\n";
			return 0;

		}



		//gmnotice
	case 7945:
	case 7946:
	{
		char * cBuff = pPacket->data;
		std::vector<char> buffVec(4);
		__int16 ogPacketSize = pPacket->size;
		pPacket->size -= 10;
		buffVec.at(0) = *((unsigned char*)&pPacket->type + 0);
		buffVec.at(1) = *((unsigned char*)&pPacket->type + 1);
		buffVec.at(2) = *((unsigned char*)&pPacket->size + 0);
		buffVec.at(3) = *((unsigned char*)&pPacket->size + 1);
		buffVec.insert(buffVec.begin() + 4, cBuff, cBuff + ogPacketSize);
		buffVec.erase(buffVec.begin() + 7, buffVec.begin() + 17);
		pPacket = (_tagGOPacket*)&buffVec[0];;
		return OnPlainPacket(This, pPacket);

	}



	case 7429:
		//openkiosk
	{
		if (pPacket->size >= 427) {
			char * cBuff = pPacket->data;
			std::vector<char> buffVec(4);
			__int16 ogPacketSize = pPacket->size;
			pPacket->size -= 10;
			buffVec.at(0) = *((unsigned char*)&pPacket->type + 0);
			buffVec.at(1) = *((unsigned char*)&pPacket->type + 1);
			buffVec.at(2) = *((unsigned char*)&pPacket->size + 0);
			buffVec.at(3) = *((unsigned char*)&pPacket->size + 1);
			buffVec.insert(buffVec.begin() + 4, cBuff, cBuff + ogPacketSize);
			buffVec.erase(buffVec.begin() + 101, buffVec.begin() + 111);
			pPacket = (_tagGOPacket*)&buffVec[0];;
			return OnPlainPacket(This, pPacket);
		}
		else
		{
			return OnPlainPacket(This, pPacket);
		}
	}

	
	case 6691: //6691
		//gametime
	{


		if (conn->GetPlayer()) {

			time_t t = time(NULL);
			tm* timePtr = localtime(&t);
			timePacket tmpckt;
			tmpckt.sec = timePtr->tm_sec;
			tmpckt.min = timePtr->tm_min;
			tmpckt.hour = timePtr->tm_hour;
			tmpckt.day = timePtr->tm_mday;
			tmpckt.month = timePtr->tm_mon;
			tmpckt.year = timePtr->tm_year;
			tmpckt.s1 = 115;
			tmpckt.s2 = 1;
			tmpckt.s3 = 74;
			tmpckt.s4 = 1;





			((GOConnection *)conn)->SendPacket(6691, &tmpckt, sizeof(timePacket));
			//delete timePtr;

			if (conn->GetPlayer()->GetAbility(9999) == 0)
			{

				if (conn->GetPlayer()->GetAbility(Characterability::CA_LEVEL) > 1 || conn->GetBillLogin() > 1)
				{
					//Old Char

					std::string messageString("Welcome Back ");
					messageString.append(conn->GetPlayer()->GetName());
					messageString.append(" To R.O.H.A.N. Goddes Of Destruction");

					std::string messageString1("[System] : ");
					messageString1.append(conn->GetPlayer()->GetName());
					messageString1.append(" Don't Forget for Vote for US to get free reward FP (https://god-rohan.com)");
					Toolset::SendNoticeMessage(conn, messageString, GMMESSAGE_TYPE::NOTICE_BOX);
					Toolset::SendNoticeMessage(conn, messageString1, GMMESSAGE_TYPE::NOTICE_TEXT);

				}
				else
				{


					//New Char

					std::string messageString("Welcome ");
					messageString.append(conn->GetPlayer()->GetName());
					messageString.append(" TO Our Family R.O.H.A.N. Goddes Of Destruction And we hopefully to enjoy with US");

					std::string messageString1("[System] : ");
					messageString1.append(conn->GetPlayer()->GetName());
					messageString1.append(" Welcome to R.O.H.A.N. Goddes Of Destruction you're now in Starting Area Check your Event Inventory for Starting Items!");

					Toolset::SendNoticeMessage(conn, messageString, GMMESSAGE_TYPE::NOTICE_BOX);
					Toolset::SendNoticeMessage(conn, messageString1, GMMESSAGE_TYPE::NOTICE_TEXT);

					int64_t money = conn->GetPlayer()->GetMoney();

					if (money == 0) {
						if (!player) return 0;
						conn->GetPlayer()->AddMoney(5000, 0, 1);

					}

				}
				conn->GetPlayer()->SetAbility(9999, 1);
			}


			return 1;
		}
		else {
			return 0;
		}
	}





	default:
		return  OnPlainPacket(This, pPacket);
	}
}


bool CMapConnection::HandleCommand(_tagGOPacket * pPacket)
{
	CMapConnection * conn = (CMapConnection*)pPacket;

	CPlayer * player = GetPlayer();

	if (!player)
		return true;
	chatPacketNew * chatpck = (chatPacketNew*)pPacket->data;
	if (pPacket->size >= 12 && (pPacket->size == chatpck->chat.nLen + chatpck->chat.nLinkInfoLen + 11))
	{
		if (chatpck->chat.nLen > 0 && chatpck->chat.nLen <= 160)
		{
			std::string chatMssgString((char*)chatpck->chat.szMsg, chatpck->chat.nLen);
			std::istringstream stringStream(chatMssgString);
			std::string commandName;
			stringStream >> commandName;
			PlayerExtensions * extsn = player->GetPlayerExtensions();

			if (commandName == ".getpoint" && player->GetGrade() == 250)
			{
				player->AddIndunPoint(GlobalSettings::gmindunpointadd, 0, 1);
				return true;
			}
			else if (GlobalSettings::advancedHkOn) {
				if (commandName == ".itemfilter" && extsn  && extsn->isVip)
				{



					std::string skiStr;
					std::vector<std::string> arguments;
					while (stringStream >> skiStr)
					{
						arguments.push_back(skiStr.c_str());
					}
					if (arguments.size() == 1)
					{
						if (arguments[0] == "on" && !extsn->isAdvancedHkOn)
						{
							extsn->isAdvancedHkOn = true;
							//AdvancedHK::getInstance().SendNoticeMessage(conn->GetPlayer(), "Item filter turned ON, deletes non max stat items..");
							AdvancedHK::getInstance().SendNoticeMessageGreen(player, "Item filter turned ON, monkey picks up only MAX stat items..", 0);
						}
						else if (arguments[0] == "off" && extsn->isAdvancedHkOn)
						{

							extsn->isAdvancedHkOn = false;
							//AdvancedHK::getInstance().SendNoticeMessage(conn->GetPlayer(), "Item filter turned OFF..");
							AdvancedHK::getInstance().SendNoticeMessageGreen(player, "Item filter turned OFF..", 0);
						}
					}
					return true;
				}
			}


			if (commandName == ".world")
			{

				CPlayer * player = GetPlayer();

				int currentLevel = player->GetAbility(Characterability::CA_LEVEL);
				EnterCriticalSection(GetCriticalSection());
				int64_t money = player->GetMoney();

				if (currentLevel < 50) {
					std::string messageString1("[System] : ");
					messageString1.append(player->GetName());
					messageString1.append(" the minimum level to use world chat is level 50!");
					//Toolset::SendNoticeMessage(conn->GetPlayer, messageString1, GMMESSAGE_TYPE::NOTICE_TEXT);
					AdvancedHK::getInstance().SendNoticeMessageGreen(player, messageString1, 2);

					LeaveCriticalSection(GetCriticalSection());

					return true;
				}
				else


					if (currentLevel < 80) {
						int  worldMessageCost = 500000;
						if (money >= worldMessageCost) { player->SubMoney(worldMessageCost, 0, 1); }
						else { LeaveCriticalSection(GetCriticalSection()); return true; }
					}
					else
						if (currentLevel < 115) {
							int  worldMessageCost = 1000000;
							if (money >= worldMessageCost) { player->SubMoney(worldMessageCost, 0, 1); }
							else { LeaveCriticalSection(GetCriticalSection()); return true; }
						}
						else
							if (currentLevel < 135) {
								int  worldMessageCost = 2500000;
								if (money >= worldMessageCost) { player->SubMoney(worldMessageCost, 0, 1); }
								else { LeaveCriticalSection(GetCriticalSection()); return true; }
							}
							else
								if (currentLevel < 165) {
									int  worldMessageCost = 5000000;
									if (money >= worldMessageCost) { player->SubMoney(worldMessageCost, 0, 1); }
									else { LeaveCriticalSection(GetCriticalSection()); return true; }
								}

				LeaveCriticalSection(GetCriticalSection());

				std::string buff;
				std::string worldMssg = "[World]";
				worldMssg += player->GetName();
				worldMssg += " :";
				while (stringStream >> buff)
				{
					worldMssg += " " + buff;
				}

				Toolset::SendNoticeMessageAllPlayers(worldMssg, GMMESSAGE_TYPE::MESSAGE_TEXT);
				return true;
			}


			int pgrade = player->GetGrade();
			if (commandName == ".summon" && pgrade == 250)
			{

				std::string skiStr;
				std::vector<std::string> arguments;

				while (stringStream >> skiStr)
				{
					arguments.push_back(skiStr.c_str());
				}

				int spawnid;
				int spawntime;
				std::istringstream(arguments[0]) >> spawnid;
				std::istringstream(arguments[1]) >> spawntime;
				int spawntimepermin = spawntime * 1000;


				if (spawnid <= 2147483647 && spawntime <= 2147483647 && spawnid > 0 && spawntime > 0) {
					auto CreateBiotic = (CBiotic *(__thiscall*)(void*, int nType, int nIRID, EpochVector3 *pos, void *Angle, unsigned int dwGenID, int genpatrolindex, int nLinkIndex, void *pItem, void *parentID, unsigned int dwOwnerID))0x004DD910;
					CBiotic * biotic = CreateBiotic((void*)0x007F8A58, spawnid, 0, player->GetPos(), (void*)0x04B827DC, 0, 0, 0, 0, 0, 0);
					if (biotic) {

						auto summontimer = (void *(__thiscall*)(void*, unsigned int timer))5071744;
						void * summon = summontimer(biotic, spawntimepermin);

					}

				}
				return true;
			}

			if (commandName == ".admin" && pgrade == 250)
			{


				std::string buff;
				std::string worldMssg = "[";
				worldMssg += player->GetName();
				worldMssg += "] :";
				while (stringStream >> buff)
				{
					worldMssg += " " + buff;
				}

				Toolset::SendNoticeMessageAllPlayers(worldMssg, GMMESSAGE_TYPE::NOTICE_TEXT);
				return true;
			}

			

			if (commandName == ".noticebox" && pgrade == 250)
			{

				std::string buff;
				std::string worldMssg;

				while (stringStream >> buff)
				{
					worldMssg += " " + buff;
				}

				Toolset::SendNoticeMessageAllPlayers(worldMssg, GMMESSAGE_TYPE::NOTICE_BOX);
				return true;
			}

			if (commandName == ".noticetext" && pgrade == 250)
			{

				std::string buff;
				std::string worldMssg;

				while (stringStream >> buff)
				{
					worldMssg += " " + buff;
				}

				Toolset::SendNoticeMessageAllPlayers(worldMssg, GMMESSAGE_TYPE::NOTICE_TEXT1);
				return true;
			}

			if (commandName == ".green" && pgrade == 250)
			{

				std::string buff;
				std::string worldMssg;

				while (stringStream >> buff)
				{
					worldMssg += " " + buff;
				}

				Toolset::SendNoticeMessageAllPlayers(worldMssg, GMMESSAGE_TYPE::NOTICE_TEXT2);
				return true;
			}



			/*	 if (commandName == ".test")
				 {
					 std::cout << player << " " << GetUserId() << " " << player->GetEpochId()->id << std::endl;
				 }*/


			if (commandName == ".event" && pgrade == 250)
			{

				// std::cout << pgrade << std::endl;

				std::string buff;
				std::string worldMssg = "[Event]:";

				while (stringStream >> buff)
				{
					worldMssg += " " + buff;
				}



				Toolset::SendNoticeMessageAllPlayers(worldMssg, GMMESSAGE_TYPE::MESSAGE_TEXT);
				return true;

			}

		}
	}
	return false;
}

class CMapIndex
{
public:
	static bool  CheckPos(EpochVector3 *pos)
	{
		return pos->x > 0.0 && pos->x < 2097152.0 && pos->y >= 0.0 && pos->z > 0.0 && pos->z < 2097152.0;
	}
	static void GetMapIndex(EpochVector3 *pos, int *i, int *j)
	{
		auto GetMapIndex = (void(__cdecl*)(EpochVector3 *pos, int *i, int *j))0x0066A320;
		return GetMapIndex(pos, i, j);
	}
};
int TeleportFunc(CPlayer * player, EpochVector3 pos, int type)
{
	if (player)
	{
		if (!CMapIndex::CheckPos(&pos))
		{
			return 7;
		}
		if (player->GetAction()->nType == 393236)
		{
			EpochItem * pRidingItem = player->GetRidingItem();
			if (!player->HasDungeonVehicleOn())
			{
				int nX;
				int nY;
				CMapIndex::GetMapIndex(&pos, &nX, &nY);
				CRegionAndRoomManager * regionMgr = CRegionAndRoomManager::GetInstance();
				if (regionMgr->IsInDungeon(nX, nY))
				{
					if (pRidingItem)
						player->UseRidingItem(pRidingItem, 0);
				}
			}
		}
		if (player->GetIRID() <= 0)
		{
			auto SetPosEntity = (void(__thiscall*)(void*, EntityBase *pEntity, EpochVector3 *pos, int bMove, EpochID2 *pTargetID))0x00527890;
			SetPosEntity((void*)0x00B354F8, player, &pos, 0, 0);
			player->BroadcastTeleport(&pos);
		}
		else
		{
			CRegionAndRoomManager * regionMgr = CRegionAndRoomManager::GetInstance();

			if (regionMgr->IsInInstRegion(&pos))
			{
				auto SetPosEntity = (void(__thiscall*)(void*, EntityBase *pEntity, EpochVector3 *pos, int bMove, EpochID2 *pTargetID))0x00527890;
				SetPosEntity((void*)0x00B354F8, player, &pos, 0, 0);
			}
			else
			{
				auto IndunManager__Leave = (void(__thiscall*)(void*, CPlayer *pPlayer, EpochVector3 goalPos, bool bMoveWorld))0x00621360;
				IndunManager__Leave((void*)0x04BE3F88, player, pos, 1);

			}
		}
#pragma pack(push,1)
		struct  _tagResponseMAP_TELEPORT
		{
			char nResult;
			char nType;
			EpochVector3 pos;
		};
#pragma pack(pop)

		_tagResponseMAP_TELEPORT rcres = { 0 };
		rcres.nResult = 0;
		rcres.nType = type;
		rcres.pos = pos;
		player->GetConnection()->SendPacketEx(32770u, &rcres, sizeof(_tagResponseMAP_TELEPORT));
		return 0;

	}
	return -1;
}
#pragma pack(push,1)
struct _tagRequestMAP_TELEPORT {
	EpochVector3 pos;                                     // _tagEpochVector3 pos;
	char type;                                               // char nType;
	int bind;                                                // int nBind;
	int portal;                                              // int nPortal;
};

#pragma pack(pop)
enum ETELEPORTTYPE
{
	TT_BINDPOSITION = 0x0,
	TT_PKRECALL = 0x1,
	TT_GATE = 0x2,
	TT_FREEBATTLEZONE_IN = 0x3,
	TT_FREEBATTLEZONE_OUT = 0x4,
	TT_FISHINGPLACE_IN = 0x5,
	TT_FISHINGPLACE_OUT = 0x6,
	TT_STADIUM_IN = 0x7,
	TT_STADIUM_OUT = 0x8,
	TT_PRISON_OUT = 0x9,
	TT_UNITED_DUNGEON_IN = 0xA,
	TT_UNITED_DUNGEON_OUT = 0xB,
	TT_GUILDWARAREA_IN = 0xC,
	TT_GUILDWARAREA_OUT = 0xD,
	TT_SKILL_TELEPORT = 0xE,
	TT_MEETPLACE_TELEPORT = 0xF,
	TT_WATERTEMPLE_IN = 0x10,
	TT_WEDDING_HALL_IN = 0x11,
	TT_WEDDING_HALL_OUT = 0x12,
	TT_PARTYMACHING = 0x13,
	TT_GUILDWARAREA_OBSERVERMODE_IN = 0x14,
	TT_GUILDWARAREA_OBSERVERMODE_OUT = 0x15,
	TT_TUTORIALZONE_IN = 0x16,
	TT_TUTORIALZONE_OUT = 0x17,
	TT_ENTERANCE_QUEST_CHECK = 0x18,
	TT_PRIVATESHOP = 0x19,
	TT_THEME_PARK_IN = 0x1A,
	TT_THEME_PARK_OUT = 0x1B,
	TT_FIRETEMPLE_LAMP_OUT = 0x1C,
	TT_FIRETEMPLE_GORI_OUT = 0x1D,
	TT_FIRETEMPLE_KASA_OUT = 0x1E,
	TT_REFINE_IN = 0x1F,
	TT_LONELYA_IN = 0x20,
	TT_LONELYA_ZONE_IN = 0x21,
	TT_COLOSSEUM_IN = 0x22,
	TT_COLOSSEUM_OUT = 0x23,
	TT_FIRETEMPLE_IN = 0x24,
	TT_GRAT_IN = 0x25,
	TT_GRAT_OUT = 0x26,
	TT_FIRETEMPLE_OUT = 0x27,
	TT_WATERTEMPLE_OUT = 0x28,
	TT_PARTY_RECALL = 0x29,
	TT_TOWNINVASION_IN = 0x2A,
	TT_TOWNINVASION_OUT = 0x2B,
	TT_ARENA_IN = 0x2C,
	TT_ARENA_OUT = 0x2D,
	TT_GRAT2F_UP = 0x2E,
	TT_GRAT2F_DOWN = 0x2F,
	TT_TELEPORT_SCROLL = 0x30,
	TT_PVPARENA_IN = 0x31,
	TT_PVPARENA_OUT = 0x32,
	TT_GOLDENCASTLE_IN = 0x33,
	TT_GRAT_TREASURE_IN = 0x34,
	TT_ELEMENTAL_GARDEN_IN = 0x35,
	TT_VIP_DUNGION_IN = 0x36,
	TT_VIP_BOSS_IN = 0x37,
	TT_LAUKE_IN = 0x38,
	TT_LAUKE_OUT = 0x39,
	TT_MIRROR_DEMONS_CAVE_IN = 0x3A,
	TT_MIRROR_DEMONS_CAVE_OUT = 0x3B,
	TT_MIRROR_WATERTEMPLE_IN = 0x3C,
	TT_MIRROR_WATERTEMPLE_OUT = 0x3D,
	TT_MIRROR_CRISTAL_FIRST_IN = 0x3E,
	TT_MIRROR_CRISTAL_FIRST_OUT = 0x3F,
	TT_MIRROR_CRISTAL_SECOND_IN = 0x40,
	TT_MIRROR_CRISTAL_SECOND_OUT = 0x41,
	TT_MAX_NUM = 0x42,
};
auto CMapConnection__OnTeleport = (int(__thiscall*)(void * tThis, _tagRequestMAP_TELEPORT *prcreq))(0x0043B410);
int __fastcall dCMapConnection__OnTeleport(void* This, void* notUsed, _tagRequestMAP_TELEPORT *prcreq)
{
	//std::cout << "Bind : " << prcreq->bind << " Portal; " << prcreq->portal << " type: " << (int*)prcreq->type << std::endl;


	CMapConnection * conn = (CMapConnection*)This;
	CPlayer * player = conn->GetPlayer();
	switch (prcreq->type)
	{
	case ETELEPORTTYPE::TT_VIP_DUNGION_IN:
	case ETELEPORTTYPE::TT_VIP_BOSS_IN:
	case ETELEPORTTYPE::TT_LAUKE_IN:
	case ETELEPORTTYPE::TT_LAUKE_OUT:
	case ETELEPORTTYPE::TT_MIRROR_DEMONS_CAVE_IN:
	case ETELEPORTTYPE::TT_MIRROR_DEMONS_CAVE_OUT:
	case ETELEPORTTYPE::TT_MIRROR_WATERTEMPLE_IN:
	case ETELEPORTTYPE::TT_MIRROR_WATERTEMPLE_OUT:
	case ETELEPORTTYPE::TT_MIRROR_CRISTAL_FIRST_IN:
	case ETELEPORTTYPE::TT_MIRROR_CRISTAL_FIRST_OUT:
	case ETELEPORTTYPE::TT_MIRROR_CRISTAL_SECOND_IN:
	case ETELEPORTTYPE::TT_MIRROR_CRISTAL_SECOND_OUT:
	case ETELEPORTTYPE::TT_MEETPLACE_TELEPORT:
	case ETELEPORTTYPE::TT_COLOSSEUM_IN:
	case ETELEPORTTYPE::TT_COLOSSEUM_OUT:
	case ETELEPORTTYPE::TT_WEDDING_HALL_IN:
	case ETELEPORTTYPE::TT_WEDDING_HALL_OUT:
	case 2:
	{
			return TeleportFunc(player, prcreq->pos, prcreq->type);
	}

	case 0:
	{
		if (prcreq->bind == 0) {
			return TeleportFunc(player, prcreq->pos, prcreq->type);
		}
		else
		{
			return CMapConnection__OnTeleport(This, prcreq);
		}
	}

	default:
	
		return CMapConnection__OnTeleport(This, prcreq);
	}
}


auto OnMiniGamePacket = (HRESULT(__thiscall*)(void * tThis, _tagGOPacket *pPacket))(0x0047DCB0);
HRESULT __fastcall dOnMiniGamePacket(void* This, void* notUsed, _tagGOPacket *pPacket)
{
	if (pPacket->type >= 771 && pPacket->type <= 778)
		return 0;
	else
		return OnMiniGamePacket(This, pPacket);
}



void CMapConnectionHooks(HMODULE hModule)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
	std::cout << "\n## CMAPCONNETION HOOKS HERO4 ##" << std::endl;
	DisableThreadLibraryCalls(hModule);
	DetourTransactionBegin();
	DetourUpdateThread(GetCurrentThread());
	DetourAttach(&(PVOID&)SendPacketEx, dSendPacketEx);
	DetourAttach(&(PVOID&)OnPlainPacket, dOnPlainPacket);
	DetourAttach(&(PVOID&)Comm_OnMsgPacket, dComm_OnMsgPacket);
	DetourAttach(&(PVOID&)OnCryptPacket, dOnCryptPacket);
	DetourAttach(&(PVOID&)CMapConnection__SendChar, dCMapConnection__SendChar);
	DetourAttach(&(PVOID&)CMapConnection__OnTeleport, dCMapConnection__OnTeleport);

	DetourAttach(&(PVOID&)OnMiniGamePacket, dOnMiniGamePacket);
	DetourTransactionCommit();

}