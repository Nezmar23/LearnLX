#include <unistd.h>
#include <stdlib.h>
#include <curses.h>

int main ()
{
	initscr();
	move(5,15);
	printw("%s","Nazdar");


	move(3,25);
        printw("%s","AHOJ");
	refresh();
	sleep(10);
	endwin();
        exit(EXIT_SUCCESS);
}


