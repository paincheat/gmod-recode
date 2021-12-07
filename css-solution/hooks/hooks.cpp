#include "hooks.h"
#include "../utilities/renderer/render.h"
#include "../utilities/global_vars.h"
#include "../features/visuals/esp/esp.h"
hooks::paint_traverse::fn paint_traverse_original = nullptr;
hooks::create_move::fn create_move_original = nullptr;
hooks::setviewangles::fn setviewangles_original = nullptr;

void hooks::create()
{
	/*
	                   createmove - 23 / 24
	*/


	const auto paint_traverse_target = reinterpret_cast<void*>(get_virtual(interfaces::panel, 41));

	const auto create_move_target = reinterpret_cast<void*>(get_virtual(interfaces::clientmode, 21));

	const auto setviewangles_target = reinterpret_cast<void*>(get_virtual(interfaces::engine, 20));

	MH_Initialize();
	if (MH_CreateHook(paint_traverse_target, &paint_traverse::hook, reinterpret_cast<void**>(&paint_traverse_original)) != MH_OK)
		console::log("paint_traverse failed to create\n");
	else
		console::log("paint_traverse created\n");

	if (MH_CreateHook(setviewangles_target, &setviewangles::hook, reinterpret_cast<void**>(&setviewangles_original)) != MH_OK)
		console::log("setviewangles failed to create\n");
	else
		console::log("setviewangles created\n");

	//if (MH_CreateHook(create_move_target, &create_move::hook, reinterpret_cast<void**>(&create_move_original)) != MH_OK)
	//	console::log("create_move failed to create\n");
	//else
	//	console::log("create_move created\n");

	MH_EnableHook(MH_ALL_HOOKS);

	console::log("hooks created\n\n");

	g_render.create_fonts();

}

void hooks::destroy()
{
	MH_Uninitialize();
	MH_DisableHook(MH_ALL_HOOKS);
}

void __stdcall hooks::paint_traverse::hook(unsigned int panel, bool force_repaint, bool allow_force)
{
	paint_traverse_original(interfaces::panel, panel, force_repaint, allow_force);
	static unsigned int FocusOverlayPanel;
	if (!FocusOverlayPanel)
	{
		auto panel_name = fnv::hash(interfaces::panel->get_panel_name(panel));
		if (panel_name == fnv::hash("FocusOverlayPanel"))
			FocusOverlayPanel = panel;
	}


	if (FocusOverlayPanel == panel)
	{
		interfaces::vgui->push_make_current(panel, false); // that's fix from mine GMOD cheat.
		static float rainbow;
		rainbow += 0.005f;
		if (rainbow > 1.f)
			rainbow = 0.f;
		g_render.text(5.f, 5.f, g_render.event_logger, false, color::from_hsb(rainbow, 1.f, 1.f), "floridahook | trapaholics.xyz");
		if (g::local) {
			g_render.text(5.f, 10.f, g_render.event_logger, false, color(255, 0, 0), std::to_string(g::local->is_alive()).c_str());
			g_render.text(5.f, 25.f, g_render.event_logger, false, color(255, 0, 0), std::to_string(g::local->lifestate()).c_str());
			g_render.text(5.f, 35.f, g_render.event_logger, false, color(255, 0, 0), std::to_string(g::local->health()).c_str());
		}
		g_esp.start();

		interfaces::vgui->pop_make_current(panel);
	}
}

DWORD dwOriginCreateMove;
void __stdcall hooks::create_move::hook(int sequence_number, float input_sample_frametime, bool active) // THAT SHIT DONT WORK 
{
	//static auto oCreateMove = create_move_original;
	//oCreateMove(sequence_number, input_sample_frametime, active);
	//	return oCreateMove;

		DWORD dwEBP;

		//g_pInputVMT.dwGetMethodAddress(21);

		__asm
		{
			PUSH active
			PUSH input_sample_frametime
			PUSH sequence_number
			CALL dwOriginCreateMove
			MOV dwEBP, EBP
		}	PBYTE pSendPacket = (PBYTE)(*(PDWORD)(dwEBP)-0x1);

			bool bSendThisPacket = *pSendPacket;

			//MyMovePacket(sequence_number, bSendThisPacket);

			*pSendPacket = bSendThisPacket;

	//create_move_original(flInputSampleTime, cmd);

	//console::log("nword");s
	//return false;
}

template<typename T> inline T get_BP() {
	__asm mov eax, ebp
}

template<typename T> inline T get_SI() {
	__asm mov eax, esi
}

void __stdcall hooks::setviewangles::hook(vec3_t & angles)
{
	/*        use this shit like createmove
	                                             */

	cusercmd* cmd = get_SI<cusercmd*>();
	unsigned* sequence_number = (*get_BP<unsigned**>() + 2);

	setviewangles_original(angles);
	g::local = interfaces::entitylist->getcliententity(interfaces::engine->GetLocalPlayer());

	if (cmd)
	{
		if (cmd->buttons & IN_JUMP && g::local && !(g::local->flags() & FL_ONGROUND))
			cmd->buttons &= ~IN_JUMP;
	}
}
