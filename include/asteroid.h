/* asteroid.h */
#ifndef ASTEROID_H
#define ASTEROID_H

#include "game_object.h"

extern int ASTEROID_SPEED_IN_PIXELS_PER_SECOND;
extern int asteroidMovement(float deltaTime, GameObject *asteroid);

#endif /* asteroid.h */