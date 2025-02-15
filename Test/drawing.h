#pragma once

#include "offsets.h" 
#include "WinAPI_func.h" 
#include "player.h" 
#include "entities.h" 
#include "mathematics.h"

struct Drawing {
private:
	WinFunc win__;

public:

	Drawing(WinFunc win_) : win__(win_) {}
	~Drawing();

	HBRUSH hBrush_enemy__ = CreateSolidBrush(RGB(255, 0, 0)); 
	HBRUSH hBrush_team__ = CreateSolidBrush(RGB(0, 0, 255)); 
	HBRUSH hBrush_healthbar_team__ = CreateSolidBrush(RGB(153, 153, 255));
	HBRUSH hBrush_healthbar_enemy__ = CreateSolidBrush(RGB(255, 153, 153)); 
	HBRUSH hBrush_healthbar_frame__ = CreateSolidBrush(RGB(0, 0, 0));

	COLORREF enemy_text_color__ = RGB(255, 153, 153);
	COLORREF team_text_color__ = RGB(153, 153, 255);

	HDC HDC_desktop__;
	HWND hTarget_window__;
	RECT m_rect__;

	HFONT hFont__;

	void draw_line_of_rect(int, int, int, int, HBRUSH&);

	void draw_line_of_frame_rect(int, int, int, int, HBRUSH&);

	void draw_border_box(int, int, int, int, int, HBRUSH&);

	void draw_string(int, int, COLORREF&, const char*);

	template<typename T>
	char* to_const_char_ptr(T value) {
		std::stringstream ss;
		ss << value;
		char* buffer = new char[ss.str().size() + 1];
		strcpy_s(buffer, ss.str().size() + 1, ss.str().c_str());
		return buffer;
	}
};

