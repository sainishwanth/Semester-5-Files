#include<ncurses.h>

int main_menu(WINDOW * menuwin, char * options[]){
    // initscr();

    // int X, Y;
    // getmaxyx(stdscr, Y, X);

    // WINDOW * menuwin = newwin(6, X-X/2, Y-Y/2, 5);
    // box(menuwin, 0, 0);
    // refresh();
    // wrefresh(menuwin);
    // keypad(menuwin, true);

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
            if(highlights < 0){
                highlights = 0;
            }
            break;
        case KEY_DOWN:
            highlights++;
            if(highlights > 1){
                highlights = 1;
            }
            break;
        default:
            break;
        }
        if(choice == 10){
            return highlights;
        }
    }
}