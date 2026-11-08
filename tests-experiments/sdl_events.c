#include <SDL3/SDL.h>

int main() {

  // variables
  SDL_Window *window;
  bool sdlInitialized;
  bool isRunning = true;

  // initialize SDL
  sdlInitialized = SDL_Init(SDL_INIT_VIDEO);

  if (sdlInitialized == false) {
    SDL_LogError(SDL_LOG_CATEGORY_ERROR, "Could not initialize SDL: %s\n", SDL_GetError());
    SDL_Quit();
    return 1;
  }

  // initialize game window
  window = SDL_CreateWindow("Asteroids", 800, 600, SDL_WINDOW_RESIZABLE);

  if (window == NULL) {
    SDL_LogError(SDL_LOG_CATEGORY_ERROR, "Could not create window: %s\n", SDL_GetError());
    SDL_Quit();
    return 1;
  }


  // Game loop/event loop
  while(isRunning) {

    SDL_Event event;
    
    while (SDL_PollEvent(&event)){
      
      if(event.type == SDL_EVENT_KEY_DOWN) {
        SDL_Keymod keyModState;
        SDL_Keycode keyPressed;

        keyModState = event.key.mod;
        keyPressed = event.key.key;

        SDL_Log("Key modifier: %u\n", (unsigned int)keyModState);
        SDL_Log("Key pressed: %s\n", SDL_GetKeyName(keyPressed));
      }

      // User requested close event
      if(event.type == SDL_EVENT_QUIT) {
        isRunning = false;
      }
    }
    SDL_Delay(1); // Replace with proper Frame-Timing later
  }

  // cleanup and destroy window
  SDL_DestroyWindow(window);
  SDL_Quit();
  return 0;
}