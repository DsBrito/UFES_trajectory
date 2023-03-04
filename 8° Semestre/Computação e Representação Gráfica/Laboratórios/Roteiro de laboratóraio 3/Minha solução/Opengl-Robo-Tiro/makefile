all: g++
	@echo "Done."

g++: *.cpp
	g++ -o r *.cpp -lGL -lGLU -lglut
	./r

clean:
	@rm -f *.o r