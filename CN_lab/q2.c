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
	
	struct sockaddr_in server;
	server.sin_family=AF_INET;
	server.sin_port=htons(argv[1]);
	server.sin_addr.s_addr=inet_addr(argv[2]);
	char buff[50]="Hello msg";
	int lenserver=sizeof(server);
	int len=strlen(buff);
	sendto(sockfd, (char*) buff, len , 0, (struct sockaddr*)&server, lenserver);
	
	close(sockfd);
	return 0;
}
