
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv){

    int pid;
    pid = fork();
    pid = fork();
    pid = fork();

    char* argv1= "string";
    for(int i = 0; i <= argc; i++){
            printf("%s \n", argv[i]);
            sleep(1);
        }
    sleep(10);
    strcpy(argv[0], argv1);
    
    for(int i = 0; i <= argc; i++){
            printf("%s \n", argv[i]);
            sleep(1);
        }
    while(1){
        sleep(5);
        
        sleep(1000);
        }
}