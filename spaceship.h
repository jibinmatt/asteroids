/* spaceship.h */
#ifndef SPACESHIP_H
#define SPACESHIP_H

// Define Player Instance
typedef struct {
  float xPosition;
  float yPosition;
  float velocityX;
  float velocityY;
  float acceleration;
  float rotation;
} GameObject;

extern int PLAYER_SPEED_IN_PIXELS_PER_SECOND;
extern int playerMovement(float deltaTime, GameObject *player);

#endif /* spaceship.h */