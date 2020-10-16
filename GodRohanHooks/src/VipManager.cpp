#include "stdafx.h"
#include "VipManager.h"
#include "AdvancedHK.h"
#include "Toolset.h"
#include "player.h"
#include "Toolset.h"
#include "CURLplusplus.h"

VipManager::VipManager()
{
	sqlConn.Connect();
}
bool VipManager::InsertUser(int id)
{	
	std::lock_guard<std::mutex> guard(setMutex);
	std::pair<std::unordered_set<int>::iterator, bool> ret = vipUsers.insert(id);
	if (ret.second == true)
		return true;
	return false;
}
void VipManager::ClearUsers()
{
	std::lock_guard<std::mutex> guard(setMutex);
	vipUsers.clear();
}
bool VipManager::isVipUser(int userId)
{
	std::lock_guard<std::mutex> guard(setMutex);
	auto  it = vipUsers.find(userId);
	if (it != vipUsers.end())
		return true;
	return false;
}
void VipManager::CheckOldUsers(std::vector<int> & ids)
{
	std::lock_guard<std::mutex> guard(setMutex);
	for each (auto &  var in vipUsers)
	{
		if (std::find(ids.begin(), ids.end(), var) == ids.end())
		{
			CMapConnection * conn = CMapConnection::GetUserConnection(var);
			if (conn && conn->GetPlayer() && conn->GetPlayer()->GetPlayerExtensions())
				conn->GetPlayer()->GetPlayerExtensions()->isVip = false;
		}
	}
}


void VipManager::LoadVips()
{


	std::vector<int> vipIds = sqlConn.GetVipUserList();
	for (int i = 0; i < vipIds.size(); i++)
	{
		if (InsertUser(vipIds.at(i)))
		{


			CMapConnection * conn = CMapConnection::GetUserConnection(vipIds.at(i));
			if (conn && conn->GetPlayer() && conn->GetPlayer()->GetPlayerExtensions())
				conn->GetPlayer()->GetPlayerExtensions()->isVip = true;
		}
	}
}


void VipManager::ReloadVipsWorker()
{


	struct PVPBOSS{float x;float y = 2;float z;};
	struct BOSS { float x; float y = 2; float z; };

	BOSS* angle[] = { 0,angle[1],0 };
	while (true)
	{
		




		//0 min
		std::string messager = ("[Warning] : RMT will cause a Permanent ban for your account!");
		Toolset::SendNoticeMessageAllPlayers(messager, GMMESSAGE_TYPE::NOTICE_TEXT);
		std::this_thread::sleep_for(std::chrono::minutes(30));
	
		
		
		//0:30 hour
		std::string message1r = ("[Warning] : Our Gm's Never Ask your for your Password");
		Toolset::SendNoticeMessageAllPlayers(message1r, GMMESSAGE_TYPE::NOTICE_TEXT);
		//std::this_thread::sleep_for(std::chrono::minutes(30));




		std::string a27 = ("[Event] : After 30 min The PVP Boss Will Attack ");
		Toolset::SendNoticeMessageAllPlayers(a27, GMMESSAGE_TYPE::NOTICE_TEXT);
		std::this_thread::sleep_for(std::chrono::minutes(10));

		std::string a28 = ("[Event] : After 20 min The PVP Boss Will Attack ");
		Toolset::SendNoticeMessageAllPlayers(a28, GMMESSAGE_TYPE::NOTICE_TEXT);
		std::this_thread::sleep_for(std::chrono::minutes(10));

		std::string a29 = ("[Event] : After 10 min The PVP Boss Will Attack ");
		Toolset::SendNoticeMessageAllPlayers(a29, GMMESSAGE_TYPE::NOTICE_TEXT);
		std::this_thread::sleep_for(std::chrono::minutes(5));

		std::string a30 = ("[Event] : After 5 min The PVP Boss Will Attack ");
		Toolset::SendNoticeMessageAllPlayers(a30, GMMESSAGE_TYPE::NOTICE_TEXT);
		std::this_thread::sleep_for(std::chrono::minutes(1));

		std::string a31 = ("[Event] : After 4 min The PVP Boss Will Attack ");
		Toolset::SendNoticeMessageAllPlayers(a31, GMMESSAGE_TYPE::NOTICE_TEXT);
		std::this_thread::sleep_for(std::chrono::minutes(1));

		std::string a32 = ("[Event] : After 3 min The PVP Boss Will Attack ");
		Toolset::SendNoticeMessageAllPlayers(a32, GMMESSAGE_TYPE::NOTICE_TEXT);
		std::this_thread::sleep_for(std::chrono::minutes(1));

		std::string a33 = ("[Event] : After 2 min The PVP Boss Will Attack ");
		Toolset::SendNoticeMessageAllPlayers(a33, GMMESSAGE_TYPE::NOTICE_TEXT);
		std::this_thread::sleep_for(std::chrono::minutes(1));

		std::string a34 = ("[Event] : After 1 min The PVP Boss Will Attack ");
		Toolset::SendNoticeMessageAllPlayers(a34, GMMESSAGE_TYPE::NOTICE_TEXT);
		std::this_thread::sleep_for(std::chrono::seconds(30));

		std::string a35 = ("[Event] : After 30 seconds The PVP Boss Will Attack ");
		Toolset::SendNoticeMessageAllPlayers(a35, GMMESSAGE_TYPE::NOTICE_TEXT);
		std::this_thread::sleep_for(std::chrono::seconds(20));

		std::string a36 = ("[Event] : After 10 seconds The PVP Boss Will Attack ");
		Toolset::SendNoticeMessageAllPlayers(a36, GMMESSAGE_TYPE::NOTICE_TEXT);
		std::this_thread::sleep_for(std::chrono::seconds(5));


		std::string a37 = ("[Event] : After 5 seconds The PVP Boss Will Attack ");
		Toolset::SendNoticeMessageAllPlayers(a37, GMMESSAGE_TYPE::NOTICE_TEXT);
		std::this_thread::sleep_for(std::chrono::seconds(1));


		std::string a38 = ("[Event] : After 4 seconds The PVP Boss Will Attack ");
		Toolset::SendNoticeMessageAllPlayers(a38, GMMESSAGE_TYPE::NOTICE_TEXT);
		std::this_thread::sleep_for(std::chrono::seconds(1));

		std::string a39 = ("[Event] : After 3 seconds The PVP Boss Will Attack ");
		Toolset::SendNoticeMessageAllPlayers(a39, GMMESSAGE_TYPE::NOTICE_TEXT);
		std::this_thread::sleep_for(std::chrono::seconds(1));


		std::string a40 = ("[Event] : After 2 seconds The PVP Boss Will Attack ");
		Toolset::SendNoticeMessageAllPlayers(a40, GMMESSAGE_TYPE::NOTICE_TEXT);
		std::this_thread::sleep_for(std::chrono::seconds(1));

		std::string a41 = ("[Event] : After 1 seconds The PVP Boss Will Attack ");
		Toolset::SendNoticeMessageAllPlayers(a41, GMMESSAGE_TYPE::NOTICE_TEXT);
		std::this_thread::sleep_for(std::chrono::seconds(1));


		auto peace11 = (CBiotic * (__thiscall*)(void*, int nType, int nIRID, void* pos, BOSS * angle[], unsigned int dwGenID, int genpatrolindex, int nLinkIndex, void* pItem, void* parentID, unsigned int dwOwnerID))0x004DD910;
		CBiotic* peace011 = peace11((void*)0x007F8A58, 295168, 0, (void*)0x04B827DC, angle, 0, 0, 0, 0, 0, 0);







		//1 hour
		std::string message2r = ("[Warning] : Never share your account info to anyone");
		Toolset::SendNoticeMessageAllPlayers(message2r, GMMESSAGE_TYPE::NOTICE_TEXT);
		std::this_thread::sleep_for(std::chrono::minutes(30));
		//1:30 hour
		std::string message3r = ("contact our support team in discord for anyhelp");
		Toolset::SendNoticeMessageAllPlayers(message3r, 0);
		std::this_thread::sleep_for(std::chrono::minutes(30));
		//2 hour
		std::string message4r = ("[Warning] : RMT will cause a Permanent ban for your account!");
		Toolset::SendNoticeMessageAllPlayers(message4r, GMMESSAGE_TYPE::NOTICE_TEXT);
		std::this_thread::sleep_for(std::chrono::minutes(30));
		//2:30 hour

		std::string message4r5 = ("[Warning] : Our Gm's Never Ask your for your Password");
		Toolset::SendNoticeMessageAllPlayers(message4r5, GMMESSAGE_TYPE::NOTICE_TEXT);
		std::this_thread::sleep_for(std::chrono::minutes(30));
		//3 hour
		std::string message4r6 = ("[Warning] : Never share your account info to anyone");
		Toolset::SendNoticeMessageAllPlayers(message4r6, GMMESSAGE_TYPE::NOTICE_TEXT);
		std::this_thread::sleep_for(std::chrono::minutes(30));
		//3:30 hour
		std::string message4r7 = ("contact our support team in discord for anyhelp");
		Toolset::SendNoticeMessageAllPlayers(message4r7, 0);
		std::this_thread::sleep_for(std::chrono::minutes(30));
		//4 hour
		std::string message4r8 = ("[Event] : After 2 hours The World Boss Will Attack ");
		Toolset::SendNoticeMessageAllPlayers(message4r8, GMMESSAGE_TYPE::NOTICE_TEXT);
		std::this_thread::sleep_for(std::chrono::minutes(30));
		
		//4:30 hour
		std::string message4r9 = ("[Warning] : RMT will cause a Permanent ban for your account!");
		Toolset::SendNoticeMessageAllPlayers(message4r9, GMMESSAGE_TYPE::NOTICE_TEXT);
		std::this_thread::sleep_for(std::chrono::minutes(30));
		
		//5 Hours
		std::string message4r10 = ("[Event] : After 1 hours The World Boss Will Attack ");
		Toolset::SendNoticeMessageAllPlayers(message4r10, GMMESSAGE_TYPE::NOTICE_TEXT);
		std::this_thread::sleep_for(std::chrono::minutes(2));

		std::string message4r11 = ("[Warning] : RMT will cause a Permanent ban for your account!");
		Toolset::SendNoticeMessageAllPlayers(message4r11, GMMESSAGE_TYPE::NOTICE_TEXT);
		std::this_thread::sleep_for(std::chrono::minutes(28));
		
		//5:30
		std::string message4r12 = ("[Event] : After 30 min The World Boss Will Attack ");
		Toolset::SendNoticeMessageAllPlayers(message4r12, GMMESSAGE_TYPE::NOTICE_TEXT);
		std::this_thread::sleep_for(std::chrono::minutes(10));

		std::string message4r13 = ("[Event] : After 20 min The World Boss Will Attack ");
		Toolset::SendNoticeMessageAllPlayers(message4r13, GMMESSAGE_TYPE::NOTICE_TEXT);
		std::this_thread::sleep_for(std::chrono::minutes(10));

		std::string message4r14 = ("[Event] : After 10 min The World Boss Will Attack ");
		Toolset::SendNoticeMessageAllPlayers(message4r14, GMMESSAGE_TYPE::NOTICE_TEXT);
		std::this_thread::sleep_for(std::chrono::minutes(5));

		std::string message4r15 = ("[Event] : After 5 min The World Boss Will Attack ");
		Toolset::SendNoticeMessageAllPlayers(message4r15, GMMESSAGE_TYPE::NOTICE_TEXT);
		std::this_thread::sleep_for(std::chrono::minutes(1));

		std::string message4r28 = ("[Event] : After 4 min The World Boss Will Attack ");
		Toolset::SendNoticeMessageAllPlayers(message4r28, GMMESSAGE_TYPE::NOTICE_TEXT);
		std::this_thread::sleep_for(std::chrono::minutes(1));

		std::string message4r16 = ("[Event] : After 3 min The World Boss Will Attack ");
		Toolset::SendNoticeMessageAllPlayers(message4r16, GMMESSAGE_TYPE::NOTICE_TEXT);
		std::this_thread::sleep_for(std::chrono::minutes(1));

		std::string message4r17 = ("[Event] : After 2 min The World Boss Will Attack ");
		Toolset::SendNoticeMessageAllPlayers(message4r17, GMMESSAGE_TYPE::NOTICE_TEXT);
		std::this_thread::sleep_for(std::chrono::minutes(1));

		std::string message4r18 = ("[Event] : After 1 min The World Boss Will Attack ");
		Toolset::SendNoticeMessageAllPlayers(message4r18, GMMESSAGE_TYPE::NOTICE_TEXT);
		std::this_thread::sleep_for(std::chrono::seconds(30));

		std::string message4r19 = ("[Event] : After 30 seconds The World Boss Will Attack ");
		Toolset::SendNoticeMessageAllPlayers(message4r19, GMMESSAGE_TYPE::NOTICE_TEXT);
		std::this_thread::sleep_for(std::chrono::seconds(20));

		std::string message4r20 = ("[Event] : After 10 seconds The World Boss Will Attack ");
		Toolset::SendNoticeMessageAllPlayers(message4r20, GMMESSAGE_TYPE::NOTICE_TEXT);
		std::this_thread::sleep_for(std::chrono::seconds(5));


		std::string message4r21 = ("[Event] : After 5 seconds The World Boss Will Attack ");
		Toolset::SendNoticeMessageAllPlayers(message4r21, GMMESSAGE_TYPE::NOTICE_TEXT);
		std::this_thread::sleep_for(std::chrono::seconds(1));


		std::string message4r22 = ("[Event] : After 4 seconds The World Boss Will Attack ");
		Toolset::SendNoticeMessageAllPlayers(message4r22, GMMESSAGE_TYPE::NOTICE_TEXT);
		std::this_thread::sleep_for(std::chrono::seconds(1));

		std::string message4r23 = ("[Event] : After 3 seconds The World Boss Will Attack ");
		Toolset::SendNoticeMessageAllPlayers(message4r23, GMMESSAGE_TYPE::NOTICE_TEXT);
		std::this_thread::sleep_for(std::chrono::seconds(1));


		std::string message4r24 = ("[Event] : After 2 seconds The World Boss Will Attack ");
		Toolset::SendNoticeMessageAllPlayers(message4r24, GMMESSAGE_TYPE::NOTICE_TEXT);
		std::this_thread::sleep_for(std::chrono::seconds(1));


			


		std::string message4r25 = ("[Event] : After 1 seconds The World Boss Will Attack ");
		Toolset::SendNoticeMessageAllPlayers(message4r25, GMMESSAGE_TYPE::NOTICE_TEXT);
		std::this_thread::sleep_for(std::chrono::seconds(1));

		auto peace112 = (CBiotic * (__thiscall*)(void*, int nType, int nIRID, void* pos, BOSS * angle[], unsigned int dwGenID, int genpatrolindex, int nLinkIndex, void* pItem, void* parentID, unsigned int dwOwnerID))0x004DD910;
		CBiotic* peace0113 = peace112((void*)0x007F8A58, 295161, 0, (void*)0x04B827DC, angle, 0, 0, 0, 0, 0, 0);

		//6 hurs



		//0 min
		std::string a1 = ("[Warning] : RMT will cause a Permanent ban for your account!");
		Toolset::SendNoticeMessageAllPlayers(a1, GMMESSAGE_TYPE::NOTICE_TEXT);
		std::this_thread::sleep_for(std::chrono::minutes(30));

		//0:30 hour
		std::string a2 = ("[Warning] : Our Gm's Never Ask your for your Password");
		Toolset::SendNoticeMessageAllPlayers(a2, GMMESSAGE_TYPE::NOTICE_TEXT);
		std::this_thread::sleep_for(std::chrono::minutes(30));
		//1 hour
		std::string a3 = ("[Warning] : Never share your account info to anyone");
		Toolset::SendNoticeMessageAllPlayers(a3, GMMESSAGE_TYPE::NOTICE_TEXT);
		std::this_thread::sleep_for(std::chrono::minutes(30));
		//1:30 hour
		std::string a4 = ("contact our support team in discord for anyhelp");
		Toolset::SendNoticeMessageAllPlayers(a4, 0);
		std::this_thread::sleep_for(std::chrono::minutes(30));
		//2 hour
		std::string a5 = ("[Warning] : RMT will cause a Permanent ban for your account!");
		Toolset::SendNoticeMessageAllPlayers(a5, GMMESSAGE_TYPE::NOTICE_TEXT);
		std::this_thread::sleep_for(std::chrono::minutes(30));
		//2:30 hour

		std::string a6 = ("[Warning] : Our Gm's Never Ask your for your Password");
		Toolset::SendNoticeMessageAllPlayers(a6, GMMESSAGE_TYPE::NOTICE_TEXT);
		std::this_thread::sleep_for(std::chrono::minutes(30));
		//3 hour
		std::string a7 = ("[Warning] : Never share your account info to anyone");
		Toolset::SendNoticeMessageAllPlayers(a7, GMMESSAGE_TYPE::NOTICE_TEXT);
		std::this_thread::sleep_for(std::chrono::minutes(30));
		//3:30 hour
		std::string a8 = ("contact our support team in discord for anyhelp");
		Toolset::SendNoticeMessageAllPlayers(a8, 0);
		std::this_thread::sleep_for(std::chrono::minutes(30));
		//4 hour
		std::string a9 = ("[Event] : After 2 hours The World Boss Will Attack ");
		Toolset::SendNoticeMessageAllPlayers(a9, GMMESSAGE_TYPE::NOTICE_TEXT);
		std::this_thread::sleep_for(std::chrono::minutes(30));

		//4:30 hour
		std::string a10 = ("[Warning] : RMT will cause a Permanent ban for your account!");
		Toolset::SendNoticeMessageAllPlayers(a10, GMMESSAGE_TYPE::NOTICE_TEXT);
		std::this_thread::sleep_for(std::chrono::minutes(30));

		//5 Hours
		std::string a11 = ("[Event] : After 1 hours The World Boss Will Attack ");
		Toolset::SendNoticeMessageAllPlayers(a11, GMMESSAGE_TYPE::NOTICE_TEXT);
		std::this_thread::sleep_for(std::chrono::minutes(2));

		std::string a12 = ("[Warning] : RMT will cause a Permanent ban for your account!");
		Toolset::SendNoticeMessageAllPlayers(a12, GMMESSAGE_TYPE::NOTICE_TEXT);
		std::this_thread::sleep_for(std::chrono::minutes(28));

		//5:30
		std::string a13 = ("[Event] : After 30 min The World Boss Will Attack ");
		Toolset::SendNoticeMessageAllPlayers(a13, GMMESSAGE_TYPE::NOTICE_TEXT);
		std::this_thread::sleep_for(std::chrono::minutes(10));

		std::string a14 = ("[Event] : After 20 min The World Boss Will Attack ");
		Toolset::SendNoticeMessageAllPlayers(a14, GMMESSAGE_TYPE::NOTICE_TEXT);
		std::this_thread::sleep_for(std::chrono::minutes(10));

		std::string a15 = ("[Event] : After 10 min The World Boss Will Attack ");
		Toolset::SendNoticeMessageAllPlayers(a15, GMMESSAGE_TYPE::NOTICE_TEXT);
		std::this_thread::sleep_for(std::chrono::minutes(5));

		std::string a16 = ("[Event] : After 5 min The World Boss Will Attack ");
		Toolset::SendNoticeMessageAllPlayers(a16, GMMESSAGE_TYPE::NOTICE_TEXT);
		std::this_thread::sleep_for(std::chrono::minutes(1));

		std::string a17 = ("[Event] : After 4 min The World Boss Will Attack ");
		Toolset::SendNoticeMessageAllPlayers(a17, GMMESSAGE_TYPE::NOTICE_TEXT);
		std::this_thread::sleep_for(std::chrono::minutes(1));

		std::string a18 = ("[Event] : After 3 min The World Boss Will Attack ");
		Toolset::SendNoticeMessageAllPlayers(a18, GMMESSAGE_TYPE::NOTICE_TEXT);
		std::this_thread::sleep_for(std::chrono::minutes(1));

		std::string a19 = ("[Event] : After 2 min The World Boss Will Attack ");
		Toolset::SendNoticeMessageAllPlayers(a19, GMMESSAGE_TYPE::NOTICE_TEXT);
		std::this_thread::sleep_for(std::chrono::minutes(1));

		std::string a20 = ("[Event] : After 1 min The World Boss Will Attack ");
		Toolset::SendNoticeMessageAllPlayers(a20, GMMESSAGE_TYPE::NOTICE_TEXT);
		std::this_thread::sleep_for(std::chrono::seconds(30));

		std::string a202 = ("[Event] : After 30 seconds The World Boss Will Attack ");
		Toolset::SendNoticeMessageAllPlayers(a202, GMMESSAGE_TYPE::NOTICE_TEXT);
		std::this_thread::sleep_for(std::chrono::seconds(20));

		std::string a21 = ("[Event] : After 10 seconds The World Boss Will Attack ");
		Toolset::SendNoticeMessageAllPlayers(a21, GMMESSAGE_TYPE::NOTICE_TEXT);
		std::this_thread::sleep_for(std::chrono::seconds(5));


		std::string a22 = ("[Event] : After 5 seconds The World Boss Will Attack ");
		Toolset::SendNoticeMessageAllPlayers(a22, GMMESSAGE_TYPE::NOTICE_TEXT);
		std::this_thread::sleep_for(std::chrono::seconds(1));


		std::string a23 = ("[Event] : After 4 seconds The World Boss Will Attack ");
		Toolset::SendNoticeMessageAllPlayers(a23, GMMESSAGE_TYPE::NOTICE_TEXT);
		std::this_thread::sleep_for(std::chrono::seconds(1));

		std::string a24 = ("[Event] : After 3 seconds The World Boss Will Attack ");
		Toolset::SendNoticeMessageAllPlayers(a24, GMMESSAGE_TYPE::NOTICE_TEXT);
		std::this_thread::sleep_for(std::chrono::seconds(1));


		std::string a25 = ("[Event] : After 2 seconds The World Boss Will Attack ");
		Toolset::SendNoticeMessageAllPlayers(a25, GMMESSAGE_TYPE::NOTICE_TEXT);
		std::this_thread::sleep_for(std::chrono::seconds(1));

		std::string a26 = ("[Event] : After 1 seconds The World Boss Will Attack ");
		Toolset::SendNoticeMessageAllPlayers(a26, GMMESSAGE_TYPE::NOTICE_TEXT);
		std::this_thread::sleep_for(std::chrono::seconds(1));

		//6 hurs

		auto peace1131 = (CBiotic *(__thiscall*)(void*, int nType, int nIRID, void * pos, BOSS *angle[], unsigned int dwGenID, int genpatrolindex, int nLinkIndex, void *pItem, void *parentID, unsigned int dwOwnerID))0x004DD910;
		CBiotic * peace0111 = peace1131((void*)0x007F8A58, 295156, 0, (void*)0x04B827DC, angle, 0, 0, 0, 0, 0, 0);



		



		
	//	auto peace = (CBiotic *(__thiscall*)(void*, int nType, int nIRID, void *pos1, void *Angle, unsigned int dwGenID, int genpatrolindex, int nLinkIndex, void *pItem, void *parentID, unsigned int dwOwnerID))0x004DD910;
		//CBiotic * peace0 = peace((void*)0x007F8A58, 295161, 0, (void*)0x04B827DC, (void*)0x04B827DC, 0, 0, 0, 0, 0, 0);
		//auto summontimer1 = (void *(__thiscall*)(void*, unsigned int timer))5071744;
		//void * summon1 = summontimer1(peace0, 3600000);

		




		std::vector<int> vipIds = sqlConn.GetVipUserList();
		CheckOldUsers(vipIds);
		ClearUsers();
		for (int i = 0; i < vipIds.size(); i++)
		{
			if (InsertUser(vipIds.at(i)))
			{


			//	std::cout << "New VIP user added:" << vipIds.at(i) << std::endl;
			
				//AdvancedHK::getInstance().SendNoticeMessageGreen(conn->player->GetPlayerExtensions, "Item filter turned OFF..", 0);
				CMapConnection * conn = CMapConnection::GetUserConnection(vipIds.at(i));
				if (conn && conn->GetPlayer() && conn->GetPlayer()->GetPlayerExtensions())
					conn->GetPlayer()->GetPlayerExtensions()->isVip = true;
			}
		}
	}
}
void VipManager::StartReloadThread()
{
	std::thread r(&VipManager::ReloadVipsWorker, this);
	r.detach();
}