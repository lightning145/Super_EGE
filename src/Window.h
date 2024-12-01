#ifndef WINDOW_H
#define WINDOW_H

#include <SDL.h>

class Window
{
public:
   Window(int width,int height,bool wind);
   ~Window();

   void SetTitle(const char* t);

   int getch();

   SDL_Window* window;

private:
   SDL_GLContext glc;
   SDL_Event event;

};

#endif