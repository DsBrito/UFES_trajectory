# Makefile

all: compile

compile: main.o aresta.o Arquivo.o ponto.o subconjunto.o vertice.o lista.o
	gcc -o  trab1 main.o aresta.o Arquivo.o ponto.o subconjunto.o vertice.o lista.o  -lm  -g

main.o: ./main.c
	gcc -o main.o -c ./main.c 

aresta.o: ./aresta.c
	gcc -o aresta.o -c ./aresta.c

Arquivo.o: ./Arquivo.c
	gcc -o Arquivo.o -c ./Arquivo.c

ponto.o: ./ponto.c
	gcc -o ponto.o -c ./ponto.c

subconjunto.o: ./subconjunto.c
	gcc -o subconjunto.o -c ./subconjunto.c

vertice.o:
	gcc -o vertice.o -c ./vertice.c

lista.o:
	gcc -o lista.o -c ./lista.c

clean:
	rm -rf *.o *~ trab1
