#include<stdio.h>
#include<time.h>

int linear_search(int *a,int n, int key){
    for(int i = 0; i < n; ++i){
        if(a[i] == key){
            return i;
        }
    }
    return -1;
}
int main(){
    int a[10] = {5,3,1,26,1,23,44,5,6,7};
    int pos = linear_search(a, 10, 200);
    int start = clock();
    if(pos == -1){
        printf("Key Not Found");
    }
    else{
        printf("Key Found in position %d", pos);
    }
    int stop = clock();
    int total = stop-start;
    printf("\nTime Taken - %dms", total);
    return 0;
}