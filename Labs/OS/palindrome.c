#include<stdio.h>

int main(){
    int n;
    int pal = 0;
    printf("Enter a number to check if its a palindrome or not: ");
    scanf("%d", &n);
    int rem;
    int temp = n;
    while(n != 0){
        rem = (n%10);
        pal = (pal*10)+rem;
        n /= 10;
    }
    if(temp == pal){
        printf("Palindrome");
    }else{
        printf("Not a Palindrome");
    }
    return 0;
}