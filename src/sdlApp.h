#ifndef _SDLAPP_H
#define _SDLAPP_H

#include <SDL2/SDL.h>
#include <iostream>

class SDLApp {
 public:
  SDLApp(std::string title, int _w, int _h, int _fps);
  void close(int);
  int runApp();
  // Application functions
  virtual void draw(){};
  virtual void events(){};

 protected:
  SDL_Window *window;
  SDL_Renderer *renderer;
  int w, h;

 private:
  bool continueRunning;
  int returnValue;
  int fps;
};

#endif  // _SDLAPP_H