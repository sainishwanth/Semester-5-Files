#include<stdio.h>
#include<time.h>
#include<stdlib.h>
int binary_search(int *a, int low, int high, int key){
    int mid = (high+low)/2;
    if(low > high){
        return -1;
    }
    if(a[mid] == key){
        return mid;
    }
    else if (a[mid] > key){
        return binary_search(a, low, mid-1, key);
    }else if (a[mid] < key){
        return binary_search(a, mid+1, high, key);
    }
}
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
void bubble_sort(int a[], int n){
    for(int i = 0; i < n-1; ++i){
        for(int j = 0; j < n-i-1; ++j){
            if(a[j] > a[j+1]){
                swap(&a[j], &a[j+1]);
            }
        }
    }
}
int main(void)
{   
    int n;
    int key;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int a[n];
    for(int i = 0; i < n; ++i){
        a[i] = rand() % 100;
    }
    for(int i = 0; i < n; ++i){
        printf("%d ", a[i]);
    }
    printf("\nEnter an element to search for - ");
    scanf("%d", &key);
    printf("\nSorted Array - ");
    int start = clock();
    bubble_sort(a, n);
    for(int i = 0; i < n; ++i){
        printf("%d ", a[i]);
    }
    int pos = binary_search(a,0,n,key);
    printf("\n");
    if( pos == -1){
        printf("Number not found");
    }else{
        printf("Number found at %d", pos);
    }
    int stop = clock();
    printf("\nTime Taken - %dms", stop-start);
    return 0;
}