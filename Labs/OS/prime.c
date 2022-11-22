#include<stdio.h>

int main(){
    int n;
    int check;
    printf("Enter a Number: ");
    scanf("%d", &n);
    printf("The Prime Numbers upto %d are\n", n);
    for(int i = 3; i < n; ++i){
        check = 0;
        for(int j = 2; j < i; ++j){
            if(i % j == 0){
                check = 1;
                break;
            }
        }
        if(!check){
            printf("%d,", i);
        }
    }
    return 0;
}
