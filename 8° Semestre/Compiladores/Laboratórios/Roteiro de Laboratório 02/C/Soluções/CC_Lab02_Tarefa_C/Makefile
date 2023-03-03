
all: bison flex gcc
	@echo "Done."

bison: parser.y
	bison parser.y

flex: scanner.l
	flex scanner.l

gcc: scanner.c parser.c
	gcc -Wall -o lab02 scanner.c parser.c

clean:
	@rm -f *.o *.output scanner.c parser.h parser.c lab02
