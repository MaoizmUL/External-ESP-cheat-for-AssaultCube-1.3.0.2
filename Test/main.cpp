#include "ESP.h"

int main() {

	WinFunc win(L"AssaultCube");
	if (win.process_handle__ != NULL)
		win.print();
	else {
		std::cout << "The Process was not found!" << std::endl;
		return 1;
	}
	
	ESP ESP(win);
	bool is_esp_on = false;
	bool is_pressed_key = false; 
	while (true) {
		if (GetAsyncKeyState(VK_INSERT)) {
			if (!is_pressed_key) {
				is_esp_on = !is_esp_on;
				is_pressed_key = true;
			}
		}
		else {
			is_pressed_key = false;
		}

		if (is_esp_on) {
			ESP.run();
		}
	}

	return 0;
}