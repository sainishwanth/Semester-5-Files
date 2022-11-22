#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void merge(int *a, int low, int mid, int high){
    int i = low, j =  mid+1, k = low, c[10];
    while((i <= mid) && (j<=high)){
        if(a[i] < a[j]){
            c[k++] = a[i++];
        }else{
            c[k++] = a[j++];
        }
    }while(i <= mid){
        c[k++] = a[i++];
    }while(j <= high){
        c[k++] = a[j++];
    }for(i = low; i<=k-1; ++i){
        a[i] = c[i];
    }
}
void merge_sort(int *a, int low, int high){
    if(low < high){
        int mid = (low+high)/2;
        merge_sort(a, low, mid);
        merge_sort(a, mid+1, high);
        merge(a, low, mid, high);
    }
}
int main(void){
    int arr[10];
    for(int i = 0; i < 10; ++i){
        scanf("%d\n", &arr[i]);
    }
    int start = clock();
    merge_sort(arr, 0,9); 
    int stop = clock();
    printf("Sorted Array - \n");
    for(int i = 0; i < 10; ++i){
        printf("%d\n", arr[i]);
    }
    printf("Total time to Sort - %dms", stop-start);
}