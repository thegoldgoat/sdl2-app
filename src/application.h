#ifndef _APPLICAZIONE_H
#define _APPLICAZIONE_H
#include "sdlApp.h"

class Application : public SDLApp {
public:
// Public variables and method
  Application();
  void draw(void);
  void events(void);
private:
// Private variables and method

};


#endif