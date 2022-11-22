#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main(){
    int pid = fork();
    if(!pid){
        wait(NULL);
        printf("\nParent Process ID: %d", getppid());
        printf("\nChild Process ID: %d", pid);
    }else{
        printf("\nChild Process ID: %d", getpid());
        printf("\nParent Process ID: %d", getppid());
    }
    return 0;
}