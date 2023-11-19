#include "collisionsManager.h"

CollisionsManager::CollisionsManager() {
    // Constructor body
}

void CollisionsManager::detect_collision(Player &player, Floor &floor) {
    // Collision logic
    if (player.GetPosition().y + player.GetHeight() >= floor.position.y) {
        player.stop_vertical_speed();
        player.SetPositionY(floor.position.y - player.GetHeight()); // Place player exactly on the floor
    }
}
