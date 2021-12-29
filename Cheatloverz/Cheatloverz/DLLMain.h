/*
Cheatloverz 2 - Extreme Alien Technology
By Cheatloverz
*/

#pragma once

#include "Common.h"
#include "LoaderInfo.h"

// Macro to make stuff a little easier
#define DLL_EXPORT extern "C" __declspec(dllexport)


namespace BackEndInfo
{
	extern bool g_LoaderInfoSet;
	extern LoaderInfo g_LoaderInfo;
	extern HINSTANCE g_hModule;
	typedef bool define;
	extern bool g_bUnloadModule;
};
