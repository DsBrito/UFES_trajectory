


# Componentes do Grupo: Dionatas Santos Brito e Filipe Ferreira de Oliveira


OBJS = ./build/main.o ./build/psh.o ./build/cmd.o

SOURCE = main.c psh.c cmd.c

OUT = psh
CC	 = gcc
FLAGS = -c -DNDEBUG -std=gnu11
LFLAGS	 = -lm

all: | mkBuildDir $(OBJS)
	$(CC) $(OBJS) -o $(OUT) $(LFLAGS)

build/main.o: main.c
	$(CC) $(FLAGS) main.c -o ./build/main.o

build/psh.o: psh.c
	$(CC) $(FLAGS) psh.c -o ./build/psh.o

build/cmd.o: cmd.c
	$(CC) $(FLAGS) cmd.c -o ./build/cmd.o


clean:
	rm -rf build/

mkBuildDir:
	@if [ ! -d "./build/" ]; then \
		mkdir build; \
	fi

run:
	./psh
