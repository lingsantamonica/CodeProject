
//YUNPENG LING
//Socket Programming practice
//This program work as a socket server

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

void error(const char *msg)
{
	
	
	perror(msg);
	exit(1);  //terminate the program
	
}

int main( int argc, char *argv[])
{
	
	//If user did not provide correct port number
	if(argc<2)
	{
		fprintf(stderr, " Port number not provided. program terminated\n");
		exit(1);
		
		
	}
	
	
	int sockfd, newsockfd, portno , n;
	
	char buffer[255]; //Message size defined
	
	struct sockaddr_in serv_addr, cli_addr; //internet address 
	
	socklen_t clilen; 
	
	
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	
	//socket connection failure
	if(sockfd<0)
	{
		error("Error opening socket");
	}	
	
	
	//bzero clears any data it references to
	bzero((char*)& serv_addr, sizeof(serv_addr) );
	
	portno = atoi(argv[1]); //argv contains port number
	
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = INADDR_ANY;
	serv_addr.sin_port= htons(portno); //htons == host to network short
	
	
	//finding function
	if(bind(sockfd, (struct sockaddr*)& serv_addr, sizeof(serv_addr))<0)
	{
		error("Binding failed");
	}
	
	
	//Server listening
	listen(sockfd, 5); // the max clients could connect to server set to 5
	clilen=sizeof(cli_addr);
	
	
	
	newsockfd = accept(sockfd, (struct sockaddr*)& cli_addr, &clilen);
	
	//check if the function failed
	if(newsockfd<0)
	{
		
		error("Error on accept");
	}
	
	
	while(1)
	{
		
		//Clear anything inside buffer
		bzero(buffer, 255);
		
		//read function
		n = read(newsockfd, buffer, 255);
		
		if(n<0)
		{
			
			error("Error on reading");
			
		}
		
		printf("Client: %s\n", buffer);
		
		//clear the buffer & waiting for server reply
		bzero(buffer, 255);
		fgets(bufffer, 255, stdin); //fgets takes the reply from the server
		
		n= write(newsockfd, buffer, strlen(buffer));
		
		if(n<0)
		{
			
			error("Error on writing");
		}
		
		int i = strncmp(" Bye" , buffer, 3);
		if(i==0)
		{
			
			break;
		}
		
		
		
	}
	
	
	close(newsockfd);
	close(sockfd);
	return 0;
	
	
}

