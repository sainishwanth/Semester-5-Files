#include<stdio.h>
#include<stdlib.h>
#define gotoxy(x,y) printf("\033[%d;%dH", (y), (x))
int main(){
    printf("Hello1");
    gotoxy(10,4);
    printf("Hello2");
    char cmd[]="\033[6n";
}