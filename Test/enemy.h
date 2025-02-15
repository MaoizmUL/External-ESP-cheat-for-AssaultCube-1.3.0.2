#pragma once
#include <iostream>
#include "Vector.h"

struct Enemy {

	uintptr_t base_address__;
	Vector3 head_position__;
	Vector3 feet_position__;
	char name__[20];
	int health__;
	int team__;

	void print();
};

