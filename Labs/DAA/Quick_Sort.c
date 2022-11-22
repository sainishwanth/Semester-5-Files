#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void swap(int *a, int *b){
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int *a, int low, int high){
    int pivot = a[high];
    int i = low-1;

    for(int j = 0; j < high; ++j){
        if(a[j] <= pivot){
            i+=1;
            swap(&a[i], &a[j]);
        }
    }
    swap(&a[i+1], &a[high]);
    return i+1;
}

void Quick_Sort(int *a, int low, int high){
    if(low < high){
        int part = partition(a, low, high);
        return Quick_Sort(a, low, part-1);
        return Quick_Sort(a, part+1, high);
    }
}

int main(){
    int arr[10] = {4,5,6,7,2,1,3,4,10,2};
    int start = clock();
    Quick_Sort(arr, 0, 10);
    int stop = clock();
    for(int i = 0; i < 10; ++i){
        printf("%d\n", arr[i]);
    }
    printf("Time taken - %d", stop-start);
    return 0;
}