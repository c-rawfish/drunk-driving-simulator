#include "obstacles.h"
#include <random>

obstacle_handler::obstacle_handler(const int display_width, float height, Color color, int speed, int count, const int display_height, Rectangle& player) :
	obstacle_color(color),
	obstacle_speed(speed),
	screen_height(display_height),
	player_rec(player),
	obstacle_rec{ 0, 0, static_cast<float>(display_width / count), height },
	obstacles(count, false)
{
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

	std::random_device rd;
	std::mt19937 rng(rd());
	std::uniform_int_distribution<int> distribution(1, 3);
	std::generate(obstacles.begin(), obstacles.end(),
		[&]() { bool gen = distribution(rng) <= 2; spawn_count = gen ? spawn_count + 1 : spawn_count; return gen && spawn_count; });
}

