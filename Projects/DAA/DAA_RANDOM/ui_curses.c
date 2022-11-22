#include<ncurses.h>

int display(){
    initscr();

    noecho();
    cbreak();

    int X, Y;
    getmaxyx(stdscr, Y, X);

    WINDOW * menuwin = newwin(6, X-X/2, Y-Y/2, 5);
    box(menuwin, 0, 0);
    refresh();
    wrefresh(menuwin);
    keypad(menuwin, true);

    char options[2][15] = {"Custom Input", "Random Input"};
    int choice;
    int highlights = 0;

    while(true){
        for(int i = 0; i < 2; ++i){
            if(i == highlights){
                wattron(menuwin, A_REVERSE);
            }
            mvwprintw(menuwin, i+1, 1, options[i]);
            wattroff(menuwin, A_REVERSE);
        }
        choice = wgetch(menuwin);

        switch (choice)
        {
        case KEY_UP:
            highlights--;
            break;
        case KEY_DOWN:
            highlights++;
            break;
        default:
            break;
        }
        if(choice == 10){
            break;
        }
    }


    getch();
    endwin();
}