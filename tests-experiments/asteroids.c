#include <stdio.h>
#include <SDL3/SDL.h>
#include "asteroids.h"

int playerMovement() {

  const bool *keyStates = SDL_GetKeyboardState(NULL);
  
  if(keyStates[SDL_SCANCODE_W]) {
    SDL_Log("You pressed up!");
  }

  if(keyStates[SDL_SCANCODE_S]) {
    SDL_Log("You pressed down!");
  }

  if(keyStates[SDL_SCANCODE_A]) {
    SDL_Log("You pressed left!");
  }

  if(keyStates[SDL_SCANCODE_D]) {
    SDL_Log("You pressed right!");
  }
      
}