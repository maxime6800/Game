#ifndef FLOOR_H
#define FLOOR_H

#include "raylib.h"

class Floor {
public:
    Texture2D tileset;
    Rectangle groundTileSrc;
    Vector2 position;
    int screenWidth;
    float tileHeight;

    Floor(int width);
    ~Floor();
    bool Load_Texture();
    void Draw();
    void UpdatePosition(float playerX); // Hinzufügen einer Methode zur Aktualisierung der Position
};

#endif // FLOOR_H