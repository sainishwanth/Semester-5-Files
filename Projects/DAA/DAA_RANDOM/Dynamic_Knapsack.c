#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int random_(int min, int max){
    return min + rand() / (RAND_MAX / (max - min + 1) + 1);
}
void random_assignment(int arr[],int n, int multiplier){
    for(int i = 0; i < n; ++i){
    arr[i] = random_(1,10) * multiplier;
    //printf("%d\t", arr[i]);
    }
}
int max(int a, int b){
    if (a > b){
        return a;
    }
    return b;
}
int main(){
    srand(time(NULL));
    int n;
    printf("Enter the number of items - ");
    scanf("%d", &n);
    int Max_W = random_(1,8) * 10;
    printf("Max - %d\n" ,Max_W);
    int Profits[n], Weights[n];
    int k[n+1][Max_W+1];
    random_assignment(Profits, n, 10);
    random_assignment(Weights, n, 5);
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