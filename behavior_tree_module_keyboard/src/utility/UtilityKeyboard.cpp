#include "utility/UtilityKeyboard.h"

#include <Windows.h>

namespace utility
{
	void setKeyDown(const int keycode)
	{
		INPUT input = { 0 };
		input.type = INPUT_KEYBOARD;
		input.ki.wScan = 0;
		input.ki.time = 0;
		input.ki.dwExtraInfo = 0;
		input.ki.dwFlags = 0;
		input.ki.wVk = keycode;
		SendInput(1, &input, sizeof(INPUT));
	}

	void setKeyUp(const int keycode)
	{
		INPUT input = { 0 };
		input.type = INPUT_KEYBOARD;
		input.ki.wScan = 0;
		input.ki.time = 0;
		input.ki.dwExtraInfo = 0;
		input.ki.dwFlags = KEYEVENTF_KEYUP;
		input.ki.wVk = keycode;
		SendInput(1, &input, sizeof(INPUT));
	}
}
