#include<stdio.h>
#include<time.h>
#include<stdlib.h>
// int binary_search(int *a, int low, int high, int key){
//     int mid = (high+low)/2;
//     if(low > high){
//         return -1;
//     }
//     if(a[mid] == key){
//         return mid;
//     }
//     else if (a[mid] > key){
//         return binary_search(a, low, mid-1, key);
//     }else if (a[mid] < key){
//         return binary_search(a, mid+1, high, key);
//     }
// }
int search(int* nums, int numsSize, int target){
    
    int low = 0;
    int high = numsSize;
    while(low < high){
        int mid = (low+high)/2;
        if(nums[mid] == target){
            return mid;
        }else if (nums[mid] > target){
            high = mid-1;
            continue;
        }else{
            low = mid + 1;
            continue;
        }
    }
    return -1;
}
int main(void)
{   
    int a[15] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    int key = 3;
    int start = clock();
    int pos = search(a,14,key);
    if( pos == -1){
        printf("Number not found");
    }else{
        printf("Number found at %d", pos);
    }
    int stop = clock();
    printf("Time Taken - %dms", stop-start);
    return 0;
}