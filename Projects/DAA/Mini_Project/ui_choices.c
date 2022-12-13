# include<ncurses.h>

#define LENGTH 4
#define WIDTH 6


// int * choices_menu(WINDOW * menuChoice, int *profits, int * weights){

// }

void rectangle(){
    int y = LENGTH;
    int x = WIDTH;
    for(int i = 0; i < LENGTH; ++i){
        for(int j = 0; j < WIDTH; ++j){
            if(i==0||i==3||j==0||j==5){
                if(i == 1 || i == 2){
                    printw("| ");
                }else{
                 printw("- ");
                }
            }
            else{
                if(i == 1 && j == 2){
                    printw("%d", 10);
                }else if(i == 2 && j == 2){
                    printw("%d", 10);
                }else{
                printw("  ");
                }
            }
        }
        printw("\n");
        mvprintw()
    }
}

int main(){
    initscr();
    int x = getmaxx(stdscr);
    int y = getmaxy(stdscr);
    WINDOW * menuChoice = newwin(0, 0, 0, 0);
    int * profits = {1,2,3,4};
    int * weights = {1,2,3,4};
    int x_ = getcurx(stdscr);
    int y_ = getcury(stdscr);
    printw("X = %d, y = %d\n", x_, y_);
    rectangle();
    mvprintw(7, 5,"Hello");
    printw("X - %d, Y - %d\n", getcurx(stdscr), getcury(stdscr));
    rectangle();
    getch();
    return 0;
}