#include "stdafx.h"
#include "PlayerExtensions.h"


PlayerExtensions::PlayerExtensions(CPlayer * player)
{
	this->player = player;
	if (VipManager::getInstance().isVipUser(player->GetUserId()))
		isVip = true;
}


PlayerExtensions::~PlayerExtensions()
{
}
