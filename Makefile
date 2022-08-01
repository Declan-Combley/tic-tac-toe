cc=gcc
bin=tic-tac-toe
flags= -Wall -Wextra

tic-tac-toe: main.c
	$(cc) main.c -o $(bin) $(flags)
