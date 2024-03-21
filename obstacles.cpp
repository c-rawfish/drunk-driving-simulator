#include "obstacles.h"
#include <math.h>
#include <chrono>

obstacle_handler::obstacle_handler(const int display_width, float height, Color color, int speed, int count, const int display_height, Rectangle& player) :
	obstacle_color(color), obstacle_speed(speed), screen_height(display_height), player_rec(player)
{
	obstacle_width = static_cast<float>(display_width / count);
	obstacle_rec = Rectangle{ 0, 0, obstacle_width, height };
	for (int i = 0; i < count; i++)
		obstacles.push_back(false);

	reset_obstacles();
}

bool obstacle_handler::update_obstacles() {
	obstacle_rec.y += obstacle_speed;
	if (obstacle_rec.y > screen_height) {
		obstacle_rec.y = 0 - obstacle_rec.height;
		reset_obstacles();
	}

	bool collided = false;

	for (int i = 0; i < obstacles.size(); i++) {
		if (obstacles.at(i)) {
			obstacle_rec.x = i * obstacle_rec.width;

			DrawRectangleRec(obstacle_rec, obstacle_color);
			if (CheckCollisionRecs(obstacle_rec, player_rec))
				collided = true;
		}
	}

	return collided;
}

void obstacle_handler::reset_obstacles() {
	int spawn_count = 0;

	for (int i = 0; i < obstacles.size(); i++) {
		obstacles.at(i) = false;

		SetRandomSeed(static_cast<unsigned int>(std::chrono::high_resolution_clock::now().time_since_epoch().count()));
		if (GetRandomValue(1, 3) <= 2 && !(spawn_count > obstacles.size() - 1)) {
			obstacles.at(i) = true;
		}
	}
}

