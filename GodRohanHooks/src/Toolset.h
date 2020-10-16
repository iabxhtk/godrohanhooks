#pragma once
#include "CMapConnection.h"
class Toolset
{
public:
	Toolset();
	~Toolset();
	static void SendNoticeMessageAllPlayers(std::string messageString, char type);
	static void SendNoticeMessageAllPlayers(std::string messageString, char type, int protocol);
	static void SendNoticeMessage(RohanConnection * conn, std::string messageString, char type);
	static void SendNoticeMessagelv(RohanConnection * conn, std::string messageStringg, char type);
	static void SendNoticeMessageWorld(std::string messageStringworld, char type);
	static void SendToPrison(CPlayer * player, int time, char reason);
	static char * DynamicCast(void *inptr, int VfDelta, void *SrcType, void *TargetType, int isReference)
	{
		auto ___RTDynamicCast = (char *(__cdecl*)(void *inptr, int VfDelta, void *SrcType, void *TargetType, int isReference))0x00753FAB;//(0x006F3BEB) 0x00753FAB
		return ___RTDynamicCast(inptr, VfDelta, SrcType, TargetType, isReference);
	}


};

