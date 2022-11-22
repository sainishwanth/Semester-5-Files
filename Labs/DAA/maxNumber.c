#include<stdio.h>

int max(int *arr, int n, int a){
    if(n == 0){
        return a;
    }
    if(arr[n] > arr[n-1]){
        return max(arr, n-1, arr[n]);
    }else{
        return max(arr, n-1, arr[n-1]);
    }
}

int main(){
    int a[5] = {1,2,3,4,5};
    printf("%d",max(a,4,0));
    return 0; 
}