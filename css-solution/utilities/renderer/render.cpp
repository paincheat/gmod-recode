#include "render.h"
renderer g_render;

void renderer::create_fonts()
{
	esp_name = interfaces::vgui->font_create();
	esp_info = interfaces::vgui->font_create();
	event_logger = interfaces::vgui->font_create();
	interfaces::vgui->set_font_glyph(esp_name, "Segoe UI Semilight", 13, 400, NULL, NULL, fontflag_antialias | fontflag_dropshadow);
	interfaces::vgui->set_font_glyph(esp_info, "04b03", 8, 400, NULL, NULL, fontflag_outline);
	interfaces::vgui->set_font_glyph(event_logger, "Lucida Console", 10, 500, NULL, NULL, fontflag_dropshadow);

	if (event_logger != NULL)
		console::log("Lucida Console created\n");
	else
		console::log("Segoe UI Semilight failed to create\n");

	if (esp_info != NULL)
		console::log("04b03 created\n");
	else
		console::log("04b03 failed to create\n");

	if (esp_name != NULL)
    	console::log("Segoe UI Semilight created\n");
	else
		console::log("Segoe UI Semilight failed to create\n");

	console::log("fonts initalized\n\n");
}

void renderer::text(int x, int y, DWORD font, bool center, color finalclr, const char* output)
{
	/* this shit fix cyrrilic symbols in text */
	va_list va_alist;
	char buffer[1024];
	va_start(va_alist, output);
	_vsnprintf(buffer, sizeof(buffer), output, va_alist);
	va_end(va_alist);
	wchar_t wbuf[1024];
	MultiByteToWideChar(CP_UTF8, 0, buffer, 256, wbuf, 256);
	int width = 0, height = 0;
	interfaces::vgui->draw_text_font(font);
	//if (center) interfaces::surface->get_text_size(font, wbuf, width, height);
	//interfaces::surface->draw_text_pos(x, y);

	if (center) {
		interfaces::vgui->get_text_size(font, wbuf, width, height);
		interfaces::vgui->draw_text_pos(x - width / 2, y);
	}
	else
		interfaces::vgui->draw_text_pos(x, y);

	interfaces::vgui->set_text_color(finalclr.r, finalclr.g, finalclr.b, finalclr.a);
	interfaces::vgui->draw_render_text(wbuf, wcslen(wbuf));
}

vec2_t renderer::textsize(DWORD font, const char* output)
{
	size_t size = strlen(output);
	auto wide_buffer = std::make_unique<wchar_t[]>(size);
	mbstowcs_s(0, wide_buffer.get(), size, output, size - 1);
	int width, height;
	interfaces::vgui->get_text_size(font, wide_buffer.get(), width, height);
	return vec2_t(width, height);
}

void renderer::line(int x, int y, int x2, int y2, color finalclr)
{
	interfaces::vgui->set_drawing_color(finalclr.r, finalclr.g, finalclr.b, finalclr.a);
	interfaces::vgui->draw_line(x, y, x2, y2);
}

void renderer::outlined_rect(int x, int y, int width, int height, color finalclr)
{
	interfaces::vgui->set_drawing_color(finalclr.r, finalclr.g, finalclr.b, finalclr.a);
	interfaces::vgui->draw_outlined_rect(x, y, width, height);
}

void renderer::filled_rect(int x, int y, int width, int height, color finalclr)
{
	interfaces::vgui->set_drawing_color(finalclr.r, finalclr.g, finalclr.b, finalclr.a);
	interfaces::vgui->draw_filled_rectangle(x, y, width, height);
}