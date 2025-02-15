#pragma once
#include <iostream>

namespace offset {
	static uintptr_t base_address = 0x00400000;
	static uintptr_t base_entity_address = base_address + 0x0018AC00;
	static uintptr_t base_entity_list_address = base_address + 0x00191FCC;
	static uintptr_t players_on_map = base_address + 0x18AC0C;
	static uintptr_t head_position = 0x4;
	static uintptr_t feet_position = 0x28;
	static uintptr_t view_angles = 0x34;
	static uintptr_t health = 0xEC;
	static uintptr_t is_dead = 0xB4;
	static uintptr_t name = 0x205;
	static uintptr_t team = 0x30C;
	static uintptr_t current_ammo = 0x140;
	static uintptr_t viewmatrix = 0x0057DFD0;
};