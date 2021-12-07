#pragma once
#include "../includes.h"
#include "../classes/engineclient.h"
#include "../classes/surface.h"
#include "../classes/panel.h"
#include "../classes/cusercmd.h"
#include "../utilities/minhook/minhook.h"
#include "../utilities/fnv.h"

namespace hooks
{
	namespace paint_traverse {
		using fn = void(__thiscall*)(vgi_panel*, unsigned int, bool, bool);
		void __stdcall hook(unsigned int panel, bool force_repaint, bool allow_force);
	}

	namespace create_move {
		using fn = void(__thiscall*)(int, float, bool);
		void __stdcall hook(int sequence_number, float input_sample_frametime, bool active);
	}

	namespace setviewangles {
		using fn = void(__stdcall*)(vec3_t&);
		void __stdcall hook(vec3_t& angles);
	}

	void create();
	void destroy();

	inline unsigned int get_virtual(void* _class, unsigned int index) { return static_cast<unsigned int>((*static_cast<int**>(_class))[index]); }
};