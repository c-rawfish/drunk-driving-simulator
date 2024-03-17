#include "obstacles.h"
#include <stdlib.h>
#include <time.h>

bool* generate_list;

int obstacle_rect_width = 0;
int spacing = 0;
int obstacle_y = 0;
const int OBSTACLE_RECT_HEIGHT = 50;
const int OBSTACLE_MOVE_SPEED = 3;

int max_obstacles = 0;
int min_obstacles = 0;

int screen_height = 0;

void generate_obstacles() {
    for(int i = 0; i < sizeof(generate_list); i++)
        generate_list[i] = false;
    
    int obstacle_count = GetRandomValue(min_obstacles, max_obstacles);
    int picked_count = 0;
    
    while(picked_count < obstacle_count) {
        int index = GetRandomValue(0, max_obstacles);
        
        if(generate_list[index] == true)
            continue;
        
        generate_list[index] = true;
        picked_count++;
    }
}

void init_obstacles(const int MIN_OBSTACLES, const int MAX_OBSTACLES, const int SCREEN_WIDTH, const int SCREEN_HEIGHT) {
    generate_list = malloc(sizeof(bool) * MAX_OBSTACLES + 1);
    
    max_obstacles = MAX_OBSTACLES;
    min_obstacles = MIN_OBSTACLES;
    
    generate_obstacles();
    
    obstacle_rect_width = SCREEN_WIDTH / (MAX_OBSTACLES + 1); // + 1 to allow for spacing
    spacing = ((SCREEN_WIDTH - (obstacle_rect_width * MAX_OBSTACLES)) / MAX_OBSTACLES);
    obstacle_y = 0 - OBSTACLE_RECT_HEIGHT;
    
    screen_height = SCREEN_HEIGHT;
}

bool update_obstacles(Rectangle player) { // returns if an obstacle has collided with the player
    bool collision = false;
    
    obstacle_y += OBSTACLE_MOVE_SPEED;
    if(obstacle_y > screen_height) {
        obstacle_y = 0 - OBSTACLE_RECT_HEIGHT;
        generate_obstacles();
    }
    
    for(int i = 0; i < max_obstacles; i++) {
        if(generate_list[i] == false)
            continue;
        
        Rectangle rec = {(obstacle_rect_width * i) + (spacing * (i + 1)), obstacle_y, obstacle_rect_width, OBSTACLE_RECT_HEIGHT};
        DrawRectangleRec(rec, RED);
        
        if(CheckCollisionRecs(player, rec))
            collision = true;
    }
    
    
    return collision;
}

void deinit_obstacles() {
    free(generate_list);
}