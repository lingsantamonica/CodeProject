
//YUNPENG LING
//Socket Programming practice
//This program work as a socket client


/*

filename server_ipaddress portno

argv[0] filename
argv[1] server_ipaddress
argv[2] portno


*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>  //To read, write and close
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>  //include struct that store server info

void error(const char *msg)
{
	
	
	perror(msg);
	exit(0);  //terminate the program
	
}

int main( int argc, char* argv[])
{
	int sockfd, portno, n;
	struct sockaddr_in serv_addr;
	
	struct hostent *server;
	
	char buffer[255];
	
	
	//User did not provide enough addresses
	if(argc<3)
	{
		fprintf(stderr, "usage %s hostname port\n", argv[0]);
		exit(1);
	}
	
	
	portno=atoi(argv[2]);
	sockfd=socket(AF_INET, SOCK_STREAM, 0);
	
	if(sockfd<0)
	{
		error("Error opening socket");
	}
		
	server=getHostByName(argv[1]);
		
		
	//User provide wrong IP address or the server is off
	if(server==NULL)
	{
			fprintf(stderr, "Error, no such host");
	}
		
    bzero((char*)& serv_addr, sizeof(serv_addr));
	serv_addr.sin_family=AF_INET;
		
	//bcopy copy n bytes from server to struct
	bcopy((char*) server->h_addr, (char *)& serv_addr.sin_addr.s_addr, server->h_length);
		
	serv_addr.sin_port = htons(portno);
		
	if(connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr))<0)
	{
			
			error("Connection failed");
	}
		
	
	while(1)
	{
		bzero(buffer, 255);
		fgets(buffer, 255, stdin);
		
		n=write(sockfd, buffer, strlen(buffer));
		
		if(n<0)
		{
			error("Error on writing");
		}
		
		bzero(buffer, 255);
		n=read(sockfd, buffer, 255);
		
		//check function successful or not
		if(n<0)
		{
			error("Error on reading");
		}
		
		//Print the message we read from server
		printf("Server: %s" , buffer);
		
		int i = strncmp("Bye", buffer, 3)
		
		if(i==0)
		{
			break;
		}
		
		
		
	}
	
	
	close(sockfd);
	return 0;
		
		
	
	
	
}