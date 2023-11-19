#include "player.h"
#include <cmath>

Player::Player(const std::string& name, Color color, float speed, float maxSpeed, float acceleration) 
    : name(name), color(color), speed(0), maxSpeed(maxSpeed), acceleration(acceleration),
      isJumping(false), verticalSpeed(0) {
    // Initialisiere Spieler-Dreieckspunkte
    v1 = { GetScreenWidth() / 2.0f, 100.0f };
    v2 = { GetScreenWidth() / 2.0f - 50.0f, 150.0f };
    v3 = { GetScreenWidth() / 2.0f + 50.0f, 150.0f };
}

void Player::Draw() {
    DrawTriangle(v1, v2, v3, color);
}

void Player::movePlayer() {
    if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D)) {
        speed += acceleration;
    } else if (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A)) {
        speed -= acceleration;
    } else {
        // Reduziere die Geschwindigkeit schrittweise, wenn keine Taste gedrückt wird
        if (speed > 0) {
            speed -= acceleration;
        } else if (speed < 0) {
            speed += acceleration;
        }
    }

    // Begrenze die Geschwindigkeit auf die maximale Geschwindigkeit
    if (speed > maxSpeed) speed = maxSpeed;
    if (speed < -maxSpeed) speed = -maxSpeed;

    // Aktualisiere die Position
    v1.x += speed;
    v2.x += speed;
    v3.x += speed;
}

float Player::get_x(){
    return v1.x;
}
void Player::Jump() {
    int count{0};
    if(IsKeyPressed(KEY_SPACE) && isJumping == false){
        v1.y += verticalSpeed;
        v2.y += verticalSpeed;
        v3.y += verticalSpeed;
        ++count;
        isJumping = false;
        if(50 > count){
            verticalSpeed = 0;
        }
    }   
}

void Player::stop_vertical_speed() {

}

Vector2 Player::GetPosition() const {
    return v1; // Assuming v1 is the base of the player triangle
}

float Player::GetHeight() const {
    return v2.y - v1.y; // Assuming v2 is the top of the player triangle
}

void Player::SetPositionY(float y) {
    float height = GetHeight();
    v1.y = y - height;
    v2.y = y;
    v3.y = y;
}
