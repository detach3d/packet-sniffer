#include <iostream>
#include <cstring>
#include <arpa/inet.h>
#include "protocol_headers.h"
#include "process_packet.h"

void process_packet(const char* buffer, std::size_t size) {
    ip_header* ip = reinterpret_cast<ip_header*>(const_cast<char*>(buffer));
    tcp_header* tcp = reinterpret_cast<tcp_header*>(const_cast<char*>(buffer + (ip->ihl * 4)));

    std::cout << "Source IP: " << inet_ntoa(ip->ip_src)
              << " | Destination IP: " << inet_ntoa(ip->ip_dst)
              << " | Protocol: " << static_cast<int>(ip->protocol);

    if (ip->protocol == IPPROTO_TCP) { 
        std::cout << " | Source Port: " << ntohs(tcp->source_port)
                  << " | Destination Port: " << ntohs(tcp->dest_port)
                  << "\n";
    }
}