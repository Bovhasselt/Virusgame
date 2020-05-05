#ifndef VIRUS_INCLUDED
#define VIRUS_INCLUDED

#include "MySDL.h"
#include "Coord.h"

class Virus
{
public:
    Virus()
    {}
    
    Virus(Coord pos,Coord speed) :
        pos{pos}, speed{speed}
    {}

    void step(MySDL& mySDL)
    {
        pos+=speed;
        if (pos.x<0 or pos.x>mySDL.size().x)
        { speed.x=-speed.x; }
        if (pos.y<0 or pos.y>mySDL.size().y)
        { speed.y=-speed.y; }
    }

    void draw(MySDL& mySDL)
    {
        filledCircleColor(mySDL.renderer(), pos.x, pos.y, radius, color(0,255,0));
    }
    
private:
    static const int radius=10;
    Coord pos,speed;
};

#endif
