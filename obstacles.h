#pragma once
#include "raylib.h"
#include <vector>

class obstacle_handler {
public:
	obstacle_handler(const int display_width, float height, Color color, int speed, int count, const int display_height, Rectangle& player);
	bool update_obstacles();
private:
	void reset_obstacles();

	Rectangle obstacle_rec{};
	Rectangle& player_rec;
	Color obstacle_color{};
	int obstacle_speed{};
	int screen_height{};
	std::vector<bool> obstacles{};
};
