i#include<stdio.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<netinet/ip.h>
#include<stdlib.h>

int main(int argc,char* argv[]){

	int sockfd=socket(AF_INET,SOCK_DGRAM,0);
	if(sockfd==-1){
		printf("ERROR IN C");
		exit(0);
	}else{
		printf("socket created");
	}
	
	struct sockaddr_in client;
	struct sockaddr_in server;
	server.sin_family=AF_INET;
	server.sin_port=htons(argv[1]);
	server.sin_addr.s_addr=inet_addr(argv[2]);
	int len=sizeof(server);
	int bindfd=bind(sockfd,(struct sockaddr*)&server,len);
	if(bindfd==-1){
		printf("\nBIND ERROr\n");
		exit(0);
	}
	else{
		printf("\nBind created\n");
	}
	
	
	char buff[50];
	int maxlen=50;
	int lenclient=sizeof(client);
	
	int r=recvfrom(sockfd, (char*)buff,maxlen,0,(struct sockaddr*) &client,&lenclient);
	buff[r]='\0';
	printf("msg recv=%s",buff);
	
	close(sockfd);
		
	return 0;
}
		
