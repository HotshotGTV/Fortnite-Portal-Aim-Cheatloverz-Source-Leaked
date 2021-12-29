/*
	Cheatloverz 2 - Extreme Alien Technology
	By Cheatloverz
*/

#include "DLLMain.h"
#include "Utilities.h"
#include "Offsets.h"
#include "NetVars.h"
#include "Interfaces.h"
#include "Render.h"
#include "nigger.h"
#include "GUISpecifications.h"






BackEndInfo::define window = "  Fortnite";






void CenteredTextPrint(std::string Text)
{
	std::string NewString;

	CONSOLE_SCREEN_BUFFER_INFO csbi;
	int columns;


	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;

	int TextLength = Text.length();
	int Space = (columns / 2) - (TextLength / 2);

	for (int i = 0; i < Space; i++)
	{
		NewString += " ";
	}

	NewString += Text;

	while (NewString.length() < columns)
	{
		NewString += " ";
	}

	printf("%s\n", NewString.c_str());
}


// -----------------------------------------------------------
// A thread to run all of the setup related stuff of the 
//  entire cheat. Either called from DLLMain or from our export
//
DWORD WINAPI InitThread(LPVOID lpThreadParam)
{
	Utilities::OpenConsole();
	Utilities::SetConsoleColor(BACKGROUND_GREEN | BACKGROUND_INTENSITY);
	CenteredTextPrint("Cheatloverz 2.5");
	Utilities::SetConsoleColor(FOREGROUND_INTENSE_WHITE);
	Utilities::Log("Utilities Library Ready");
	int backend = 1;
	if (backend=1)
	{
		Offsets::Init();
		Interfaces::Initialize();
		NetVars.Initialize();
		Render::Initialise();
		Hooks::Apply();
		Utilities::Log("Ready");
	}

	return 0;
}

// -----------------------------------------------------------
// Allows the loader to supply some information about the user
//
DLL_EXPORT DWORD WINAPI PhoneHome(LoaderInfo* loaderInfo)
{
	// Copy over the loader info
	if (loaderInfo)
	{
		BackEndInfo::g_LoaderInfoSet = true;
		memcpy(&BackEndInfo::g_LoaderInfo, loaderInfo, sizeof(LoaderInfo));
	}
	return 0;
}

// -----------------------------------------------------------
// DLL Entry Point
//
BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)
{
	
	switch (fdwReason)
	{
	case DLL_PROCESS_ATTACH:
		BackEndInfo::g_hModule = hinstDLL;
		BackEndInfo::g_LoaderInfoSet = false;
		break;
	case DLL_PROCESS_DETACH:
		break;
	}

	return TRUE;
}

// -----------------------------------------------------------
// Allows the cheat to access some of the info we aquire from
// the loader and the injection process
//
namespace BackEndInfo
{
	bool g_LoaderInfoSet;
	LoaderInfo g_LoaderInfo;
	HINSTANCE g_hModule;
	bool g_bUnloadModule;
};
