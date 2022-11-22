#include<stdio.h>

int main(){
    for(int i = 0; i < 4; ++i){
        for(int j = 0; j < 6; ++j){
            if(i==0||i==3||j==0||j==5){
                 printf("* ");
            }
            else{
                if(i == 1 && j == 2){
                    printf("20");
                }else if(i == 2 && j == 2){
                    printf("30");
                }else{
                printf("  ");
                }
            }
        }
        printf("\n");
    }
}