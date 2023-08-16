#include<stdio.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<netinet/ip.h>
#include<stdlib.h>

int main(int argc,int argv[]){
    int sockfd=socket(AF_INET,SOCK_DGRAM,0);
    if(sockfd==-1){
        printf("Error in c");
        exit(0);

    }else{
        printf("socket created");
    }

    struct sockaddr_in server;
    server.sin_family=AF_INET;
    server.sin_port=htons(argv[1]);
    server.sin_addr.s_addr = inet_addr(argv[2]);
    int len=sizeof(server);
}
