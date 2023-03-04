all: g++
	@echo "Makefile Ok."

g++: *.cpp
	g++ -o trabalhocg main.cpp 3D_interface/*.cpp 2D_interface/*.cpp 3D_tools/*.cpp 2D_tools/*.cpp tinyxml/*.cpp  -lGL -lGLU -lglut
	
clean:
	@rm -f *.o trabalhocg
