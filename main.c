#include "raylib.h"
#include "player.h"
#include "obstacles.h"

int main() {
    const int SCREEN_WIDTH = 650;
    const int SCREEN_HEIGHT = 650;
    
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "drunk driving simulator");
    SetTargetFPS(60);
    
    init_player(SCREEN_WIDTH, 350);
    init_obstacles(4, 8, SCREEN_WIDTH, SCREEN_HEIGHT);
    
    bool game_over = false;
    
    while(!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        
        if(!game_over) {
           update_player();
        
        
           if(update_obstacles(get_player_rec()))
               game_over = true;
           draw_player();
        } else {
            DrawText("game over lmaoooo", 10, 10, 32, BLACK);
        }
        
        EndDrawing();
    }
    
    CloseWindow();
    deinit_obstacles();
    
    return 0;
}