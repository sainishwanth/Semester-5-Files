PROG1 = Final_Knapsack.c

PROG2 = ui_curses.c

PROG3 = Debug_Knapsack.c

FILE1 = knapsack

FLAG1 = lncurses

CC = gcc

CFAGS = -lncurses.

make:
	$(CC) -o $(FILE1) $(PROG1) $(PROG2) -$(FLAG1)&& ./$(FILE1)

debug:
	$(CC) -o $(FILE1) $(PROG3) $(PROG2) -$(FLAG1)&& ./$(FILE1)
