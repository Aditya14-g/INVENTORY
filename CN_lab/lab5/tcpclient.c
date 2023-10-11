#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1)
    {
        printf("error in creating the socket\n");
    }
    else
    {
        printf("Socket created successfully\n");
    }

    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_port = htons(atoi(argv[1]));
    server.sin_addr.s_addr = inet_addr(argv[2]);
    int serverlen = sizeof(server);
    // printf("The length of the struct addr_in server is %d\n",addrlen);

    // creating connect function
    int cnnt = connect(sockfd, (struct sockaddr *)&server, serverlen);

    if (cnnt == -1)
    {
        printf("Error while connecting");
        exit(0);
    }
    else
    {
        printf("Connected to server successfully\n");
    }

    // s=send(sockfd, msg, lenmsg, 0)
    // r=recv(sockfd,buf,maxlen,0)

    // sending info to the server
    char buff1[50] = "2105569";
    int length = strlen(buff1);

    int s = send(sockfd, (char *)buff1, length, 0);
    if (s == -1)
    {
        printf("Sending message is failed\n");
        exit(0);
    }
    else
    {
        printf("sent successfully\n");
    }
    
    char buff2[50];
    int maxlen = 50;
    int rec = recv(sockfd, (char *)buff2, maxlen, 0);

    if (rec == -1)
    {
        printf("Error while receiving the message\n");
        exit(0);
    }
    else
    {
        buff2[rec] = '\0'; // Null-terminate the received data
        printf("Received from server: %s\n", buff2);
    }

    close(sockfd);
}
