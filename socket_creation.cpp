#include <string>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <iostream>
#include "process_packet.h"
#include <exception>
#include "socket_creation.h"

#define BUFF_SIZE 2048

int create_socket()
{
    return socket(AF_INET, SOCK_RAW, IPPROTO_TCP);
}

void packet_handler()
{

    int sockfd = create_socket();
    if (sockfd == -1)
    {
        throw std::invalid_argument{"Failed to create raw socket. May be you don't have permission\n"};
    }

    std::cout << "Listener started for TCP connections\n";

    char buffer[BUFF_SIZE];

    while (true)
    {
        ssize_t receiver = recv(sockfd, buffer, BUFF_SIZE, 0);
        if (receiver < 0)
        {
            std::cerr << "Error receiving packets!\n";
            continue;
        }
        process_packet(buffer, receiver);
    }

    close(sockfd);
}