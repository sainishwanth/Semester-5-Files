#include<stdio.h>

void linear(int *a, int n, int num){
    for(int i = 0; i < n; ++i){
        if(a[i] == num){
            printf("Number %d found at position%d", num, i);
            return;
        }
    }
    printf("Number not Found");
}

int main(void){
    int a[10] = {0,2,3,4,5,1,2,3,4,10};
    int num;
    printf("Enter a number to Search for: ");
    scanf("%d", &num);
    linear(a, 10, num);
    return 0;
}