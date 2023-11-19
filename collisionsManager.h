#ifndef COLLISIONSMANAGER_H
#define COLLISIONSMANAGER_H

#include "player.h"
#include "floor.h"

class CollisionsManager {
public:
    CollisionsManager();
    void detect_collision(Player &player, Floor &floor);
};

#endif // COLLISIONSMANAGER_H
