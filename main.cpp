#include "raylib.h"
#include <iostream>
#include <vector>
#include "player.h"
#include "floor.h"
#include "collisionsManager.h"

float SPEED = 3.0;
float MAX_SPEED = 20.0;
float ACCELERATION = 10.0;


int main() {
    // Initialization of screen 
    const int screenWidth = 1600;
    const int screenHeight = 1000;

    // Initialization window
    InitWindow(screenWidth, screenHeight, "2DGame");
    
    // Init Implementation Objects
    Floor floor{screenWidth};
    Player player{"Player", RED, SPEED, MAX_SPEED, ACCELERATION};
    CollisionsManager collision;

    //init Cam 
    Camera2D camera = {};
    
    // Load the tileset texture
    floor.Load_Texture();

    // Load the tileset texture
    if (!floor.Load_Texture()) {
        CloseWindow();
        return -1;
    }

    // Cam settings
    camera.target = player.GetPosition();
    camera.offset = { (float)screenWidth / 2, (float)screenHeight / 2 };
    camera.rotation = 0.0f;
    camera.zoom = 1.0f;

    // FPS rate 
    SetTargetFPS(60);
    

    // Main Game Loop
    while (!WindowShouldClose()) {
        // Update
        player.movePlayer();
        player.Jump();
        player.stop_vertical_speed();
        collision.detect_collision(player, floor);
        camera.target = player.GetPosition(); // Update camera target position
        floor.UpdatePosition(player.GetPosition().x);

        // Draw
        BeginDrawing();
        ClearBackground(LIGHTGRAY);

        BeginMode2D(camera);
        floor.Draw();

        player.Draw(); // Draw player within the camera context
        EndMode2D();

        // Draw other elements outside of the camera here
        EndDrawing();
    }

    // De-Initialization
    CloseWindow();

    // Clean up resources that Raylib may have allocated
    CloseAudioDevice(); // Close audio device if you have initialized it
    //rlglClose();        // Close rlgl if you have used it directly

    return 0;
}
