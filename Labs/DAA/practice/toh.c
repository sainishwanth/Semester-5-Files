#include<stdio.h>
#include<time.h>
int count = 0;

void toh(int n, char from, char aux, char to){
    if (n == 1){
        printf("%d. ", ++count);
        printf("Moving 1 disk from %c to %c\n", from, to);
        return;
    }
    toh(n-1, from, to, aux);
    printf("%d. Moving 1 disk from %c to %c\n", ++count,from, to);
    toh(n-1, aux, from, to);
}

int main(){
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    float start = clock();
    toh(n, 'A', 'B', 'C');
    float stop = clock();
    printf("\nTotal time taken - %fms", (stop-start));
}