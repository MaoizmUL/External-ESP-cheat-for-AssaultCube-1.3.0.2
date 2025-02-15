#include "entities.h"

void Entities::init() {
	
	for (unsigned int i = 0; i < amount__ - 1; ++i) {
		ReadProcessMemory(win__.process_handle__, (LPCVOID)(offset::base_entity_list_address), &enemy_list__[i].base_address__, sizeof(enemy_list__[i].base_address__), nullptr);
		ReadProcessMemory(win__.process_handle__, (LPCVOID)(enemy_list__[i].base_address__ + (i * 0x4)), &enemy_list__[i].base_address__, sizeof(enemy_list__[i].base_address__), nullptr);

		ReadProcessMemory(win__.process_handle__, (LPCVOID)(enemy_list__[i].base_address__ + offset::head_position), &enemy_list__[i].head_position__.x, sizeof(enemy_list__[i].head_position__.x), nullptr);
		ReadProcessMemory(win__.process_handle__, (LPCVOID)(enemy_list__[i].base_address__ + (offset::head_position + 0x4)), &enemy_list__[i].head_position__.y, sizeof(enemy_list__[i].head_position__.y), nullptr);
		ReadProcessMemory(win__.process_handle__, (LPCVOID)(enemy_list__[i].base_address__ + (offset::head_position + 0x8)), &enemy_list__[i].head_position__.z, sizeof(enemy_list__[i].head_position__.z), nullptr);

		ReadProcessMemory(win__.process_handle__, (LPCVOID)(enemy_list__[i].base_address__ + offset::feet_position), &enemy_list__[i].feet_position__.x, sizeof(enemy_list__[i].feet_position__.x), nullptr);
		ReadProcessMemory(win__.process_handle__, (LPCVOID)(enemy_list__[i].base_address__ + (offset::feet_position + 0x4)), &enemy_list__[i].feet_position__.y, sizeof(enemy_list__[i].feet_position__.y), nullptr);
		ReadProcessMemory(win__.process_handle__, (LPCVOID)(enemy_list__[i].base_address__ + (offset::feet_position + 0x8)), &enemy_list__[i].feet_position__.z, sizeof(enemy_list__[i].feet_position__.z), nullptr);

		ReadProcessMemory(win__.process_handle__, (LPCVOID)(enemy_list__[i].base_address__ + offset::name), &enemy_list__[i].name__, sizeof(enemy_list__[i].name__), nullptr);
		ReadProcessMemory(win__.process_handle__, (LPCVOID)(enemy_list__[i].base_address__ + offset::health), &enemy_list__[i].health__, sizeof(enemy_list__[i].health__), nullptr);
		ReadProcessMemory(win__.process_handle__, (LPCVOID)(enemy_list__[i].base_address__ + offset::team), &enemy_list__[i].team__, sizeof(enemy_list__[i].team__), nullptr);
	}
}

void Entities::update_info() {
	for (unsigned int i = 0; i < amount__ - 1; ++i) {
		ReadProcessMemory(win__.process_handle__, (LPCVOID)(offset::base_entity_list_address), &enemy_list__[i].base_address__, sizeof(enemy_list__[i].base_address__), nullptr);
		ReadProcessMemory(win__.process_handle__, (LPCVOID)(enemy_list__[i].base_address__ + (i * 0x4)), &enemy_list__[i].base_address__, sizeof(enemy_list__[i].base_address__), nullptr);

		ReadProcessMemory(win__.process_handle__, (LPCVOID)(enemy_list__[i].base_address__ + offset::head_position), &enemy_list__[i].head_position__.x, sizeof(enemy_list__[i].head_position__.x), nullptr);
		ReadProcessMemory(win__.process_handle__, (LPCVOID)(enemy_list__[i].base_address__ + (offset::head_position + 0x4)), &enemy_list__[i].head_position__.y, sizeof(enemy_list__[i].head_position__.y), nullptr);
		ReadProcessMemory(win__.process_handle__, (LPCVOID)(enemy_list__[i].base_address__ + (offset::head_position + 0x8)), &enemy_list__[i].head_position__.z, sizeof(enemy_list__[i].head_position__.z), nullptr);

		ReadProcessMemory(win__.process_handle__, (LPCVOID)(enemy_list__[i].base_address__ + offset::feet_position), &enemy_list__[i].feet_position__.x, sizeof(enemy_list__[i].feet_position__.x), nullptr);
		ReadProcessMemory(win__.process_handle__, (LPCVOID)(enemy_list__[i].base_address__ + (offset::feet_position + 0x4)), &enemy_list__[i].feet_position__.y, sizeof(enemy_list__[i].feet_position__.y), nullptr);
		ReadProcessMemory(win__.process_handle__, (LPCVOID)(enemy_list__[i].base_address__ + (offset::feet_position + 0x8)), &enemy_list__[i].feet_position__.z, sizeof(enemy_list__[i].feet_position__.z), nullptr);

		ReadProcessMemory(win__.process_handle__, (LPCVOID)(enemy_list__[i].base_address__ + offset::name), &enemy_list__[i].name__, sizeof(enemy_list__[i].name__), nullptr);
		ReadProcessMemory(win__.process_handle__, (LPCVOID)(enemy_list__[i].base_address__ + offset::health), &enemy_list__[i].health__, sizeof(enemy_list__[i].health__), nullptr);
		ReadProcessMemory(win__.process_handle__, (LPCVOID)(enemy_list__[i].base_address__ + offset::team), &enemy_list__[i].team__, sizeof(enemy_list__[i].team__), nullptr);
	}
}

void Entities::print() {
	std::cout << "=============================" << "\n";
	std::cout << "========= Entities ==========" << "\n";
	std::cout << "=============================" << "\n\n";

	for (unsigned int i = 0; i < amount__ - 1; ++i) {
		enemy_list__[i].print();
	}

	std::cout << "\n\n";
}