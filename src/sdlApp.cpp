#include "sdlApp.h"
#include <SDL2/SDL.h>
#include <iostream>

// Application's constructor
SDLApp::SDLApp(std::string title, int _w, int _h, int _fps) : fps(_fps) {
  window =
      SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_UNDEFINED,
                       SDL_WINDOWPOS_UNDEFINED, _w, _h, SDL_WINDOW_RESIZABLE);
  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
  if (!window || !renderer) {
    std::cout << "Error initializing window or renderer: " << SDL_GetError()
              << std::endl;
    close(-1);
  }
  this->continueRunning = true;
}

// Application's core: return the value sent with close()
int SDLApp::runApp() {
  Uint32 beforeRenderTime;
  Uint32 afterRenderTime;
  while (this->continueRunning) {
    beforeRenderTime = SDL_GetTicks();
    SDL_GetWindowSize(this->window, &w, &h);
    draw();
    events();
    SDL_RenderPresent(this->renderer);
    afterRenderTime = SDL_GetTicks();
    if (afterRenderTime - beforeRenderTime < floor(1000 / fps)) {
      SDL_Delay(floor(1000 / this->fps - (afterRenderTime - beforeRenderTime)));
    }
  }
  return this->returnValue;
}

// Close the application with _ritorno value.
void SDLApp::close(int _returnValue) {
  this->returnValue = _returnValue;
  this->continueRunning = false;
  SDL_DestroyRenderer(this->renderer);
  SDL_DestroyWindow(this->window);
  SDL_Quit();
}
