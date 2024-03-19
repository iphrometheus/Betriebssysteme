#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdio.h>
#include <time.h>
#define PORT 2344
#define MAX_QUEUE 1
#define BUF_SIZE 1024
main()
{
	int sock_1;
	int sock_2;
	int rec_value, length;
	char buf[BUF_SIZE];
	char aus[BUF_SIZE];
	struct sockaddr_in server;

	/* create stream socket in internet domain */
	sock_1 = socket(AF_INET, SOCK_STREAM, 0);

	if (sock_1 < 0)
	{
		perror("Open stream socket");
		exit(1);
	}
	/* build address in internet domain */
	server.sin_family = AF_INET;

	/* everyone is allowed to connet to server */
	server.sin_addr.s_addr = INADDR_ANY;
	server.sin_port = PORT;

	/* bind socket */
	if (bind(sock_1, &server, sizeof(struct sockaddr_in)))
	{
		perror("Bind socket to server_addr\n");
		exit(1);
	}
	listen(sock_1, MAX_QUEUE);

	/* start accepting connection */
	sock_2 = accept(sock_1, 0, 0);

	if (sock_2 < 0)
	{
		perror("accept\n");
		exit(1);
	}
	
	/* read from sock_2 */
	while (rec_value = read(sock_2, buf, BUF_SIZE))
	{
		if (rec_value < 0)
		{
			perror("Reading stream message\n");
			exit(1);
		} else
			buf[rec_value-1]= '\0';
			if(0 >= strcmp(buf,"GETTIME")){
				timer_t clk = time(NULL);
				printf("Antwort: %s\n", ctime(&clk));
				break;

			}else{
			printf("Pufferinhalt: %.*s\n", rec_value, buf);
			printf("Antwort:%d\n", rec_value);
			}
	}
	printf("Ending connection.\n");

	close(sock_1);
	close(sock_2);

}
