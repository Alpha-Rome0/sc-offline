#pragma once
#include "common.h"

extern bool g_hooksInstalled;

void InstallHooks();
void LogHooks();
bool HookFunction(uint8_t* target, size_t stolen, void* detour, void** original);
uint8_t* NearData(size_t n);
bool MakeCryString(void* out, const char* s);
void FreeCryString(void* s);
const char* RequestShipFromAtc(uint64_t atcEntity, uint64_t player, const char* shipClass);

// The selected offline ASOP ships (asop_ships.txt, listed as entitlements). The ship behind a CSCURN's
// 16-byte id (URN +0x10; either qword, either byte order): its index, or -1. Any thread.
int FleetShipIndexOfUrnId(const uint64_t id[2]);
const char* FleetShipClass(int index);   // its class name, or nullptr

// Which ship classes an ASOP terminal lists. The Vehicles tab's checkboxes are the source;
// data\asop_ships.txt keeps them, and ASOP reloads that file for each entitlement-list request.
// Nothing is checked until you check one. Any thread.
bool Fleet_AsopListed(const char* name);
int  Fleet_AsopListedCount();
void Fleet_SetAsopListed(const char* name, bool on);
void Fleet_ReplaceAsopListed(const char* const* names, int count);   // the whole checked set
void Fleet_ClearAsopListed();
