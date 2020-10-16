#pragma once
#include "VipManager.h"
class PlayerExtensions
{

public:
	CPlayer * player;
	bool isAdvancedHkOn = false;
	bool isVip = false;
	PlayerExtensions(CPlayer * player);
	~PlayerExtensions();
};

