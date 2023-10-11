#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

int main(int agrc, char *argv[])
{
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1)
    {
        printf("Error while creating socket\n");
    }
    else
    {
        printf("Socket is created successfully\n");
    }

    struct sockaddr_in server;
    struct sockaddr_in client;
    server.sin_family = AF_INET;
    server.sin_port = htons(atoi(argv[1]));
    server.sin_addr.s_addr = inet_addr(argv[2]);
    int serverlen = sizeof(server);
    int clientlen = sizeof(client);

    int bindfd = bind(sockfd, (struct sockaddr *)&server, serverlen);
    if (bindfd == -1)
    {
        printf("Error in binding\n");
    }
    else
    {
        printf("binding successful\n");
    }

    int lstn = listen(sockfd, 3);
    if (lstn == -1)
    {
        printf("Listen error");
        exit(0);
    }
    else
    {
        printf("Listen function created successfully\nserver side \n");
    }

    // accpt(sfd,(struct sockaddr*)&clientaddr, lenclientaddr,)

    int acptfd = accept(sockfd, (struct sockaddr *)&client, (socklen_t *)&clientlen);

    if (acptfd == -1)
    {
        printf("error while creating accpet\n");
        exit(0);
    }

    // here acceptfd will be used in place of sockfd
    char buff1[50];
    int length = strlen(buff1);
    int maxlen = 50;

    int rec = recv(acptfd, buff1, maxlen, 0);
    if (rec == -1)
    {
        printf("Error while receiving the message\n");
        exit(0);
    }
    else
    {
        buff1[rec] = '\0'; // Null-terminate the received data
        printf("Received from client: %s\n", buff1);
    }


    char buff2[50] = "Robins";
    int length2 = strlen(buff2);
    int s = send(acptfd, (char *)buff2, length2, 0);
    if (s == -1)
    {
        printf("Sending message is failed\n");
        exit(0);
    }
    else
    {
        printf("sent successfully");
    }

    close(sockfd);
}

