#ifndef FLOOR_H
#define FLOOR_H

#include "raylib.h"

class Floor{
public:
    Rectangle rect;
    Color color;

    Floor(float x, float y, float width, float height, Color color);
    void Draw() const;
};

#endif // FLOOR