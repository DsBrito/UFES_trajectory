
all: bison flex gcc
	@echo "Done."

bison: parser.y
	bison parser.y

flex: scanner.l
	flex scanner.l

gcc: scanner.c parser.c tables.c types.c ast.c code.c
	gcc -Wall -Wconversion -o lab07 scanner.c parser.c tables.c types.c ast.c code.c

tm: tm.c tables.c types.c
	gcc -Wall -Wconversion -o tmsim tm.c tables.c types.c

clean:
	@rm -f *.o *.output scanner.c parser.h parser.c *.dot *.pdf lab07 tmsim
