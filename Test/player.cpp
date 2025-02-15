#include "player.h"

Player::Player(WinFunc win_) : win__(win_) {
	init(win_);
}

void Player::init(WinFunc win_) {
	ReadProcessMemory(win_.process_handle__, (LPCVOID)(offset::base_entity_address), &offset::base_entity_address, sizeof(offset::base_entity_address), nullptr);

	ReadProcessMemory(win_.process_handle__, (LPCVOID)(offset::base_entity_address + offset::head_position), &head_position__.x, sizeof(head_position__.x), nullptr);
	ReadProcessMemory(win_.process_handle__, (LPCVOID)(offset::base_entity_address + (offset::head_position + 0x4)), &head_position__.y, sizeof(head_position__.y), nullptr);
	ReadProcessMemory(win_.process_handle__, (LPCVOID)(offset::base_entity_address + (offset::head_position + 0x8)), &head_position__.z, sizeof(head_position__.z), nullptr);

	ReadProcessMemory(win_.process_handle__, (LPCVOID)(offset::base_entity_address + offset::feet_position), &feet_position__.x, sizeof(feet_position__.x), nullptr);
	ReadProcessMemory(win_.process_handle__, (LPCVOID)(offset::base_entity_address + (offset::feet_position + 0x4)), &feet_position__.y, sizeof(feet_position__.y), nullptr);
	ReadProcessMemory(win_.process_handle__, (LPCVOID)(offset::base_entity_address + (offset::feet_position + 0x8)), &feet_position__.z, sizeof(feet_position__.z), nullptr);

	ReadProcessMemory(win_.process_handle__, (PBYTE*)(offset::base_entity_address + offset::name), &name__, sizeof(name__), nullptr);
	ReadProcessMemory(win_.process_handle__, (LPCVOID)(offset::base_entity_address + offset::health), &health__, sizeof(health__), nullptr);
	ReadProcessMemory(win_.process_handle__, (LPCVOID)(offset::base_entity_address + offset::team), &team__, sizeof(team__), nullptr);

	ReadProcessMemory(win_.process_handle__, (LPCVOID)(offset::viewmatrix), &matrix__, sizeof(matrix__), nullptr);
}

void Player::update_info() {

	ReadProcessMemory(win__.process_handle__, (LPCVOID)(offset::base_entity_address + offset::head_position), &head_position__.x, sizeof(head_position__.x), nullptr);
	ReadProcessMemory(win__.process_handle__, (LPCVOID)(offset::base_entity_address + (offset::head_position + 0x4)), &head_position__.y, sizeof(head_position__.y), nullptr);
	ReadProcessMemory(win__.process_handle__, (LPCVOID)(offset::base_entity_address + (offset::head_position + 0x8)), &head_position__.z, sizeof(head_position__.z), nullptr);

	ReadProcessMemory(win__.process_handle__, (LPCVOID)(offset::base_entity_address + offset::feet_position), &feet_position__.x, sizeof(feet_position__.x), nullptr);
	ReadProcessMemory(win__.process_handle__, (LPCVOID)(offset::base_entity_address + (offset::feet_position + 0x4)), &feet_position__.y, sizeof(feet_position__.y), nullptr);
	ReadProcessMemory(win__.process_handle__, (LPCVOID)(offset::base_entity_address + (offset::feet_position + 0x8)), &feet_position__.z, sizeof(feet_position__.z), nullptr);

	ReadProcessMemory(win__.process_handle__, (PBYTE*)(offset::base_entity_address + offset::name), &name__, sizeof(name__), nullptr);
	ReadProcessMemory(win__.process_handle__, (LPCVOID)(offset::base_entity_address + offset::health), &health__, sizeof(health__), nullptr);
	ReadProcessMemory(win__.process_handle__, (LPCVOID)(offset::base_entity_address + offset::team), &team__, sizeof(team__), nullptr);

	ReadProcessMemory(win__.process_handle__, (PBYTE*)(offset::viewmatrix), &matrix__, sizeof(matrix__), nullptr);
}

void Player::print() {
	std::cout << "=============================" << "\n";
	std::cout << "========== Player ===========" << "\n";
	std::cout << "=============================" << "\n\n";

	std::cout << "Name (me): " << name__ << "\n";
	std::cout << "Health: " << health__ << "\n";
	std::cout << "Position (head): (" << head_position__.x << ", " << head_position__.y << ", " << head_position__.z << ")\n";
	std::cout << "Position (feet): (" << feet_position__.x << ", " << feet_position__.y << ", " << feet_position__.z << ")\n";
	std::cout << "Team: " << team__ << "\n";

	std::cout << "\n\n";
}