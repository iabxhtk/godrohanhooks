#pragma once
#include "Structs.h"
#include <string>
#include <vector>
#include "Monster.h"
#include <chrono>
#include "Scheduler.h"
void SpawnManagerHooks(HMODULE hModule);
struct Tm : std::tm {
	int tm_usecs; // [0, 999999] micros after the sec

	Tm(const int year, const int month, const int mday, const int hour,
		const int min, const int sec, const int usecs, const int isDST = -1)
		: tm_usecs{ usecs } {
		tm_year = year - 1900; // [0, 60] since 1900
		tm_mon = month - 1;    // [0, 11] since Jan
		tm_mday = mday;        // [1, 31]
		tm_hour = hour;        // [0, 23] since midnight
		tm_min = min;          // [0, 59] after the hour
		tm_sec = sec;          // [0, 60] after the min
							   //         allows for 1 positive leap second
		tm_isdst = isDST;      // [-1...] -1 for unknown, 0 for not DST,
							   //         any positive value if DST.
	}

	template <typename Clock_t = std::chrono::system_clock::time_point,
		typename MicroSecond_t = std::chrono::microseconds>
		auto to_time_point() -> typename Clock_t::system_clock::time_point {
		auto time_c = mktime(this);
		return Clock_t::from_time_t(time_c) + MicroSecond_t{ tm_usecs };
	}
	std::chrono::system_clock::time_point getTimePoint() {
		auto time_c = mktime(this);
		return std::chrono::system_clock::from_time_t(time_c) + std::chrono::microseconds{ tm_usecs };
	}
};
struct configEntry
{
	int spawneeId;
	int spawneeType;

	std::chrono::system_clock::time_point spawnTime;
	unsigned int interval;
	EpochVector3  * pos;
	EpochVector3  * angle;
	bool notifySpawn;
	std::string noticeMessage;
	bool notifyKillOpen;
	unsigned int killAfter;
};

/*
class Spawner
{
public:
	Scheduler * spawnScheduler;
	static void loadConfig();
	static void loadFromXls();
	static bool isNotifyId(int id);
	static Biotic * Spawn(int spawneeType, EpochVector3 * pos, EpochVector3 * angle);

	static void  SendNotice(std::string text);

	static std::vector<EpochID2> notifyDeadIds;
	static std::vector<configEntry> entries;
	Spawner();
	~Spawner();
};
*/


