/*
 * Simpleshell fuer das Praktikum Betriebssysteme
 *
 * Bitte übersetzen mit:
 * > gcc -o simpleshell simpleshell.c -lreadline
 *
 * Bitte beachten Sie, dass für die Nutzung der readline-Bibliothek folgendes Paket installiert sein muss:
 *
 * > sudo apt install libreadline-dev
 */

#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <unistd.h>

extern HIST_ENTRY **history_list ();

int main ()
{
  char *temp, *prompt;
  int done;

  temp = (char *)NULL;
  prompt = "ETTI-Shell > ";
  done = 0;

  while (!done)
    {
      temp = readline (prompt);

      /* Testen auf End-of-File EOF. */
      if (!temp)
	{
	  printf("\n");
	  exit (1);
	}
      /* Wenn die Eingabe nicht leer ist, wird sie ausgegeben und dann in der History gespeichert. */
      if (*temp)
	{
	  fprintf (stderr, "%s\r\n", temp);
	  add_history (temp);
	  /* An dieser Stelle sollte das eingegebene Kommando in einem Kindprozess gestartet werden
	   * Dazu sind folgende Schritte nötig:
	   * Erzeugung eines Kindprozesses mit fork()
	   * Im Kindprozess wird das Kommando mit einem der execX() Befehle ausgeführt
	   * Der Elternprozess wartet auf die Beendigung des Kindprozesses */
	   
	   pid_t p = fork();
	   if(p == 0){
		char *tmp = "/usr/bin/";
	   	char * arg[] = {tmp ,NULL};
		printf("\n");
		execvp(temp, arg);
		}
		else{
			int status;
			waitpid(p,&status,WUNTRACED);
		}


	}

      /* Die Shell kennt auch ein paar eingebaute Kommandos: "quit", "etti", "list" */
      if (strcmp (temp, "quit") == 0)
	done = 1;

      if (strcmp (temp, "etti") == 0)
	{
	  printf("Saucool!\n");
	  done = 1;
	}

      if (strcmp (temp, "list") == 0)
	{
	  HIST_ENTRY **list;
	  register int i;

	  list = history_list ();
	  if (list)
	    {
	      for (i = 0; list[i]; i++)
		fprintf (stderr, "%d: %s\r\n", i, list[i] -> line);
	    }
	}
      free (temp);
    }
  printf("\n");
  exit (0);
}
