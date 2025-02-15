#pragma once
#include "drawing.h"

struct ESP : public Drawing{
public:

	WinFunc win__;
	Player player__;
	Entities entities__;
	Mathematics math__;

public:

	ESP(WinFunc win_) : win__(win_), player__(win_), entities__(win_), math__(win_), Drawing(win_) {
		hTarget_window__ = FindWindow(0, L"AssaultCube");
		HDC_desktop__ = GetDC(hTarget_window__);
		GetWindowRect(FindWindow(NULL, L"AssaultCube"), &m_rect__);
	}

	void draw_esp(int, int, float, int, char[20], HBRUSH&, COLORREF&);
	DWORD WINAPI run();
};

