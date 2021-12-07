#pragma once
#include "../css-math/matrix.h"
#include "../css-math/vec.h"
#include "../css-math/color.h"

enum font_flags {
	fontflag_none,
	fontflag_italic = 0x001,
	fontflag_underline = 0x002,
	fontflag_strikeout = 0x004,
	fontflag_symbol = 0x008,
	fontflag_antialias = 0x010,
	fontflag_gaussianblur = 0x020,
	fontflag_rotary = 0x040,
	fontflag_dropshadow = 0x080,
	fontflag_additive = 0x100,
	fontflag_outline = 0x200,
	fontflag_custom = 0x400,
	fontflag_bitmap = 0x800,
};

struct vertex_t {
	vertex_t() {}
	vertex_t(const vec2_t& pos, const vec2_t& coord = vec2_t(0, 0)) {
		position = pos;
		tex_coord = coord;
	}
	void initialize(const vec2_t& pos, const vec2_t& coord = vec2_t(0, 0)) {
		position = pos;
		tex_coord = coord;
	}

	vec2_t	position;
	vec2_t	tex_coord;
};

class surface
{
public:
	void set_drawing_color(int r, int g, int b, int a = 255) {
		using original_fn = void(__thiscall*)(surface*, int, int, int, int);
		return (*(original_fn * *)this)[11](this, r, g, b, a);
	}

	void play_sound(const char* sound_path) {
		using original_fn = void(__thiscall*)(surface*, const char*);
		return (*(original_fn * *)this)[77](this, sound_path);
	}

	void set_text_color(int r, int g, int b, int a = 255) {
		using original_fn = void(__thiscall*)(surface*, int, int, int, int);
		return (*(original_fn * *)this)[19](this, r, g, b, a);
	}

	void draw_polygon(int n, vertex_t* vertice, bool clip_vertices = true) {
		using original_fn = void(__thiscall*)(surface*, int, vertex_t*, bool);
		return (*(original_fn * *)this)[101](this, n, vertice, clip_vertices);
	}
	void draw_filled_rectangle(int x, int y, int w, int h) {
		using original_fn = void(__thiscall*)(surface*, int, int, int, int);
		return (*(original_fn * *)this)[11](this, x, y, x + w, y + h);
	}
	void set_texture(int id) {
		using original_fn = void(__thiscall*)(surface*, int);
		return (*(original_fn * *)this)[33](this, id);
	}
	inline void draw_textured_rectangle(int x, int y, int w, int h) {
		typedef void(__thiscall * original_fn)(void*, int, int, int, int);
		return (*(original_fn * *)this)[36](this, x, y, w, h);
	}
	void set_texture_rgba(int id, const unsigned char* rgba, int wide, int tall) {
		using original_fn = void(__thiscall*)(surface*, int, const unsigned char*, int, int);
		return (*(original_fn * *)this)[32](this, id, rgba, wide, tall);
	}
	int create_new_texture_id(bool procedural = false) {
		using original_fn = int(__thiscall*)(surface*, bool);
		return (*(original_fn * *)this)[38](this, procedural);
	}
	void draw_outlined_rect(int x, int y, int w, int h) {
		using original_fn = void(__thiscall*)(surface*, int, int, int, int);
		return (*(original_fn * *)this)[12](this, x, y, x + w, y + h);
	}
	void draw_line(int x1, int y1, int x2, int y2) {
		using original_fn = void(__thiscall*)(surface*, int, int, int, int);
		return (*(original_fn * *)this)[14](this, x1, y1, x2, y2);
	}
	void draw_text_font(unsigned long font) {
		using original_fn = void(__thiscall*)(surface*, unsigned long);
		return (*(original_fn * *)this)[17](this, font);
	}
	void push_make_current(unsigned int panel, bool useInsets) {
		typedef void(__thiscall* original_fn)(PVOID, unsigned int, bool);
		return (*(original_fn * *)this)[8](this, panel, useInsets);
	}
	void pop_make_current(unsigned int panel) {
		typedef void(__thiscall* original_fn)(PVOID, unsigned int);
		return (*(original_fn * *)this)[9](this, panel);
	}
	void draw_text_pos(int x, int y) {
		using original_fn = void(__thiscall*)(surface*, int, int);
		return (*(original_fn * *)this)[20](this, x, y);
	}
	void draw_render_text(const wchar_t* text, int textLen) {
		using original_fn = void(__thiscall*)(surface*, const wchar_t*, int, int);
		return (*(original_fn * *)this)[22](this, text, textLen, 0);
	}
	unsigned long font_create() {
		using original_fn = unsigned int(__thiscall*)(surface*);
		return (*(original_fn * *)this)[66](this);
	}
	void set_font_glyph(unsigned long font, const char* windowsFontName, int tall, int weight, int blur, int scanlines, int flags) {
		using original_fn = void(__thiscall*)(surface*, unsigned long, const char*, int, int, int, int, int, int, int);
		return (*(original_fn * *)this)[67](this, font, windowsFontName, tall, weight, blur, scanlines, flags, 0, 0);
	}
	void get_text_size(unsigned long font, const wchar_t* text, int& wide, int& tall) {
		using original_fn = void(__thiscall*)(surface*, unsigned long, const wchar_t*, int&, int&);
		return (*(original_fn * *)this)[74](this, font, text, wide, tall);
	}
	void unlock_cursor() {
		using original_fn = void(__thiscall*)(surface*);
		return (*(original_fn * *)this)[61](this);
	}

	void set_clip_rect(int x, int y, int w, int h) {
		using original_fn = void(__thiscall*)(surface*, int, int, int, int);
		return (*(original_fn * *)this)[142](this, x, y, w, h);
	}

	void draw_filled_rect_fade(int x, int y, int w, int h, unsigned int alpha1, unsigned int alpha2, bool is_horizontal) {
		using original_fn = void(__thiscall*)(surface*, int, int, int, int, unsigned int, unsigned int, bool);
		return (*(original_fn * *)this)[118](this, x, y, w, h, alpha1, alpha2, is_horizontal);
	}

	void draw_colored_text(unsigned long font, int x, int y, int red, int green, int blue, int alpha, const char* text) {
		using original_fn = void(__thiscall*)(surface*, unsigned long, int, int, int, int, int, int, const char*);
		return (*(original_fn * *)this)[158](this, font, x, y, red, green, blue, alpha, text);
	}

	void get_screen_size(int& width, int& height) {
		using original_fn = void(__thiscall*)(surface*, int&, int&);
		return (*(original_fn * *)this)[39](this, std::ref(width), std::ref(height));  //width, height
	}

	void draw_textured_polygon(int vertex_count, vertex_t* vertex, bool clip_vertices = true) {
		using original_fn = void(__thiscall*)(surface*, int, vertex_t*, bool);
		return (*(original_fn * *)this)[101](this, vertex_count, vertex, clip_vertices);
	}

	void draw_outlined_circle(int x, int y, int radius, int segments) {
		using original_fn = void(__thiscall*)(surface*, int, int, int, int);
		return (*(original_fn * *)this)[98](this, x, y, radius, segments);
	}

	void draw_set_texture_file(int texture_id, const char* texture_name, int hardware_filter, bool force_reload = 0) {
		using original_fn = void(__thiscall*)(surface*, int, const char*, int, bool);
		return (*(original_fn * *)this)[31](this, texture_id, texture_name, hardware_filter, force_reload);
	}

	bool is_texture_id_valid(int texture_id) {
		using original_fn = bool(__thiscall*)(surface*, int);
		return (*(original_fn * *)this)[37](this, texture_id);
	}

	void surface_get_cursor_pos(int& x, int& y) {
		using original_fn = void(__thiscall*)(surface*, int&, int&);
		return (*(original_fn * *)this)[95](this, std::ref(x), std::ref(y));  //x, y
	}

	void draw_textured_rect(int x, int y, int width, int height) {
		using original_fn = void(__thiscall*)(surface*, int, int, int, int);
		return (*(original_fn * *)this)[36](this, x, y, width, height);
	}
};