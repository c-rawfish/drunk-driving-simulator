#include "raylib.h"
#include "raymath.h"
#include "player.h"

const int MOVE_SPEED_X = 7;
const int PLAYER_WIDTH = 50;
const int PLAYER_HEIGHT = 65;

Rectangle player_rect = {0, 0, 0, 0};

int max_x = 0;

void init_player(const int SCREEN_WIDTH, const int START_Y) {
    max_x = SCREEN_WIDTH - PLAYER_WIDTH;
    
    player_rect.x = (SCREEN_WIDTH / 2) - (PLAYER_WIDTH / 2);
    player_rect.y = START_Y;
    player_rect.width = PLAYER_WIDTH;
    player_rect.height = PLAYER_HEIGHT;
}

void update_player() {
    if(IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A)) {
        player_rect.x -= MOVE_SPEED_X;
    }
    if(IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D)) {
        player_rect.x += MOVE_SPEED_X;
    }
    
    player_rect.x = Clamp(player_rect.x, 0, max_x);
}

void draw_player() {
    DrawRectangleRec(player_rect, BLUE);
}

Rectangle get_player_rec() {
    return player_rect;
}