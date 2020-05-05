CC   = g++
LIBS = -lSDL2 -lSDL2_gfx
PROG = VirusGame

all: 	$(PROG)

%: %.cpp
	$(CC) $(CXXFLAGS) -o $@ $< $(LIBS)

clean: 
	rm -f $(PROG)
