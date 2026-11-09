#include <SDL3/SDL.h>
#include "asteroids.h"

#define WINDOW_WIDTH 1000
#define WINDOW_HEIGHT 800

int main() {

  // SDL variables
  SDL_Window *window = NULL;
  SDL_Renderer *renderer = NULL;

  // Game variables
  bool isRunning = true;
  Uint64 timeElapsed;
  Uint64 tempCounter = 0;
  float deltaTime = 0;

  // player initialization
  GameObject player = {
    .xPosition = WINDOW_WIDTH/2.0,
    .yPosition =  WINDOW_HEIGHT/2.0,
    .velocityX = 100,
    .velocityY = 100,
    .acceleration = 10,
    .rotation = 0
  };
  
  // dummy asteroid for testing
  GameObject asteroid = {
    .xPosition = 400,
    .yPosition =  600,
    .velocityX = 0,
    .velocityY = 0,
    .acceleration = 0,
    .rotation = 0
  };

  // initialize SDL
  if (!SDL_Init(SDL_INIT_VIDEO)) {
    SDL_LogError(SDL_LOG_CATEGORY_ERROR, "Could not initialize SDL: %s\n", SDL_GetError());
    SDL_Quit();
    return 1;
  }

  // initialize game window
  if(!SDL_CreateWindowAndRenderer("Asteroids", WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_RESIZABLE, &window, &renderer)) {
    SDL_LogError(SDL_LOG_CATEGORY_ERROR, "Could not create window and renderer: %s\n", SDL_GetError());
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 1;
  }

  
  tempCounter = SDL_GetTicksNS();
  
  // Game loop/event loop
  while(isRunning) {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
      // other Keyboard events to be handled here
      
      // User requested close event
      if(event.type == SDL_EVENT_QUIT) {
        isRunning = false;
      }
    }
    
    // frame timing nonsense
    SDL_Delay(1); // Replace with proper Frame-Timing later
    timeElapsed = SDL_GetTicksNS(); // current timestamp
    deltaTime = (timeElapsed - tempCounter)/1000000.0;
    tempCounter = timeElapsed;
    
    // update Game Objects positions and movement and render to screen
    // background color
    if(!SDL_SetRenderDrawColor(renderer, 10, 10, 10, 255)) {
      SDL_LogError(SDL_LOG_CATEGORY_ERROR, "Could not update renderer color: %s\n", SDL_GetError());
      SDL_DestroyRenderer(renderer);
      SDL_DestroyWindow(window);
      SDL_Quit();
      return 1;
    }
    SDL_RenderClear(renderer);
    // spaceship color
    if(!SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255)) {
      SDL_LogError(SDL_LOG_CATEGORY_ERROR, "Could not update renderer color: %s\n", SDL_GetError());
      SDL_DestroyRenderer(renderer);
      SDL_DestroyWindow(window);
      SDL_Quit();
      return 1;
    }
    // SDL_Log("Delta time: %f ms", deltaTime);
    playerMovement(deltaTime, &player);
    asteroidMovement(deltaTime, &asteroid);

    // render spaceship
    if (!SDL_RenderLine(renderer, player.xPosition, player.yPosition-5, player.xPosition-5, player.yPosition+5)) {
      SDL_LogError(SDL_LOG_CATEGORY_ERROR, "Could not render spaceship: %s\n", SDL_GetError());
      SDL_DestroyRenderer(renderer);
      SDL_DestroyWindow(window);
      SDL_Quit();
      return 1;
    }

    if (!SDL_RenderLine(renderer, player.xPosition, player.yPosition-5, player.xPosition+5, player.yPosition+5)) {
      SDL_LogError(SDL_LOG_CATEGORY_ERROR, "Could not render spaceship: %s\n", SDL_GetError());
      SDL_DestroyRenderer(renderer);
      SDL_DestroyWindow(window);
      SDL_Quit();
      return 1;
    }

    if (!SDL_RenderLine(renderer, player.xPosition-5, player.yPosition+5, player.xPosition+5, player.yPosition+5)) {
      SDL_LogError(SDL_LOG_CATEGORY_ERROR, "Could not render spaceship: %s\n", SDL_GetError());
      SDL_DestroyRenderer(renderer);
      SDL_DestroyWindow(window);
      SDL_Quit();
      return 1;
    }

    SDL_RenderPresent(renderer);
  }

  // cleanup and destroy window
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
  return 0;
}