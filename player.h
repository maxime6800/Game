#ifndef PLAYER_H
#define PLAYER_H

#include "raylib.h"
#include <string>

class Player {
    std::string name;
    Color color;        // Color Player
    float speed;        // Grundgeschwindigkeit
    float maxSpeed;     // Maximale Geschwindigkeit
    float acceleration; // Beschleunigung
    Vector2 v1, v2, v3; // Dreieckspunkte des Spielers
    bool isJumping;     
    float verticalSpeed; // Vertikale Geschwindigkeit für Sprünge
public:
    Player(const std::string& name, Color color, float speed, float maxSpeed, float acceleration);
    void Draw();
    void movePlayer();
    void Jump();
    void stop_vertical_speed();
    Vector2 GetPosition() const;
    float GetHeight() const;
    void SetPositionY(float y);
    float get_x();
};

#endif // PLAYER_H
