/*
Cheatloverz 2 - Extreme Alien Technology
By Cheatloverz
*/

#pragma once

#include "Hacks.h"

class CEsp : public Hack
{
public:
	void Setup();
	void Draw();
	void Move(CUserCmd *pCmd);
private:

	// Other shit

	struct ESPBox
	{
		int x, y, w, h;
	};

	// Draw a player
	void DrawPlayer(IClientEntity* pEntity, player_info_t pinfo);

	// Get player info
	Color GetPlayerColor(IClientEntity* pEntity);
	bool GetBox(IClientEntity* pEntity, ESPBox &result);
	bool GetPlayerBox(IClientEntity* pEntity, ESPBox &result);


	// Draw shit about player
	void DrawBox(ESPBox size, Color color);
	void DrawName(player_info_t pinfo, ESPBox size);
	void DrawHealth(IClientEntity* pEntity, ESPBox size);
	void DrawInfo(IClientEntity* pEntity, ESPBox size);
	void DrawCross(IClientEntity* pEntity);
	void DrawSkeleton(IClientEntity* pEntity)
};

