
all: bison flex gcc
	@echo "Done."

bison: parser.y
	bison parser.y

flex: scanner.l
	flex scanner.l

gcc: scanner.c parser.c tables.c types.c ast.c interpreter.c
	gcc -Wall -Wconversion -o lab06 scanner.c parser.c tables.c types.c ast.c interpreter.c

clean:
	@rm -f *.o *.output scanner.c parser.h parser.c *.dot *.pdf lab06
