#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int max(int a, int b){
    if (a > b){
        return a;
    }
    return b;
}
int random_(int min, int max){
    return min + rand() / (RAND_MAX / (max - min + 1) + 1);
}
int Dynamic_Knapsack(int Profits[], int Weights[], int n, int Max_W){
    int k[n+1][Max_W+1];
    for(int i = 0; i <=n; i++){
        for(int w = 0; w <= Max_W; w++){
            if(i==0 || w == 0){
                k[i][w] = 0;
            }else if(Weights[i-1] <= w){
                k[i][w] = max(Profits[i-1]+k[i-1][w-Weights[i-1]], k[i-1][w]);
            }else{
                k[i][w] = k[i-1][w];
            }
        }
    }
    return k[n][Max_W];
}

int * random_assignment(int n, int multiplier){
    int * arr = (int *)malloc(n*sizeof(int));
    for(int i = 0; i < n; ++i){
    arr[i] = random_(2,9) * multiplier;
    }
    return arr;
}

int main(){
    int n, Max_W, Max_P, Input_MaxP;
    int * Profits;
    int * Weights;
    srand(time(0)*0.1);
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    float start = clock();
    Max_W = random_(2,8) * 10;
    srand(time(0)*3);
    Profits = random_assignment(n, 9);
    srand(time(0)*4);
    Weights = random_assignment(n, 6);
    
    printf("Profits\tWeights");
    for(int i = 0; i < n; ++i){
        printf("%d\t%d\n", Profits[i], Weights[i]);
    }

    Max_P = Dynamic_Knapsack(Profits, Weights, n, Max_W);
    float stop = clock();
    printf("Max Profit = %d\nTime Taken - %fs", Max_P, (stop-start)/100);
}