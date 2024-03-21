#pragma once
#include "raylib.h"

struct player {
	Rectangle player_rec{};
	Color player_color{};
	Vector2 player_pos{};
	Vector2 player_bounds{};
	int player_speed;

	player(float width, float height, Color color, float start_y, int screen_width, int speed);
	void update_player();
};