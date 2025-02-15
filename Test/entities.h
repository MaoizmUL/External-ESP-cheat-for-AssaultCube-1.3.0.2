#pragma once
#include "include.h"
#include "offsets.h"
#include "enemy.h"
#include "WinAPI_func.h"

struct Entities {

	int amount__;
	std::vector<Enemy> enemy_list__;

	Entities(WinFunc win_) : win__(win_) {
		ReadProcessMemory(win_.process_handle__, (LPCVOID)offset::players_on_map, &amount__, sizeof(amount__), nullptr);
		enemy_list__.resize(amount__);
		init();
	}

	void update_info();

	void print();

private:
	WinFunc win__;

	void init();
};

