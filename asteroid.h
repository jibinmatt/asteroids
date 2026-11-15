/* asteroid.h */
#ifndef ASTEROID_H
#define ASTEROID_H

// Define Asteroid Instance
typedef struct {
  float xPosition;
  float yPosition;
  float velocityX;
  float velocityY;
  float acceleration;
  float rotation;
} GameObject;

extern int ASTEROID_SPEED_IN_PIXELS_PER_SECOND;
extern int asteroidMovement(float deltaTime, GameObject *asteroid);

#endif /* asteroid.h */