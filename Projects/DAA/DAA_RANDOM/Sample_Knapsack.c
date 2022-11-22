#include<stdio.h>

void swap(int* xp, int* yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
void bubbleSort(int p_w[],int item_nos[], int w[],int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++){ 
        for (j = 0; j < n - i - 1; j++){
            if (p_w[j] < p_w[j + 1])
                swap(&p_w[j], &p_w[j + 1]);
                swap(&item_nos[j], &item_nos[j+1]);
                swap(&w[j], &w[j+1]);
        }
    }
}

int main(){
    int n;
    printf("Enter the number of items: ");
    scanf("%d", &n);
    int w[n], p[n], p_w[n], item_nos[n], max_W, count_W = 0, max_P = 0;
    printf("Enter the Max Weight: ");
    scanf("%d", &max_W);
    int curr_W = max_W;
    int i, j;
    for(i = 0; i < n; ++i){
        printf("Enter the weight of item [%d]: ", i+1);
        scanf("%d", &w[i]);
    }
    printf("\n\n");
    for(i = 0; i < n; ++i){
        printf("Enter the Profit of item [%d]: ", i+1);
        scanf("%d", &p[i]);
    }
    for(i = 0; i < n; ++i){
        p_w[i] = p[i] / w[i];
        printf("%d\t", p_w[i]);
    }
    for(i = 0; i < n; ++i){
        item_nos[i] = i+1;
    }
    bubbleSort(p_w, item_nos, w, n);
    printf("\n");
    for(i = 0; i < n; ++i){
        printf("%d\t", p_w[i]);
    }
    i = 0;
    printf("Items - \n");
    // while(count_W < max_W && i < n){
    //     if(w[i] < curr_W){
    //         i++;
    //         continue;
    //     }
    //     printf("%d\t", item_nos[i]);
    //     count_W += w[i];
    //     max_P += p[i];
    //     curr_W -= w[i];
    //     i++;
    // }
        for(i = 0; i < n; ++i){
        if(w[i] > curr_W){
            continue;
        }
        count_W += w[i];
        max_P += p[i];
        curr_W -= w[i];
        printf("%d\t", item_nos[i]);
        if(count_W >= max_W){
            break;
        }
    }
    return 0;
}