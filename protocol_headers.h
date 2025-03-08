#include <arpa/inet.h>

class ip_header {
public:
    unsigned char ihl : 4, version : 4;
    unsigned char tos;
    unsigned short tot_len;
    unsigned short id;
    unsigned short frag_off;
    unsigned char ttl;
    unsigned char protocol;
    unsigned short check;
    in_addr ip_src, ip_dst; 
};


class tcp_header {
public:
    unsigned short source_port;
    unsigned short dest_port;
    unsigned int seq_num;
    unsigned int ack_num;
    unsigned char data_offset : 4, reserved : 4;
    unsigned char flags;
    unsigned short window_size;
    unsigned short checksum;
    unsigned short urgent_pointer;
};