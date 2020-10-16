#include "stdafx.h"
#include "Toolset.h"
#include "EntityManager.h"
#include "MapEnums.h"


Toolset::Toolset()
{
}

Toolset::~Toolset()
{
}

void Toolset::SendNoticeMessageAllPlayers(std::string messageString, char type)
{
	if (messageString.length() > 0 && messageString.length() < 256)
	{
		tagRequestCOMMGMNOTICE noticePacket;
		memset(noticePacket.msg, 0, 256);
		strncpy(noticePacket.msg, messageString.c_str(), messageString.length());
		noticePacket.gmMsgType = type;
		noticePacket.size = 3 + messageString.length();
		noticePacket.len = messageString.length();

		_tagGOPacket* packet = (_tagGOPacket*)&noticePacket;
		CEntityManager * entityMgr = (CEntityManager*)0x007F8A60;
		entityMgr->BroadcastAllPlayer(7946, (void*)packet->data, packet->size);
		entityMgr->BroadcastAllPlayer(7968, (void*)packet->data, packet->size);
		entityMgr->BroadcastAllPlayer(7945, (void*)packet->data, packet->size);


	}
}









void Toolset::SendNoticeMessageAllPlayers(std::string messageString, char type, int protocol)
{
	if (messageString.length() > 0 && messageString.length() < 256)
	{
		tagRequestCOMMGMNOTICE noticePacket;
		memset(noticePacket.msg, 0, 256);
		strncpy(noticePacket.msg, messageString.c_str(), messageString.length());
		noticePacket.gmMsgType = type;
		noticePacket.size = 3 + messageString.length();
		noticePacket.len = messageString.length();

		_tagGOPacket* packet = (_tagGOPacket*)&noticePacket;
		CEntityManager * entityMgr = (CEntityManager*)0x007F8A60;
		entityMgr->BroadcastAllPlayer(protocol, (void*)packet->data, packet->size);
	}
}
void Toolset::SendNoticeMessage(RohanConnection * conn, std::string messageString, char type)
{
	if (conn && messageString.length() > 0 && messageString.length() < 256)
	{
		tagRequestCOMMGMNOTICE noticePacket;
		memset(noticePacket.msg, 0, 256);
		strncpy(noticePacket.msg, messageString.c_str(), messageString.length());
		noticePacket.gmMsgType = type;
		noticePacket.size = 3 + messageString.length();
		noticePacket.len = messageString.length();

		_tagGOPacket* packet = (_tagGOPacket*)&noticePacket;
		conn->SendPacketEx(7946, (void*)packet->data, packet->size);
		conn->SendPacketEx(7945, (void*)packet->data, packet->size);
		conn->SendPacketEx(7947, (void*)packet->data, packet->size);
	}

}
void Toolset::SendNoticeMessagelv(RohanConnection * conn, std::string messageStringg, char type)
{
	if (conn && messageStringg.length() > 0 && messageStringg.length() < 256)
	{
		tagRequestCOMMGMNOTICE noticePacket;
		memset(noticePacket.msg, 0, 256);
		strncpy(noticePacket.msg, messageStringg.c_str(), messageStringg.length());
		noticePacket.gmMsgType = type;
		noticePacket.size = 3 + messageStringg.length();
		noticePacket.len = messageStringg.length();

		_tagGOPacket* packet = (_tagGOPacket*)&noticePacket;
		conn->SendPacketEx(7946, (void*)packet->data, packet->size);
		conn->SendPacketEx(7945, (void*)packet->data, packet->size);
		conn->SendPacketEx(7965, (void*)packet->data, packet->size);

	}

}

void Toolset::SendNoticeMessageWorld(std::string messageStringworld, char type)
{
	if (messageStringworld.length() > 0 && messageStringworld.length() < 256)
	{
		tagRequestCOMMGMNOTICE noticePacket;
		memset(noticePacket.msg, 0, 256);
		strncpy(noticePacket.msg, messageStringworld.c_str(), messageStringworld.length());
		noticePacket.gmMsgType = type;
		noticePacket.size = 3 + messageStringworld.length();
		noticePacket.len = messageStringworld.length();

		_tagGOPacket* packet = (_tagGOPacket*)&noticePacket;
		CEntityManager * entityMgr = (CEntityManager*)0x007F8A60;
		entityMgr->BroadcastAllPlayer(7965, (void*)packet->data, packet->size);




	}
}

void Toolset::SendToPrison(CPlayer * player, int time, char reason)
{
	

	if (!player)
	{
		std::cout << "Player null \n";
		return;
	}
	CCrime * crime = player->GetCCrime();
	if (crime)
	{
		crime->GotoPrison(time, reason);
	}
}





