#pragma once
#include "../interfaces.h"
#include "../../css-math/color.h"
#include "../console.h"

class renderer
{
public:
	DWORD esp_name, esp_info, event_logger;
	void create_fonts();

	void text(int x, int y, DWORD font, bool center, color finalclr, const char* output);
	vec2_t textsize(DWORD font, const char* output);
	void line(int x, int y, int x2, int y2, color finalclr);
	void outlined_rect(int x, int y, int width, int height, color finalclr);
	void filled_rect(int x, int y, int width, int height, color finalclr);
};
extern renderer g_render;