#include "application.h"
#include "global.h"
#include <SDL2/SDL.h>
#include <iostream>

Application::Application() : SDLApp(WINDOW_TITLE, W, H, FPS){}

void Application::draw() {
    SDL_SetRenderDrawColor(this->renderer, 51, 51, 51, 255);
    SDL_RenderClear(this->renderer);
}

void Application::events() {
    SDL_Event ev;
    while(SDL_PollEvent(&ev)) {
        switch(ev.type) {
        case SDL_QUIT:
            this->close(0);
            break;
        case SDL_KEYDOWN:
            // carattere premuto -> ev.key.keysym.sym;
            break;
        case SDL_MOUSEBUTTONDOWN:
            // coordinate mouse -> ev.button.x ev.button.y
            break;
        }
    }
}
