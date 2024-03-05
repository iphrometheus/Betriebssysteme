#include <stdio.h>
#include <stdlib.h>
#include <syslog.h>


int main (void* arg){
    printf("Start \n");

    int var1 = fork();
    if(var1 == 0){
        setsid(0);
        char *path = "/";
        chdir(path);
        umask(0);
        fcloseall();
        syslog(LOG_INFO, "Daemon erzeugt");
        sleep(10);
    }
    else{
        exit(0);
    }
}