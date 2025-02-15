#pragma once
#include "include.h"
#include "offsets.h"
#include "WinAPI_func.h"
#include "Vector.h"

struct Player {
	Vector3 head_position__;
	Vector3 feet_position__;
	char name__[20];
	int health__;
	int team__;
	float matrix__[16];

	Player(WinFunc);

	void update_info();

	void print();
private:
	WinFunc win__;
	void init(WinFunc);
};