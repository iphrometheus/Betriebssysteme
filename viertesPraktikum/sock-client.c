#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdio.h>
#define PORT 2344
#define BUF_SIZE 1024

main()
{
	int sock, run;
	char buf[BUF_SIZE];
	struct sockaddr_in server;
	struct hostent *hp;
	char *hostname = "localhost";

	/* create socket */
	sock = socket(AF_INET, SOCK_STREAM, 0);
	if (sock < 0)
	{
		perror("Open stream socket");
		exit(1);
	}

	server.sin_family = AF_INET;

	/* get internet address of host specified by command line */
	hp = gethostbyname(hostname);
	if (hp == NULL)
	{
		fprintf(stderr, "%s is a unknown host.\n", hostname);
		exit(2);
	}

	/* copies the internet address to server address */
	bcopy(hp->h_addr, &server.sin_addr, hp->h_length);

	/* set port */
	server.sin_port = PORT;

	/* open connection */
	if (connect(sock, &server, sizeof(struct sockaddr_in)) < 0)
	{
		perror("Connecting stream socket");
		exit(1);
	}

	/* read input from stdin */
	while (run = read(0, buf, BUF_SIZE))
	{
		if (run < 0)
		{
			perror("Error reading from stdin");
			exit(1);
		}

		/* write buffer to stream socket */
		if (write(sock, buf, run) < 0)
		{
			perror("Writing on stream socket");
			exit(1);
		}
	}
	close(sock);
}
