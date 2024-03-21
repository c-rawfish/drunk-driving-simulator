#include "raylib.h"
#include "player.h"
#include "obstacles.h"

int main() {
	const int SCREEN_WIDTH{ 650 };
	const int SCREEN_HEIGHT{ 650 };

	InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "drunk driving simulator");
	SetTargetFPS(60);

	const float PLAYER_WIDTH{ 50 };
	const float PLAYER_HEIGHT{ 50 };
	player player(PLAYER_WIDTH, PLAYER_HEIGHT, BLUE, 500.0f, SCREEN_WIDTH, 5);
	
	obstacle_handler handler(SCREEN_WIDTH, 50, RED, 3, 8, SCREEN_HEIGHT, player.player_rec);

	bool game_over = false;

	while (!WindowShouldClose()) {
		BeginDrawing();
		ClearBackground(RAYWHITE);

		if (!game_over) {
			player.update_player();
			if (handler.update_obstacles())
				game_over = true;
		}
		else {
			DrawText("LMAOOO imagine losing", 10, 10, 32, LIGHTGRAY);
		}	

		EndDrawing();
	}

	CloseWindow();

	return 0;
}