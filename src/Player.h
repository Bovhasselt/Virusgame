#ifndef PLAYER_INCLUDED
#define PLAYER_INCLUDED

#include "MySDL.h"
#include "Coord.h"
#include "Unit.h"

/*! The object representing the player in VirusGame
 */
class Player : public Unit
{
public:
    /*! Creates the Player
      @param pos start position
     */
    Player(Coord pos, int radius=24) : Unit{pos, radius}
    {
    }

    /*! Handles the keyboard events
      @param keyboardState the current state (keys pressed) of the keyboard
     */
    void keyboard(const Uint8 *keyboardState)
    {
        double diff_speed = 0.5;
        // for others keys see: https://wiki.libsdl.org/SDL_Scancode
        if (keyboardState[SDL_SCANCODE_UP])
            speed.y -= diff_speed;
        if (keyboardState[SDL_SCANCODE_DOWN])
            speed.y += diff_speed;
        if (keyboardState[SDL_SCANCODE_LEFT])
            speed.x -= diff_speed;
        if (keyboardState[SDL_SCANCODE_RIGHT])
            speed.x += diff_speed;
        if (keyboardState[SDL_SCANCODE_B] && radius < 75)
            radius += 1;
        if (keyboardState[SDL_SCANCODE_S] && radius > 15)
            radius -= 1;

        speed *= 0.95; // reduce speed to create some resistance
    }

    /*! Draws the Player
      @param mySDL for the size of the window
     */
    void draw(MySDL &mySDL) const
    {
        aacircleColor(mySDL.renderer(), pos.x, pos.y, radius, color(255, 255, 255));
    }
};

#endif
