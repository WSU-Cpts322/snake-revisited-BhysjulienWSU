#include <ncurses.h>
#include <iostream>

using namespace std;

int main()
{
    initscr();
    cbreak();
    noecho();
    scrollok(stdscr, TRUE);
    nodelay(stdscr, TRUE);
    keypad(stdscr, TRUE);

    int i = 0;

    while (true)
    {
	char c = getch();
	int  delay = 100;	
	printw("------------------\n");
	for(int j = 0; j < 10; j++)
	{
		printw("|                |\n");
	}
		printw("|      %c         |\n", c);
		delay = 200;
		printw("|                |\n");
	for(int j = 0; j < 10; j++)
	{
		printw("|                |\n");
	}
	printw("-----------------\n");
	refresh();
        napms(delay);

	erase();

	i++;
    }
}
