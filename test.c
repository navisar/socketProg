#include <stdio.h>
#include <sys/socket.h>
#include <string.h>
#include <stdlib.h>
#include <arpa/inet.h> //inet_addr
#include <netdb.h>


// Socket Basic Reference http://www.cs.rpi.edu/~moorthy/Courses/os98/Pgms/socket.html

int main(int argc, char *argv[])
{
	int clientSoc, portNo;
	struct sockaddr_in serverAdd;
	char command[1000] = {0};
	struct hostent *server;
	
	/*Creating a client socket */
	clientSoc = socket(AF_INET, SOCK_STREAM, 0);
	
	if (clientSoc == -1)
	{
		printf("Unable to create a socket\n");
	}
	else
	{
		printf("Socket has been created\n");
	}
		if (argc < 3)
	{
	    fprintf(stderr,"usage %s hostname port\n", argv[0]);
		exit(0);
	}
	portNo = atoi(argv[2]);
	server = gethostbyname(argv[1]);
	bzero((char *) &serverAdd, sizeof(serverAdd));
	serverAdd.sin_family = AF_INET;
	bcopy((char *)server->h_addr,(char *)&serverAdd.sin_addr.s_addr,server->h_length);
	serverAdd.sin_port = htons(portNo);
	
	if (connect(clientSoc, (struct sockaddr *)&serverAdd , sizeof(serverAdd)) < 0)
	{
		printf("Error in Connection\n");
		return 1;
	}
	printf("Connected \n");
	printf("Please enter your command: \n");
	scanf("%s", command);
	return 0;
	
}
