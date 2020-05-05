#ifndef PLAYER_INCLUDED
#define PLAYER_INCLUDED

#include "MySDL.h"
#include "Coord.h"

class Player
{
public:
    Player(Coord pos) :
        pos{pos}
    {}

    void keyboard(const Uint8* keyboardState)
    {
        double diff_speed=0.5;
        // for keys see: https://wiki.libsdl.org/SDL_Scancode
        if (keyboardState[SDL_SCANCODE_UP])
            speed.y-=diff_speed;
        if (keyboardState[SDL_SCANCODE_DOWN])
            speed.y+=diff_speed;
        if (keyboardState[SDL_SCANCODE_LEFT])
            speed.x-=diff_speed;
        if (keyboardState[SDL_SCANCODE_RIGHT])
            speed.x+=diff_speed;
        // if (keyboardState[SDL_SCANCODE_A])
        speed*=0.95; // reduce speed to create some resistance
    }
    
    void step(MySDL& mySDL)
    {
        pos+=speed;
        if (pos.x<0 or pos.x>mySDL.size().x)
        { speed.x=-speed.x; }
        if (pos.y<0 or pos.y>mySDL.size().y)
        { speed.y=-speed.y; }
    }

    void draw(MySDL& mySDL)
    {   aacircleColor(mySDL.renderer(), pos.x, pos.y, radius, color(255,255,255)); }
    
private:
    static const int radius=24;
    Coord pos,speed;
};

#endif
