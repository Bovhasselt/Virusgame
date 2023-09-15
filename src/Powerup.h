#ifndef POWERUP_INCLUDED
#define POWERUP_INCLUDED

#include "MySDL.h"
#include "Coord.h"
#include "Unit.h"

/*! A Virus, be careful!
 */
class PowerUp : public Unit
{
public:
  PowerUp()
  {
  }

  /*! Creates a Virus
    @param pos start position
    @param speed start speed
   */
  PowerUp(Coord pos, Coord speed, int radius = 7) : Unit{pos, radius, speed}
  {
  }

  /*! Draws the Virus
    @param mySDL for the size of the window
   */
  void draw(MySDL &mySDL) const
  {
    filledCircleColor(mySDL.renderer(), pos.x, pos.y, radius, color(255, 0, 0));
  }
};

#endif