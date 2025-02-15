#include "ESP.h"

void ESP::draw_esp(int x_, int y_, float distance_, int health_, char name_[20], HBRUSH& hBrush_, COLORREF& text_color_) {

	int width = static_cast<int>((win__.width_window__ * 1.375) / distance_); //box width around player
	int height = static_cast<int>((win__.height_window__ * 3.7) / distance_); //box height around player	

	draw_border_box(x_ - (width / 2), y_ - height, width, height, 1, hBrush_);

	int height_hp = (health_ * height) / 100;

	if (text_color_ == team_text_color__)
		draw_line_of_rect(x_ - (width / 2) - 10, y_, 5, -height_hp, hBrush_healthbar_team__);
	else
		draw_line_of_rect(x_ - (width / 2) - 10, y_, 5, -height_hp, hBrush_healthbar_enemy__);

	draw_line_of_frame_rect(x_ - (width / 2) - 10, y_ - height, 6, height, hBrush_healthbar_frame__); //frame around healthbar

	char* health_info = to_const_char_ptr(health_);

	draw_string(x_, y_, text_color_, name_); //name of player
	draw_string(x_, y_ + 15, text_color_, health_info); //health of player 

	delete[] health_info;
}


DWORD WINAPI ESP::run() {
	entities__.update_info();
	player__.update_info();

	for (unsigned int i = 0; i < entities__.amount__; ++i) {
		if (math__.world_to_screen(entities__.enemy_list__[i].feet_position__, math__.screen__, player__.matrix__, win__.width_window__, win__.height_window__) && entities__.enemy_list__[i].health__ > 0) {
			if (entities__.enemy_list__[i].team__ != player__.team__)
				draw_esp(math__.screen__.x, math__.screen__.y, math__.get_distance_3D(player__.feet_position__, entities__.enemy_list__[i].feet_position__), entities__.enemy_list__[i].health__, entities__.enemy_list__[i].name__, hBrush_enemy__, enemy_text_color__);
			else
				draw_esp(math__.screen__.x, math__.screen__.y, math__.get_distance_3D(player__.feet_position__, entities__.enemy_list__[i].feet_position__), entities__.enemy_list__[i].health__, entities__.enemy_list__[i].name__, hBrush_team__, team_text_color__);
		}
	}

	return 0;
}


