#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void swap_float(float* xp, float* yp){
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
void swap(int* xp, int* yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
void bubbleSort(int p_w[],int item_nos[], int w[], int p[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++){ 
        for (j = 0; j < n - i - 1; j++){
            if (p_w[j] < p_w[j + 1])
                swap(&p_w[j], &p_w[j + 1]);
                swap(&item_nos[j], &item_nos[j+1]);
                swap(&w[j], &w[j+1]);
                swap(&p[j], &p[j+1]);
        }
    }
}
float random_(int min, int max){
    return min + rand() / (RAND_MAX / (max - min + 1) + 1);
}
void random_assignment(int arr[],int n, int multiplier){
    for(int i = 0; i < n; ++i){
    arr[i] = random_(1,10) * multiplier;
    printf("%d\t", arr[i]);
    }
}

int main(){
    int n;
    srand (time(NULL));
    printf("Enter the number of items: ");
    scanf("%d", &n);
    int item_nos[n], max_W, count_W = 0, max_P = 0;
    int w[n], p[n], p_w[n];
    max_W = random_(1,5) * 10;
    int curr_W = max_W;
    printf("Maximum Weight = %d", max_W);
    int i, j;
    printf("\n\nWeights\n");
    random_assignment(w, n, 5);
    printf("\n\nProfits\n");
    random_assignment(p, n, 10);
    printf("\n\nProfits/Weights\n");
    for(i = 0; i < n; ++i){
        p_w[i] = p[i] / w[i];
        printf("%d\t", p_w[i]);
    }
    for(i = 0; i < n; ++i){
        item_nos[i] = i+1;
    }
    bubbleSort(p_w, item_nos, w, p, n);
    printf("\n\nOrdered Profits/Weights\n");
    for(i = 0; i < n; ++i){
        printf("%d\t", p_w[i]);
    }
    printf("\n");
    for(i = 0; i < n; ++i){
        printf("%d\t", item_nos[i]);
    }
    i = 0;
    printf("\n\nItem\tProfit\tWeight\n");
    for(i = 0; i < n; ++i){
        if(curr_W < w[i]){
            continue;
        }
        count_W += w[i];
        max_P += p[i];
        curr_W -= w[i];
        printf("%d\t%d\t%d\n", item_nos[i], p[i], w[i]);
        if(count_W >= max_W){
            break;
        }
    }
    printf("\nMax Profit - %d", max_P);
    return 0;
}