#include<stdio.h>
#include<time.h>

double factorial(int n){
    if(n < 0){
        printf("Invalid Input");
        return 0;
    }
    if(n <= 1){
        return 1;
    }
    return n*factorial(n-1);
}
int main(){
    int st, et, tt;
    int n = 50;
    st = clock();
    printf("Factorial: %lf\n", factorial(n));
    et = clock();
    tt = et - st;
    printf("Time: %dms", tt);
    return 0;
}
