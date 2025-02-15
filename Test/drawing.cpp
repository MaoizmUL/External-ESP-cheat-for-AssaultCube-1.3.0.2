#include "drawing.h"

Drawing::~Drawing() {
	DeleteObject(hBrush_enemy__);
	DeleteObject(hBrush_team__);
	DeleteObject(hBrush_healthbar_frame__);
	DeleteObject(hBrush_healthbar_enemy__);
	DeleteObject(hBrush_healthbar_team__);
	DeleteObject(HDC_desktop__);
	DeleteObject(hFont__);
	DeleteObject(hTarget_window__);
}

// Линия рисуется посредством создания прямоугольника и его заливкой цветом
// x_ - координата левого края	
// y_ - координата верхний край
// (x_ + w_) - координата правого края 
// (y_ + h_) - координата нижнего края
  
void Drawing::draw_line_of_rect(int x_, int y_, int w_, int h_, HBRUSH& brush_color_) {
	RECT rect = { x_, y_, (x_ + w_), (y_ + h_) };
	FillRect(HDC_desktop__, &rect, brush_color_);
}

void Drawing::draw_line_of_frame_rect(int x_, int y_, int w_, int h_, HBRUSH& brush_color_) {
	RECT rect = { x_, y_, (x_ + w_), (y_ + h_) };
	FrameRect(HDC_desktop__, &rect, brush_color_);
}

// Формирование самой рамки (прямоугольника вокруг игрока)
// thickness - толщина линий рамки, передается в качестве высоты в метод draw_line_of_rect()

void Drawing::draw_border_box(int x_, int y_, int w_, int h_, int thickness_, HBRUSH& brush_color_) {
	draw_line_of_rect(x_, y_, w_, thickness_, brush_color_);
	draw_line_of_rect(x_, y_, thickness_, h_, brush_color_);
	draw_line_of_rect((x_ + w_), y_, thickness_, h_, brush_color_);
	draw_line_of_rect(x_, (y_ + h_), w_, thickness_, brush_color_);
}

void Drawing::draw_string(int x_, int y_, COLORREF& color_, const char* text_) {
	SetTextAlign(HDC_desktop__, TA_CENTER | TA_NOUPDATECP);
	SetBkMode(HDC_desktop__, TRANSPARENT);
	SetTextColor(HDC_desktop__, color_);
	SelectObject(HDC_desktop__, hFont__);
	TextOutA(HDC_desktop__, x_, y_, text_, strlen(text_));
	DeleteObject(hFont__);
}
