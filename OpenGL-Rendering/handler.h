#pragma once
#include <windows.h>
#include <stdio.h>
#include <random>

float ball[];
extern float velocity;
extern bool up;
extern bool right;
DWORD WINAPI game_Handler(void* data);