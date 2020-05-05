#ifndef MYSQL_INCLUDED
#define MYSQL_INCLUDED

#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>
#include "Coord.h"

class MySDL
{
public:
    MySDL(std::string title="MyWindow",int width=800,int height=600)
    {
        if (SDL_Init(SDL_INIT_VIDEO)<0)
        { std::cerr<<"SDL, failed to SDL_Init: "<<SDL_GetError()<<'\n';exit(1);}
        if ((_window=SDL_CreateWindow(title.c_str(),
                                      SDL_WINDOWPOS_UNDEFINED,
                                      SDL_WINDOWPOS_UNDEFINED,
                                      width,
                                      height,
                                      SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE))==NULL)
        { std::cerr<<"SDL, failed to SDL_CreateWindow: "<<SDL_GetError()<<'\n';exit(1);}
        if ((_renderer=SDL_CreateRenderer(_window,-1,SDL_RENDERER_ACCELERATED))==NULL)
        { std::cerr<<"SDL, failed to SDL_CreateRenderer: "<<SDL_GetError()<<'\n';exit(1);}
    }
    
    ~MySDL()
    {
        if (_renderer!=NULL)    SDL_DestroyRenderer(_renderer);
        if (_window!=NULL)      SDL_DestroyWindow(_window);
        SDL_Quit();
    }

    SDL_Window*   window()         { return _window;      }
    SDL_Renderer* renderer()       { return _renderer;    }
    
    Coord size()
    {
        int x,y;
        SDL_GetWindowSize(_window,&x,&y);
        return Coord(x,y);
    }
    
private:
    SDL_Window*      _window=NULL;
    SDL_Renderer*    _renderer=NULL;
};

using Color=Uint32;
Color color(Uint8 red,Uint8 green,Uint8 blue,Uint8 alpha)
{
    Uint8 c[]={red,green,blue,alpha};
    return *((Color*)c);
}
Color color(Uint8 red,Uint8 green,Uint8 blue)
{   return color(red,green,blue,255); }

#endif
