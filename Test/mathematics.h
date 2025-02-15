#pragma once

#include "WinAPI_func.h"
#include "Vector.h"

struct Mathematics {

private:
	WinFunc win__;

public:
	Vector2 screen__;
	Vector4 clip_coords__;
	Vector4 NDC__;

	Mathematics(WinFunc win_) : win__(win_) {}

	bool world_to_screen(Vector3&, Vector2&, float[16], int, int);

	float get_distance_2D(Vector3&, Vector3&);
	float get_distance_3D(Vector3&, Vector3&);
};

