#include <vector>
#include <algorithm>

#include "Utils.h"
#include "MySDL.h"
#include "Coord.h"
#include "Player.h"
#include "Virus.h"
#include "Powerup.h"
#include "Unit.h"

const int SCREEN_FPS = 60;
const int SCREEN_TICKS_PER_FRAME = 1000 / SCREEN_FPS;

/*! @file
   The starting point of VirusGame, holds the main() function.
*/
extern "C" int main()
{
    std::cout << "Use the cursor keys to move around\n";
    srand(time(NULL));        // seed the speudo random number generator
    MySDL mySDL("VirusGame"); // create an SDL graphics window
    bool quit = false;        // quit flag
    int score = 0;            // the score of the player

    Player player = Player(mySDL.size() * 0.5); // player is the first unit
    Coord click_pos;                            // position of the last mouse click
    std::vector<Unit *> units = {&player};      // holds all units in the game
    int nr_units = 1;                           // current number of units

    const int max_nr_units = 21;       // maximum number of units, feel free to change
    double new_virus_chance = 0.01;    // the chance that a new virus is created each time step
    double new_powerup_chance = 0.003; // the chance that a new powerup is created each time step
    double new_virus_max_speed = 3;    // maximum speed of a new virus

    auto handle_unit = [&mySDL](Unit *unit)
    {
        unit->step(mySDL);
        unit->draw(mySDL);
    }; // lambda function to handle a unit
    auto check_collide = [&player, &score, &quit, &units](Unit *unit)
    {
        if (player.pos.distance(unit->pos) < player.radius + unit->getRadius())
        {
            // if unit is virus
            if (dynamic_cast<Virus *>(unit) != nullptr)
            {
                std::cout << "Game over, score: " << score << '\n';
                quit = true;
            }
            // if unit is powerup
            else if (dynamic_cast<PowerUp *>(unit) != nullptr)
            {
                score += 500000;
                units.erase(std::remove(units.begin(), units.end(), unit), units.end());
            }
        }
    }; // lambda function to check if a Virus collides with the player
    auto check_click = [&click_pos, &units, &nr_units, &score](Unit *unit)
    {
        // if unit is not virus continue
        if (dynamic_cast<Virus *>(unit) == nullptr)
            return;
        if (click_pos.distance(unit->pos) < unit->getRadius())
        {
            nr_units--;
            units.erase(std::remove(units.begin(), units.end(), unit), units.end());
            score += 500000;
        }
    }; // lambda function to check if a mouse click is on a virus and if so remove it

    while (!quit) // the game loop, this loops has gotten large, better split it up in multiple functions?
    {
        int ticks_start = SDL_GetTicks();
        SDL_SetRenderDrawColor(mySDL.renderer(), 0, 0, 0, 255); // black background
        SDL_RenderClear(mySDL.renderer());                      // clear graphics window

        SDL_Event e;
        while (SDL_PollEvent(&e)) // handle events
        {
            int x, y;
            switch (e.type)
            {
            case SDL_QUIT:
                quit = true;
                break;
            case SDL_MOUSEBUTTONDOWN:
                SDL_GetMouseState(&x, &y);
                std::cout << "mouse down: " << x << "," << y << '\n';
                click_pos = Coord(x, y);
                std::for_each(units.begin() + 1, units.end(), check_click); // check if any virus is clicked
                break;
            }
        }

        const Uint8 *keyboardState = SDL_GetKeyboardState(NULL); // get keyboard state
        units[0]->keyboard(keyboardState);                       // control the player by keyboard

        if (rand_0_1() < new_virus_chance && nr_units < max_nr_units) // by chance create a new virus
        {
            Coord window_size = mySDL.size();
            Coord pos = Coord(window_size.x * rand_0_1(), window_size.y * rand_0_1());
            Coord speed = Coord(new_virus_max_speed * rand_m1_1(), new_virus_max_speed * rand_m1_1());
            Virus *virus = new Virus(pos, speed);
            units.push_back(virus);
            nr_units += 1;
        }

        // by chance create a new powerup
        if (rand_0_1() < new_powerup_chance)
        {
            Coord window_size = mySDL.size();
            Coord pos = Coord(window_size.x * rand_0_1(), window_size.y * rand_0_1());
            Coord speed = Coord(new_virus_max_speed * rand_m1_1(), new_virus_max_speed * rand_m1_1());
            PowerUp *powerup = new PowerUp(pos, speed);
            units.push_back(powerup);
        }

        std::for_each(units.begin(), units.end(), handle_unit); // handle all units

        std::for_each(units.begin() + 1, units.end(), check_collide); // check if any virus collides with the player

        // draw score bar
        score += pow(player.radius, 2); // increase score
        SDL_Rect score_bar = {0, 0, int(mySDL.size().x * double(score) / 30000000), 10};
        SDL_SetRenderDrawColor(mySDL.renderer(), 255, 0, 0, 255);
        SDL_RenderFillRect(mySDL.renderer(), &score_bar);

        SDL_RenderPresent(mySDL.renderer()); // update graphics window
        int frame_ticks = SDL_GetTicks() - ticks_start;
        if (frame_ticks < SCREEN_TICKS_PER_FRAME)
            SDL_Delay(SCREEN_TICKS_PER_FRAME - frame_ticks); // delay for right framerate
    }
    return 0;
}
