
all: flex gcc
	@echo "Done."

flex: scanner.l
	flex scanner.l

gcc: scanner.c
	gcc -Wall -o lab01 scanner.c -lfl

clean:
	@rm -f scanner.c lab01
