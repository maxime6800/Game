#include "floor.h"
#include <iostream>

Floor::Floor(int width) : screenWidth(width), position({0.0f, 0.0f}), tileHeight(0) {
    // Empty constructor body
}

bool Floor::Load_Texture() {
    tileset = LoadTexture("/home/prg-user/Desktop/2DGame/floor.png");
    if (tileset.id == 0) {
        std::cerr << "Fehler beim Laden der Textur." << std::endl;
        return false;
    }

    // Verwende die volle Breite und Höhe des PNG-Bildes als Tile-Größe
    groundTileSrc = {0.0f, 0.0f, static_cast<float>(tileset.width), static_cast<float>(tileset.height)};
    tileHeight = groundTileSrc.height;
    position.y = static_cast<float>(GetScreenHeight()) - tileHeight; // Positioniere den Boden am unteren Bildschirmrand

    return true;
}

void Floor::Draw() {
    int numberOfTiles = screenWidth / static_cast<int>(groundTileSrc.width) + 1;

    for (int i = 0; i < numberOfTiles; i++) {
        Vector2 tilePosition = {position.x + i * groundTileSrc.width, position.y};
        DrawTextureRec(tileset, groundTileSrc, tilePosition, WHITE);
    }
}

void Floor::UpdatePosition(float playerX) {
    int tileWidth = static_cast<int>(groundTileSrc.width);
    position.x = -static_cast<int>(playerX) % tileWidth;
    if (position.x > 0) {
        position.x -= tileWidth;
    }
}

Floor::~Floor() {
    UnloadTexture(tileset);
}

