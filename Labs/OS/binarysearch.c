#include<stdio.h>
void binary(int *a, int low, int high, int num){
    int mid = 0;
    while(low <= high){
        mid = (low+high)/2;
        if(a[mid] == num){
            printf("Number found at position %d", mid);
            return;
        }else if(a[mid] > num){
            high = mid - 1;
            continue;
        }else if(a[mid] < num){
            low = mid + 1; 
            continue;
        }
    }
    printf("Number not Found");   
}
int main(){
    int a[10] = {0,2,3,4,5,6,7,8,9,10,11};
    int num;
    printf("Enter a number to Search for: ");
    scanf("%d", &num);
    binary(a, 0, 9, num);
    return 0;
}