#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <unistd.h>
#include <iostream>

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>


int main (void)
{
    int ntwk_sock;

    //CREATE a Socket
    ntwk_sock = socket(AF_INET, SOCK_STREAM, 0);
    // ntwk_sock = socket(PF_INET, SOCK_STREAM, 0);

    //specify address to connect to
    struct sockaddr_in server_address;
    server_address.sin_family = PF_INET;
    server_address.sin_port = htons(9066);
    server_address.sin_addr.s_addr = INADDR_ANY;

    int result = connect(ntwk_sock, (struct sockaddr *) &server_address, sizeof(server_address));
    if ( result < 0)
        std::cout << "Did not work " << std::endl;
    else if (result == 0)
        std::cout << "Did work " << std::endl;
    else 
        std::cout << "Other behavior " << std::endl;
    
    //receive data from the server
    
    // recv(ntwk_sock, &service_response[0], sizeof(service_response), 0);

    //print out the data
    // std::cout << "DATA : " << service_response << std::endl;
    // printf("My message is : %s\n", service_response);


    sleep(1);
    int size;
    while (true)
    {
        char *buff = NULL;
        size_t len = 420;
        char service_response[256];

        getline(&buff, &len , stdin);
        std::cout << "Message created: " << buff << std::endl;
        result = send(ntwk_sock, buff , 256, 0); //send the message through the socket
        std::cout << "After send and before recv" << std::endl;

        sleep(1);
        memset(service_response, 0, sizeof(service_response));
        size = recv(ntwk_sock, &service_response, sizeof(service_response), 0);
        while (size > 0)
        {
            std::cout << "New answer received : " << service_response << " with code : " << size << std::endl;
            size = recv(ntwk_sock, &service_response, sizeof(service_response), 0);
        }
        if (strcmp(service_response, "EOF") == 0)
        {
            std::cout << "Why" << std::endl;
            break;
        }
        free(buff);

    }



    close(ntwk_sock);
    
    return (0);
}