#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(){
    int pid = fork();
    if (pid < 0){
        printf("Fork Failed\n");
        exit(0);
    }else if(pid == 0){
        printf("Fork Successful\n");
        printf("Output of Child Process is: \n");
        execlp("echo", "echo" , "hello, world!",(char *)NULL);
        exit(0);
    }else{
        printf("Created Child Process, its id is - %d\n", getpid());
        wait(NULL);
        printf("Return back to Parent Process with id %d", getppid());
        exit(0);
    }
    return 0;
}