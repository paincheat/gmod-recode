#pragma once

#define CLIENT "client.dll"
#define ENGINE "engine.dll"
#define VGUIMAT "vguimatsurface.dll"
#define VGUI2 "vgui2.dll"

#define INRANGE(x,a,b)   (x >= a && x <= b)
#define GET_BYTE( x )    (GET_BITS(x[0]) << 4 | GET_BITS(x[1]))
#define GET_BITS( x )    (INRANGE((x&(~0x20)),'A','F') ? ((x&(~0x20)) - 'A' + 0xa) : (INRANGE(x,'0','9') ? x - '0' : 0))

#include <windows.h>
#include <iostream>
#include <cstdint>
#include <memory>
#include <vector>
#include <thread>
#include <chrono>
#include <array>
#include <fstream>
#include <istream>
#include <unordered_map>
#include <intrin.h>
#include <filesystem>

#include <psapi.h>
#include <iostream>
#include <iomanip>
#include <ctime>
#include <chrono>

#include "utilities/console.h"
#include "utilities/interfaces.h"
#include "css-math/matrix.h"
#include "css-math/vec.h"
#include "css-math/color.h"
#include "hooks/hooks.h"

static uintptr_t findsignature(const char* module, const char* idasignature)
{
	const char* pat = idasignature;
	DWORD firstMatch = 0;
	DWORD rangeStart = (DWORD)GetModuleHandleA(module);
	MODULEINFO miModInfo;
	GetModuleInformation(GetCurrentProcess(), (HMODULE)rangeStart, &miModInfo, sizeof(MODULEINFO));
	DWORD rangeEnd = rangeStart + miModInfo.SizeOfImage;
	for (DWORD pCur = rangeStart; pCur < rangeEnd; pCur++)
	{
		if (!*pat)
			return firstMatch;

		if (*(PBYTE)pat == '\?' || *(BYTE*)pCur == GET_BYTE(pat))
		{
			if (!firstMatch)
				firstMatch = pCur;

			if (!pat[2])
				return firstMatch;

			if (*(PWORD)pat == '\?\?' || *(PBYTE)pat != '\?')
				pat += 3;

			else
				pat += 2;
		}
		else
		{
			pat = idasignature;
			firstMatch = 0;
		}
	}
	MessageBoxA(NULL, std::string("contact support, failed to found signature: ").append(idasignature).c_str(), "floridahook", MB_OK);
}