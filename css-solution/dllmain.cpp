#include "includes.h"

unsigned long __stdcall mainthread(void* base)
{
	while (!GetModuleHandleA("client.dll") && !GetModuleHandleA("shaderapidx9.dll") && !GetModuleHandleA("engine.dll"))
		std::this_thread::sleep_for(std::chrono::milliseconds(50));


	try {
		console::initialize("floridahook");
		console::log(R"#(
  _____.__               .__    .___      .__                   __    
_/ ____\  |   ___________|__| __| _/____  |  |__   ____   ____ |  | __
\   __\|  |  /  _ \_  __ \  |/ __ |\__  \ |  |  \ /  _ \ /  _ \|  |/ /
 |  |  |  |_(  <_> )  | \/  / /_/ | / __ \|   Y  (  <_> |  <_> )    < 
 |__|  |____/\____/|__|  |__\____ |(____  /___|  /\____/ \____/|__|_ \
                                 \/     \/     \/                   \/
            )#");
		console::log("\n");
		interfaces::initalize();
		hooks::create();
	}
	catch (const std::runtime_error & error) {
		MessageBoxA(nullptr, error.what(), "fatal error", MB_OK | MB_ICONERROR);
		FreeLibraryAndExitThread(static_cast<HMODULE>(base), 0);
	}
	console::log("floridahook for counter-strike:source [steam] initalized\n");

	while (!GetAsyncKeyState(VK_END))
		std::this_thread::sleep_for(std::chrono::milliseconds(50));

	FreeLibraryAndExitThread(static_cast<HMODULE>(base), 0);
}

unsigned long __stdcall detach()
{
	hooks::destroy();
	console::destroy();
	return TRUE;
}

std::int32_t WINAPI DllMain(HMODULE module, DWORD ul_reason_for_call, LPVOID reversed)
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
		//DisableThreadLibraryCalls(module);
		if (auto handle = CreateThread(nullptr, NULL, mainthread, module, NULL, nullptr))
			CloseHandle(handle);
		break;	
	case DLL_PROCESS_DETACH:
		detach();
		break;
    }
    return TRUE;
}

