#include<stdio.h>
void swap(int* xp, int* yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void bubbleSort(int p_w[],int item_nos[], int n)
{
    int i, j, temp;
    for (i = 0; i < n - 1; i++){ 
        for (j = 0; j < n - i - 1; j++){
            if (p_w[j] < p_w[j + 1]){
                swap(&p_w[j], &p_w[j + 1]);
                swap(&item_nos[j],&item_nos[j + 1]);
                //swap(&p[j], &p[j+1]);
                //swap(&w[j], &w[j+1]);
            }
        }
    }
}
int main(){
    int arr[5] = {30,45,20,15,20};
    int item_nos[5] = {0,1,2,3,4};
    bubbleSort(arr,item_nos,5);
    for(int i = 0; i < 5; ++i){
    printf("%d ", arr[i]);
    }
    printf("\n");
    for(int i = 0; i < 5; ++i){
        printf("%d ", item_nos[i]);
    }
}