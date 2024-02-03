/* Beispielprogramm fuer Aufgabe 3c */
#include <stdio.h>
#include <unistd.h>
#include <signal.h>

int killProzess(int p);
int ProzessBaumstruktur();


int main(int argc, char const *argv[])
{
/*    int pid;
    printf("Start\n");

    pid = fork();
    if(pid < 0)
        printf("Fehler\n");
    
    if(pid == 0)
    {
        printf("Kindprozess\n");
        // aufgabe 3c
        /*sleep(20);
        return 0;
    }

    if(pid > 0)
    {
        printf("Elternprozess!\n");
        printf("PID des Kindes: %d\n",(int) pid);
        // aufgabe 3c
        /*sleep(10);
        return 0;
    }
    // aufgabe 3c with SigKill
 /*
    sleep(10);
    if(pid > 0){
    int p = getpid();
    killProzess(p);
    printf("Elternprozess gekillt \n");
    }
    sleep(10);
    printf("killing Child prozess\n");
    int c = getpid();
    killProzess(getpid);
    return 0;   
 */
    ProzessBaumstruktur();
    return 0;
}

int killProzess (int p){
    printf("Pid of Prozess %d\n", p);
    int check = kill(p, SIGKILL);
    if(check == 0){
        return check;
    }
    else{
        return -1;
    }
}

int ProzessBaumstruktur(){
    int fork1 = fork(); //A1 
    int fork2 = fork(); // fork creates a2 aswell as a11"
    printf("A1, A2 & A11 erzeugt\n");

    //kill parent 
    if(fork1 != 0 && fork2 != 0){
    int parentPro = getpid();
    sleep(10);
    printf("Kill Parent:\n");
    killProzess(parentPro);
    printf("Done");
    }
    int pidA21 = 0;
    if (fork2 == 0 && fork1 != 0)
    {
        // create a21
        pidA21 = fork();
        
    }
    if (fork1 == 0 && fork2 == 0)
    {
        int fork3 = fork();
        if (fork3 != 0)
        {
            fork();
        }
        
    }
    
    sleep(5);
    if (fork2 == 0 && fork1 != 0 && pidA21 != 0)
    {
        int a2pid = getpid();
        printf("killed %d\n", a2pid);
        killProzess(a2pid);
        
    }
    sleep(30);
    return 0;
}