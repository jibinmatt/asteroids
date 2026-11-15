#include <SDL3/SDL.h>
#include "spaceship.h"

int ASTEROID_SPEED_IN_PIXELS_PER_SECOND = 200; // will be dynamic

int asteroidMovement(float deltaTime, GameObject *asteroid) {
  // distance moved = speed * delta_time
  // delta_time is elapsed time

  const bool *keyStates = SDL_GetKeyboardState(NULL);
  float distance = 0;
  distance = ASTEROID_SPEED_IN_PIXELS_PER_SECOND * (deltaTime/1000.0);

  // random asteroid movement implementation
  
  // SDL_Log("Asteroid position: \n%f\n%f\n\n", (*asteroid).xPosition, (*asteroid).yPosition);
  
  return 0;
}