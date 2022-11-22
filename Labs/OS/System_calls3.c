#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<fcntl.h>

int main(){
    char buff;
    int fd, fd1;
    fd = open("one.txt", O_RDONLY);
    fd1 = open("two.txt", O_WRONLY|O_CREAT);
    while(read(fd, &buff, 1)){
        write(fd1, &buff, 1);
    }printf("Copied Succesfully\n");
    close(fd);
    close(fd1);
    return 0;
}