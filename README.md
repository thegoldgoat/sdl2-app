# sdl2-app
SDL2 application template class.

# How to use

Create your own application class, which needs to be a public SDLApp:<br>
` class Application : public SDLApp `<br>
This class needs 2 methos: <br>``void draw(void)`` and <br>``void events(void)``.<br>
These methods are called by sdlApp after launching yourApp.runApp().<br>
To stop and close the app your class need to call the close method<br>
A basic class and main template are included in the repository. (src/application.* and src/main.cpp)
