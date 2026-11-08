#include <SDL3/SDL.h>
#include "asteroids.h"

int playerMovement(float deltaTime) {
  // distance moved = speed * delta_time
  // delta_time is elapsed time

  const bool *keyStates = SDL_GetKeyboardState(NULL);
  float distance = 0;
  float upMovement = 0;
  float downMovement = 0;
  float leftMovement = 0;
  float rightMovement = 0;
  distance = 300 * (deltaTime/1000.0);

  if(keyStates[SDL_SCANCODE_W]) {
    upMovement += distance;
    SDL_Log("You moved up by %f\n", upMovement);
  }
  
  if(keyStates[SDL_SCANCODE_S]) {
    downMovement += distance;
    SDL_Log("You moved down by %f\n", downMovement);
  }
  
  if(keyStates[SDL_SCANCODE_A]) {
    leftMovement += distance;
    SDL_Log("You moved left by %f\n", leftMovement);
  }
  
  if(keyStates[SDL_SCANCODE_D]) {
    rightMovement += distance;
    SDL_Log("You moved right by %f\n", rightMovement);
  }
  
  return 0;
}