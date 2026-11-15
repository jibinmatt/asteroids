/* asteroids.h */
#ifndef PLAYERMOVEMENT_H
#define PLAYERMOVEMENT_H

//initialize Player Instance
typedef struct {
  float xPosition;
  float yPosition;
  float velocityX;
  float velocityY;
  float acceleration;
  float rotation;
} GameObject;

extern int playerMovement(float deltaTime, GameObject *player);
extern int asteroidMovement(float deltaTime, GameObject *asteroid);
extern int PLAYER_SPEED_IN_PIXELS_PER_SECOND;
extern int ASTEROID_SPEED_IN_PIXELS_PER_SECOND;

#endif /* asteroids.h */