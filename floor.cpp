#include "floor.h"
#include "raylib.h"

Floor::Floor(float x, float y, float width, float height, Color color): rect{x, y, width, height}, color{color}{}
void Floor::Draw() const{
    DrawRectangle(rect, color);
}

