/*
AyyWare 2 - Extreme Alien Technology
By Syn
*/

#include "GameFuncs.h"
#include "NetVars.h"

bool IsBallisticWeapon(void* weapon)
{
	if (weapon == nullptr) return false;
	IClientEntity* weaponEnt = (IClientEntity*)weapon;
	ClientClass* pWeaponClass = weaponEnt->GetClientClass();

	if (pWeaponClass->m_ClassID == (int)FortniteClassID::CKnife || pWeaponClass->m_ClassID == (int)FortniteClassID::CHEGrenade || pWeaponClass->m_ClassID == (int)FortniteClassID::CDecoyGrenade || pWeaponClass->m_ClassID == (int)FortniteClassID::CIncendiaryGrenade || pWeaponClass->m_ClassID == (int)FortniteClassID::CSmokeGrenade || pWeaponClass->m_ClassID == (int)FortniteClassID::CC4)
		return false;
	else
		return true;
}

bool IsPistol(void* weapon)
{
	if (weapon == nullptr) return false;
	IClientEntity* weaponEnt = (IClientEntity*)weapon;
	ClientClass* pWeaponClass = weaponEnt->GetClientClass();

	if (pWeaponClass->m_ClassID == (int)FortniteClassID::CDEagle || pWeaponClass->m_ClassID == (int)FortniteClassID::CWeaponElite || pWeaponClass->m_ClassID == (int)FortniteClassID::CWeaponFiveSeven || pWeaponClass->m_ClassID == (int)FortniteClassID::CWeaponGlock || pWeaponClass->m_ClassID == (int)FortniteClassID::CWeaponHKP2000 || pWeaponClass->m_ClassID == (int)FortniteClassID::CWeaponP250 || pWeaponClass->m_ClassID == (int)FortniteClassID::CWeaponP228 || pWeaponClass->m_ClassID == (int)FortniteClassID::CWeaponTec9 || pWeaponClass->m_ClassID == (int)FortniteClassID::CWeaponUSP)
		return true;
	else
		return false;
}

bool IsSniper(void* weapon)
{
	if (weapon == nullptr) return false;
	IClientEntity* weaponEnt = (IClientEntity*)weapon;
	ClientClass* pWeaponClass = weaponEnt->GetClientClass();

	if (pWeaponClass->m_ClassID == (int)FortniteClassID::CWeaponAWP || pWeaponClass->m_ClassID == (int)FortniteClassID::CWeaponSSG08 || pWeaponClass->m_ClassID == (int)FortniteClassID::CWeaponSCAR20 || pWeaponClass->m_ClassID == (int)FortniteClassID::CWeaponG3SG1)
		return true;
	else
		return false;
}

int GetPlayerCompRank(IClientEntity* pEntity)
{
	static DWORD m_iCompetitiveRanking = NetVars.GetOffset(0x75671F7F);
	static DWORD GameResources = *(DWORD*)(Utilities::Memory::FindPattern("client.dll", (PBYTE)"\x8B\x3D\x00\x00\x00\x00\x85\xFF\x0F\x84\x00\x00\x00\x00\x81\xC7", "xx????xxxx????xx") + 0x2);

	return *(int*)((DWORD)GameResources + m_iCompetitiveRanking + (int)pEntity->GetIndex() * 4);
}

void SayInChat(std::string text)
{
	char buffer[250];
	sprintf_s(buffer, "say \"%s\"", text.c_str());
	Interfaces::Engine->ClientCmd_Unrestricted(buffer);
}

void SetName(std::string name)
{
	NET_SetConVar convar("name", name.c_str());
	Interfaces::Engine->GetNetChannelInfo()->SendNetMsg(convar);
}