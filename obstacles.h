#pragma once
#include "raylib.h"

void init_obstacles(const int MIN_OBSTACLES, const int MAX_OBSTACLES, const int SCREEN_WIDTH, const int SCREEN_HEIGHT);
void deinit_obstacles();
bool update_obstacles(Rectangle player); // returns if an obstacle has collided with the player