#include "player.h"
#include "raylib.h"
#include <cmath>
#include <iostream>


Player::Player(std::string name, Color color, float speed, Vector2 v1, Vector2 v2, Vector2 v3): 
            name{name}, color{color}, speed{speed}, v1{v1}, v2{v2}, v3{v3}, isJumping{false}, jumpHeight{50},gravity{4.8}, verticalSpeed{0}{
    
};
void Player::Draw(){
    DrawTriangle(v1, v2, v3, color);
}
void Player::movePlayer() {
    if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D)) {
        v1.x += speed;
        v2.x += speed;
        v3.x += speed;
    }
    if (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A)) {
        v1.x -= speed;
        v2.x -= speed;
        v3.x -= speed;
    }
}

void Player::Jump() {
    if (IsKeyPressed(KEY_SPACE) && !isJumping) {
        isJumping = true;
        verticalSpeed = -10.0; // Erhöhen Sie diesen Wert für einen schnelleren Start des Sprungs
    }

    if (isJumping) {
        // Aktualisiere die Geschwindigkeit
        verticalSpeed += 20.0 * GetFrameTime(); // Erhöhen Sie diesen Wert, um die Gravitation zu verstärken

        // Speichere die alte Y-Position
        float oldY = v1.y;

        // Aktualisiere die Position
        v1.y += verticalSpeed;
        v2.y += verticalSpeed;
        v3.y += verticalSpeed;

        // Bodenkollision prüfen
        float groundLevel = 600 - 100; // Stellen Sie sicher, dass dies der tatsächliche Bodenwert ist
        if ((v1.y > groundLevel && oldY <= groundLevel) || v1.y >= groundLevel) {
            v1.y = groundLevel;
            v2.y = groundLevel - 50; // Angenommen, dies ist die Höhe Ihres Dreiecks
            v3.y = groundLevel - 50;
            isJumping = false;
            verticalSpeed = 0;
        }

    }
}


void Player::UpdateOrientation(){

}
Vector2 Player::GetPosition() const {
    Vector2 center;
    center.x = (v1.x + v2.x + v3.x) / 3;
    center.y = (v1.y + v2.y + v3.y) / 3;
    std::cout << "v1: (" << v1.x << ", " << v1.y << "), ";
    std::cout << "v2: (" << v2.x << ", " << v2.y << "), ";
    std::cout << "v3: (" << v3.x << ", " << v3.y << ")\n";

    return center;
}

