# VirusGame #
A simple game build using the SDL2 graphics library. Use
the cursor keys to move to escape/kill the viruses.

![Alt text](VirusGame.png)

## Install

### Linux/Mac:

Using the package manager on your system to install:

    cmake
    git
    libsdl2-dev
    libsdl2-gfx-dev

For example for Ubuntu use:

    sudo apt install cmake git libsdl2-dev libsdl2-gfx-dev

For a Mac probably something like (run 'brew search sdl2' to see which are available):

    brew install cmake git sdl2 sdl2_gfx

Then:

    git clone https://github.com/Bovhasselt/Virusgame.git
    cd virusgame/src
    mkdir build
    cd build
    cmake ..
    make
    ./VirusGame

### Windows:

Install [git](https://git-scm.com/download/win) and clone
[VirusGame](https://github.com/Bovhasselt/Virusgame.git).

Install [Visual Studio Studio Community
2019](https://visualstudio.microsoft.com/) and in the Visual Studio
Installer install Worksload "Desktop development with C++" (includes
CMake).

Install the SDL2 graphics library use
[vcpkg](https://github.com/Microsoft/vcpkg) by using:

    git clone https://github.com/Microsoft/vcpkg.git
    cd vcpkg
    .\bootstrap-vcpkg.bat
    .\vcpkg.exe integrate install
    .\vcpkg.exe install sdl2
    .\vcpkg.exe install sdl2-gfx --triplet x64-windows

Then in Visual Studio Studio Community 2019 open the virusgame/src
folder and build the project (F7) and run it (F5).


## Documentation
For documentation see the 
[list of classes]( http://sbt.science.uva.nl/bterwijn/virusgame/doc/html/annotated.html "Doxygen documentation")

## Authors
Bas Terwijn <<b.terwijn@uva.nl>>
Bo van Hasselt <<bovhasselt@gmail.com>>
...

## Description of extension on documentation by Bo van Hasselt
I have added: 
- termination of the game when the player comes in contact with a virus
- clicking on a virus kills it
- the player can get bigger or smaller with the keys 'b' and 's' respectively
- red units that earn you points when collected
- a score bar
You get points for  - surviving time, the bigger you are the more points
                    - killing viruses
                    - collecting reds


