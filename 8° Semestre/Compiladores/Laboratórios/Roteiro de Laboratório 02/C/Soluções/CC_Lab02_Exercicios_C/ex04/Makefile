
all: bison flex gcc
	@echo "Done."

bison: parser.y
	bison parser.y

flex: scanner.l
	flex scanner.l

gcc: scanner.c parser.c
	gcc -Wall -o ex04 scanner.c parser.c -ly

clean:
	@rm -f *.o *.output scanner.c parser.h parser.c ex04
