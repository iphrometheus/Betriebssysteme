#include <stdio.h>
#include <unistd.h>

int main(int argc, char** argv){
   int pid = fork();
   if(pid == 0){
   char * envList[] = {"usr/bin/ls", "-la", NULL};
   execvp("ls", envList);
   }
   return 0;
}