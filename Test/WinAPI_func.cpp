#include "WinAPI_func.h"

WinFunc::WinFunc(LPCWSTR process_name_) {
	init(process_name_);
}

DWORD WinFunc::get_process_id(LPCWSTR process_name_) {
	DWORD proc_id = 0;
	HWND window_handle = FindWindowW(nullptr, process_name_);
	GetWindowThreadProcessId(window_handle, &proc_id);
	return proc_id;
}

HANDLE WinFunc::get_handle(DWORD process_id_) {
	return OpenProcess(PROCESS_VM_READ | PROCESS_VM_WRITE, false, process_id_);
}

HWND WinFunc::get_window_handle(LPCWSTR process_name_) {
	HWND window_handle = FindWindowW(nullptr, process_name_);
	return window_handle;
}

void WinFunc::window_size(HWND window_handle_) {
	RECT window_rect;
	GetWindowRect(window_handle__, &window_rect);

	width_window__ = window_rect.right - window_rect.left;
	height_window__ = window_rect.bottom - window_rect.top;
}

void WinFunc::init(LPCWSTR process_name_) {
	process_id__ = get_process_id(process_name_);
	process_handle__ = get_handle(process_id__);
	window_handle__ = get_window_handle(process_name_);
	window_size(window_handle__);
}

void WinFunc::print() {
	std::cout << "=============================" << "\n";
	std::cout << "=========== Game ============" << "\n";
	std::cout << "=============================" << "\n\n";

	std::cout << "The process has been accessed!" << "\n";
	std::cout << "Process ID:    " << process_id__ << "\n";
	std::cout << "Size of game window: " << width_window__ << "x" << height_window__ << "\n";

	std::cout << "\n\n";
}

