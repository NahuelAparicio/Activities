#pragma once
#include <Windows.h>

enum class InputKey { LEFT, LEFT_UP, UP, RIGHT_UP, RIGHT, RIGHT_DOWN, DOWN, DOWN_LEFT,FIRE, ESCAPE, COUNT };

struct InputData {

	bool Keyboard[(int)InputKey::COUNT] = {};

	void Update() {
		Keyboard[(int)InputKey::LEFT] = GetAsyncKeyState(VK_LEFT);
		Keyboard[(int)InputKey::UP] = GetAsyncKeyState(VK_UP);
		Keyboard[(int)InputKey::RIGHT] = GetAsyncKeyState(VK_RIGHT);
		Keyboard[(int)InputKey::DOWN] = GetAsyncKeyState(VK_DOWN);
		Keyboard[(int)InputKey::FIRE] = GetAsyncKeyState(VK_SPACE);
		if (Keyboard[(int)InputKey::LEFT] && (Keyboard[(int)InputKey::UP]))

		{
			Keyboard[(int)InputKey::LEFT_UP] = GetAsyncKeyState(VK_LEFT) + GetAsyncKeyState(VK_UP);
		}

	}
};
