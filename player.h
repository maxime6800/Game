#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <string>
#include "raylib.h"

class Player{
    std::string name;
    Color color;
    float speed;
    Vector2 v1, v2, v3;
    bool isJumping;
    float jumpHeight;
    float gravity;
    float verticalSpeed;
public:
    Player(std::string, Color, float, Vector2 = {800/2, 100 }, Vector2 = {800/2 - 50, 200 }, Vector2 = {800/2 + 50, 200 });
    void Draw();
    void movePlayer();
    void Jump();
    void UpdateOrientation();
    Vector2 GetPosition() const;

};

#endif //PLAYER