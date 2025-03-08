#ifndef PROCESS_PACKET_H
#define PROCESS_PACKET_H

#include <iostream>
#include <cstring>
#include <arpa/inet.h>

void process_packet(const char* buffer, std::size_t size);

#endif