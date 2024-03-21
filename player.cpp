#include "player.h"
#include "raymath.h"

player::player(float width, float height, Color color, float start_y, int screen_width, int speed) {
	player_color = color;
	player_speed = speed;
	player_bounds = Vector2{ 0.0f, screen_width - width };
	player_rec = Rectangle{ (screen_width / 2) - (width / 2), start_y, width, height };
}

void player::update_player() {
	int move_x{ 0 };

	if (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A))
		move_x -= player_speed;
	if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D))
		move_x += player_speed;

	player_rec.x = Clamp(player_rec.x + move_x, player_bounds.x, player_bounds.y);

	DrawRectangleRec(player_rec, player_color);
}