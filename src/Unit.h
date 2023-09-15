#ifndef UNIT_INCLUDED
#define UNIT_INCLUDED

#include "MySDL.h"
#include "Coord.h"

class Unit
{
public:
  Unit()
  {
  }

  /*! Creates a Unit
    @param pos start position
    @param speed start speed
   */
  Unit(Coord pos, int radius, Coord speed = Coord{0, 0}) : pos{pos}, speed{speed}, radius{radius}
  {
  }

  /*! Makes a step in time
    @param mySDL for the size of the window
   */
  void step(MySDL &mySDL)
  {
    pos += speed;
    if (pos.x < 0 || pos.x > mySDL.size().x)
    {
      speed.x = -speed.x;
    }
    if (pos.y < 0 || pos.y > mySDL.size().y)
    {
      speed.y = -speed.y;
    }
  }

  Coord position() const { return pos; }

  /*! Draws the Unit
    @param mySDL for the size of the window
   */
  virtual void draw(MySDL &mySDL) const = 0;

  /*! Handles the keyboard events
    @param keyboardState the current state (keys pressed) of the keyboard
   */
  virtual void keyboard(const Uint8 *keyboardState){};

  /*! Returns the radius of the Unit
   */
  int getRadius() { return radius;}

  Coord pos, speed;
  int radius;
};

#endif