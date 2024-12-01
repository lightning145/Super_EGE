#include <glad\glad.h>
#include "Graphics.h"

#include "../include/super_ege.h"

void Graphics::clear(int a,int r,int g, int b)
{
    glClearColor((float)r,(float)g,(float)b,(float)a);
    glClear(GL_COLOR_BUFFER_BIT);
}

void Graphics::persent(SDL_Window* window)
{
    SDL_GL_SwapWindow(window);
}

