#ifndef VIRUS_INCLUDED
#define VIRUS_INCLUDED

#include "MySDL.h"
#include "Coord.h"
#include "Unit.h"

/*! A Virus, be careful!
 */
class Virus : public Unit
{
public:
  Virus()
  {
  }

  /*! Creates a Virus
    @param pos start position
    @param speed start speed
   */
  Virus(Coord pos, Coord speed, int radius=10) : Unit{pos, radius, speed}
  {
  }

  /*! Draws the Virus
    @param mySDL for the size of the window
   */
  void draw(MySDL &mySDL) const
  {
    filledCircleColor(mySDL.renderer(), pos.x, pos.y, radius, color(0, 255, 0));
  }
};

#endif
