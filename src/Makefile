CC   = g++
LIBS = -lSDL2 -lSDL2_gfx
PROG = VirusGame
FLAGS = -std=c++17 -Wall -Wextra -pedantic -Werror

all: 	$(PROG)

%: %.cpp
	$(CC) $(FLAGS) -o $@ $< $(LIBS)

clean: 
	rm -f $(PROG)
