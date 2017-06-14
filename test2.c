#include <stdio.h>
#include <sys/socket.h>
#include <string.h>
#include <stdlib.h>
#include <arpa/inet.h> //inet_addr
#include <netdb.h>


// Socket Basic Reference http://www.cs.rpi.edu/~moorthy/Courses/os98/Pgms/socket.html

int main(int argc, char *argv[])
{
	
	int clientSoc;
	struct sockaddr_in serverAdd;

	//Creating a client socket 
	clientSoc = socket(AF_INET, SOCK_STREAM, 0);
	
	if (clientSoc == -1)
	{
		printf("Unable to create a socket\n");
	}
	else
	{
		printf("Socket has been created\n");
	}
	
	serverAdd.sin_addr.s_addr = inet_addr("216.58.194.142");
	serverAdd.sin_family = AF_INET;
	serverAdd.sin_port = htons(80);
	
	if (connect(clientSoc, (struct sockaddr *)&serverAdd , sizeof(serverAdd)) < 0)
	{
		printf("Error in Connection\n");
		return 1;
	}
	printf("Connected \n");
        char command[1000] ={0};
        char command2[1000] = {0};
        char *name;
        char *parseCmd;
        printf("Please enter your command: \n");
        fgets(command, 80, stdin);
        printf("OK\n");
        strcpy(command2,command);
        name = strtok(command2, " ");
        

	while (1)
	{
	
	if (!strcmp(name,"pingSites"))
	{
		parseCmd = strtok(command," ,");
        while (parseCmd != NULL)
        {
			puts(parseCmd);
			parseCmd = strtok (NULL," ,");
			clientSoc.send(parseCmd);
		}
			printf("OK2\n");
			break;
			
	}
	if (!strcmp(name,"showHandles"))
	{
		printf("Working\n");
	}
	if(!strcmp(command,"showHandleStatus"))
	{
	}
	if(!strcmp(command, "exit"))
	{
	}
	if(!strcmp(command, "help"))
	{
	}
    }
	return 0;
	
}
