#pragma once
#include "include.h"

struct WinFunc {
	DWORD process_id__;
	HANDLE process_handle__;
	HWND window_handle__;

	unsigned int width_window__;
	unsigned int height_window__;

	WinFunc(LPCWSTR);

	static DWORD get_process_id(LPCWSTR);
	static HANDLE get_handle(DWORD);
	static HWND get_window_handle(LPCWSTR);
	void window_size(HWND);

	void print();

	private:
		void init(LPCWSTR);
};