#include "Graphics.h"
#include <iostream>
#include <string>
#include "../include/super_ege.h"
#include <glad\glad.h>

Window* graph;
Graphics gx;

Window::Window(int width,int height,bool wind)
{
    SDL_Init(SDL_INIT_EVERYTHING);

    Uint32 Mode;

    switch (wind)
    {
    case true:
        Mode = SDL_WINDOW_SHOWN|SDL_WINDOW_OPENGL;
        break;

    case false:
        Mode = SDL_WINDOW_SHOWN|SDL_WINDOW_OPENGL|SDL_WINDOW_FULLSCREEN;
        break;
    default:
        break;
    }

    window = SDL_CreateWindow(
        "Super EGE - OpenGL 3.3",
        SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,
        width,height,Mode
    );

    glc = SDL_GL_CreateContext(window);
	SDL_GL_MakeCurrent(window,glc);

	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

    gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress);

}

Window::~Window()
{
    SDL_DestroyWindow(window);
    SDL_GL_DeleteContext(glc);
    SDL_Quit;
}

void Window::SetTitle(const char* t)
{
    SDL_SetWindowTitle(window,t);
}

API(int) initgraph(int width,int height,bool windowed)
{
    graph = new Window(width,height,windowed);
    return 0;
}

API(void) closegraph()
{
    delete graph;
}

int Window::getch()
{
    while(SDL_PollEvent(&graph->event))
    {
        return(graph->event.type == SDL_QUIT);
        
    }
}

API(int) getch()
{
    return graph->getch();   
}

API(void) setcaption(const char*  caption)
{
    char* c = nullptr;
    c = const_cast<char*>(caption);

    std::string st = c;
    std::string ogl = " - OpenGL 3.3";
    std::string t = st + ogl;

    graph->SetTitle(t.c_str());
}

API(void) setbkcolor(int r,int g,int b,int a)
{
    return gx.clear(a,r,g,b);
}

API(void) present()
{
    return gx.persent(graph->window);
}


