#pragma once
#include <unordered_set>
#include <mutex>
#include "SqlConnection.h"
#include <chrono>
class VipManager
{
private:
	std::mutex setMutex;
	std::unordered_set<int> vipUsers;
	SqlConnection sqlConn;
public:
	VipManager();
	bool InsertUser(int id);
	void ClearUsers();
	bool isVipUser(int userId);
	void CheckOldUsers(std::vector<int>& ids);
	void LoadVips();

	void ReloadVipsWorker();
	

	void StartReloadThread();
	
	static VipManager & getInstance()
	{
		static VipManager singleton;
		return singleton;
	}
};