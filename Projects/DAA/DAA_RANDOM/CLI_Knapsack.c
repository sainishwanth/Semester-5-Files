#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define gotoxy(x,y) printf("\033[%d;%dH", (y), (x))
int x = 10;
int y = 10;
int random_(int min, int max){
    return min + rand() / (RAND_MAX / (max - min + 1) + 1);
}
void random_assignment(int arr[],int n, int multiplier){
    for(int i = 0; i < n; ++i){
    arr[i] = random_(2,9) * multiplier;
    //printf("%d\t", arr[i]);
    }
}
int max(int a, int b){
    if (a > b){
        return a;
    }
    return b;
}
void rectangle(int p, int w){
    for(int i = 0; i < 4; ++i){
        for(int j = 0; j < 6; ++j){
            if(i==0||i==3||j==0||j==5){
                 printf("* ");
            }
            else{
                if(i == 1 && j == 2){
                    printf("%d", p);
                }else if(i == 2 && j == 2){
                    printf("%d", w);
                }else{
                printf("  ");
                }
            }
        }
        printf("\n");
    }
}
void Graphics(int p[], int w[], int n){
    for(int i = 0; i < n; ++i){
        if(i != 0 && i % 5 == 0){
            // printf("\033[21A");
            // printf("\033[6C");
        }
        rectangle(p[i], w[i]);
    }
}
int main(){
    // int seed;
    // printf("Enter a random Seed: ");
    // scanf("%d", &seed);
    srand(time(0));
    int n = random_(2,5) * 5;
    printf("n = %d\n", n);
    int Max_W = random_(2,8) * 10;
    printf("Max Weight - %d\n", Max_W);
    //printf("Max - %d\n" ,Max_W);
    int Profits[n], Weights[n];
    int k[n+1][Max_W+1];
    random_assignment(Profits, n, 10);
    random_assignment(Weights, n, 5);
    Graphics(Profits, Weights, n);
    printf("\nProfit\tWeight\n");
    for(int i = 0; i < n; ++i){
        printf("%d\t%d\n", Profits[i], Weights[i]);
    }
    for(int i = 0; i <=n; ++i){
        for(int w = 0; w <= Max_W; w++){
            if(i==0 || w == 0){
                k[i][w] = 0;
            }else if(Weights[i] <= w){
                k[i][w] = max(Profits[i]+k[i-1][w-Weights[i]], k[i-1][w]);
            }else{
                k[i][w] = k[i-1][w];
            }
        }
    }
    printf("\n%d", k[n][Max_W]);
    return 0;
}