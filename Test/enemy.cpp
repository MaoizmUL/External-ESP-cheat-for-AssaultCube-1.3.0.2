#include "enemy.h"

void Enemy::print() {

	std::cout << "Name: " << name__ << "\n";
	std::cout << "Health: " << health__ << "\n";
	std::cout << "Position (head): (" << head_position__.x << ", " << head_position__.y << ", " << head_position__.z << ")\n";
	std::cout << "Position (feet): (" << feet_position__.x << ", " << feet_position__.y << ", " << feet_position__.z << ")\n";
	std::cout << "Team: " << team__ << "\n";

	std::cout << "\n\n";
}