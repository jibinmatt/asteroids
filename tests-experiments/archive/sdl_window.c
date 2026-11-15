#include <SDL3/SDL.h>

int main() {

  SDL_Window *window;
  bool sdlInitialized;

  sdlInitialized = SDL_Init(SDL_INIT_VIDEO);

  if (sdlInitialized == false) {
    SDL_LogError(SDL_LOG_CATEGORY_ERROR, "Could not initialize SDL: %s\n", SDL_GetError());
    SDL_Quit();
    return 1;
  }

  window = SDL_CreateWindow("Asteroids", 800, 600, SDL_WINDOW_RESIZABLE);

  if (window == NULL) {
    SDL_LogError(SDL_LOG_CATEGORY_ERROR, "Could not create window: %s\n", SDL_GetError());
    SDL_Quit();
    return 1;
  }

  SDL_Delay(5000);
  SDL_DestroyWindow(window);
  SDL_Quit();
  return 0;
}