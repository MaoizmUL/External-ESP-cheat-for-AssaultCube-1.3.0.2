#include "mathematics.h"
#include <cmath>

bool Mathematics::world_to_screen(Vector3& pos_player_, Vector2& screen_, float matrix_[16], int window_width_, int window_height_) {
	
	clip_coords__.x = pos_player_.x * matrix_[0] + pos_player_.y * matrix_[4] + pos_player_.z * matrix_[8] + matrix_[12];
	clip_coords__.y = pos_player_.x * matrix_[1] + pos_player_.y * matrix_[5] + pos_player_.z * matrix_[9] + matrix_[13];
	clip_coords__.z = pos_player_.x * matrix_[2] + pos_player_.y * matrix_[6] + pos_player_.z * matrix_[10] + matrix_[14];
	clip_coords__.w = pos_player_.x * matrix_[3] + pos_player_.y * matrix_[7] + pos_player_.z * matrix_[11] + matrix_[15];

	if (clip_coords__.w < 0.1f)
		return false;

	NDC__.x = clip_coords__.x / clip_coords__.w;
	NDC__.y = clip_coords__.y / clip_coords__.w;
	NDC__.z = clip_coords__.z / clip_coords__.w;

	screen_.x = (window_width_ / 2 * NDC__.x) + (NDC__.x + window_width_ / 2);
	screen_.y = -(window_height_ / 2 * NDC__.y) + (NDC__.y + window_height_ / 2);

	return true;
}

float Mathematics::get_distance_2D(Vector3& m_pos_, Vector3& en_pos_) {
	return (float)std::sqrt(std::pow((en_pos_.x - m_pos_.x), 2) + std::pow((en_pos_.y - m_pos_.y), 2));
}

float Mathematics::get_distance_3D(Vector3& m_pos_, Vector3& en_pos_) {
	return (float)std::sqrt(std::pow((en_pos_.x - m_pos_.x), 2) + std::pow((en_pos_.y - m_pos_.y), 2) + std::pow((en_pos_.z - m_pos_.z), 2));
}

