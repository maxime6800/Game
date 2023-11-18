#include "raylib.h"
#include <iostream>
#include "player.h"
#include "floor.h"


int main(){
    
    // Initialization
    const int screenWidth = 800;
    const int screenHeight = 600;

    Floor floor(0, screenHeight - 50, screenWidth, 50, DARKGRAY); // Der Boden ist 50 Einheiten hoch

    InitWindow(screenWidth, screenHeight, "2DGame");
    Player player{"Mes", RED, 2.0};
    
    
    Camera2D camera = {};
    Vector2 target = player.GetPosition(); // Stellen Sie sicher, dass player bereits initialisiert wurde
    camera.target = player.GetPosition();
    camera.offset = { screenWidth / 2.0f, screenHeight / 2.0f };
    camera.rotation = 0.0f;
    camera.zoom = 1.0f;

    SetTargetFPS(60);
    
    // Main Game Loop 
    while (!WindowShouldClose()) {
        // Update 
        player.movePlayer();
        player.Jump();
        camera.target = player.GetPosition(); // Aktualisieren der Kamera-Zielposition

    // Draw
        BeginDrawing();
        ClearBackground(LIGHTGRAY);

        BeginMode2D(camera);
        player.Draw(); // Zeichnen des Spielers innerhalb des Kamerakontexts
        floor.Draw();
        EndMode2D();

        // Zeichnen anderer Elemente außerhalb der Kamera hier
        EndDrawing();
}

    // end Initialization
    CloseWindow();

}