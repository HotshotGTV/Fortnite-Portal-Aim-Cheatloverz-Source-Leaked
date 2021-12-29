/*
Cheatloverz 2 - Extreme Alien Technology
By Cheatloverz
*/

#pragma once

#include "Common.h"

namespace Offsets
{
	namespace VMT
	{
		enum  World
		{
			Levels = 0x140,
			PersistentLevel = 0x30,
			Uworld = 0x1337
		};

		// ADD YOUR OWN OFFSETS.


	};

	namespace SigScans
	{
		extern DWORD dwCalcPlayerView;
		extern DWORD dwSpreadVmt;
		extern DWORD dwGetCSWpnData;
		extern DWORD dwKeyValues_KeyValues;
		extern DWORD dwKeyValues_LoadFromBuffer;
	};

	void Init();
};