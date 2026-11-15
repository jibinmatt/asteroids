#include <SDL3/SDL.h>
#include "asteroids.h"

int PLAYER_SPEED_IN_PIXELS_PER_SECOND = 300;
int ASTEROID_SPEED_IN_PIXELS_PER_SECOND = 200; // will be dynamic

int playerMovement(float deltaTime, GameObject *player) {
  // distance moved = speed * delta_time
  // delta_time is elapsed time
  // velocity is change in distance by time;
  // acceleration is change in velocity divided by time.

  const bool *keyStates = SDL_GetKeyboardState(NULL);
  float distance = 0;
  float deltaTimeInSeconds = deltaTime/1000.0;
  distance = PLAYER_SPEED_IN_PIXELS_PER_SECOND * deltaTimeInSeconds;

  // WASD Movement
  if(keyStates[SDL_SCANCODE_W]) {
    player->velocityY += player->acceleration * deltaTimeInSeconds;
    player->yPosition -= player->velocityY * deltaTimeInSeconds;
    SDL_Log("You moved up by %f\n", player->yPosition);
  }
  
  if(keyStates[SDL_SCANCODE_A]) {
    player->velocityX += player->acceleration * deltaTimeInSeconds;
    player->xPosition -= player->velocityX * deltaTimeInSeconds;
    SDL_Log("You moved left by %f\n", player->xPosition);
  }
  
  if(keyStates[SDL_SCANCODE_S]) {
    player->velocityY += player->acceleration * deltaTimeInSeconds;
    player->yPosition += player->velocityY * deltaTimeInSeconds;
    SDL_Log("You moved down by %f\n", player->yPosition);
  }
  
  if(keyStates[SDL_SCANCODE_D]) {
    player->velocityX += player->acceleration * deltaTimeInSeconds;
    player->xPosition += player->velocityX * deltaTimeInSeconds;
    SDL_Log("You moved right by %f\n", player->xPosition);
  }
  
  return 0;
}

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