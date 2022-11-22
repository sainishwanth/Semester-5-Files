#include<stdio.h>
#include<time.h>

int count = 0;

void TOH(int n, char a, char b, char c){
    printf("%d.", ++count);
    if(n == 1){
        return;
    }
    TOH(n-1, a, c, b);
    printf("Moving %c to %c\n",a,c);
    TOH(n-1, b, a, c);
}

int main(){
    int n, st, et, tt;
    printf("Enter the Number of disks: ");
    scanf("%d", &n);
    st = clock();
    TOH(n, 'A', 'B', 'C');
    et = clock();
    tt = et-st;
    printf("\nTime:%dms",tt);
    return 0;
}
