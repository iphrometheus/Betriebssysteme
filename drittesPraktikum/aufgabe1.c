#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main(){
    int pid = fork();
    if( pid == 0){
        setsid();
        chdir("/");
        umask(0);
        sleep(20);
    }
    else{
        exit(0);
    }

}