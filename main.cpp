//
//  main.cpp
//  Socket
//
//  Created by René Descartes Domingos Muala on 07/02/21.
//  Copyright © 2021 landia (René Muala). All rights reserved.
//
//  #Sorry for my english!
//

#include <iostream>
#include <netdb.h>
#include <unistd.h>
#include <arpa/inet.h>

#define machine_name_buffer_size 1024

int main(int argc, const char * argv[]) {
    
    /*
    1. Our variables!
     */
    char machine_name [machine_name_buffer_size] = {0};
    char machine_IPv4[INET_ADDRSTRLEN] = {0};
    hostent * machine_host = nullptr;
    
    /*
     2. Get current machine name
     ! if the machine is connected to a network:
     returns <machine name>
     ! else
     returns <machine name>.local
     */
    gethostname(machine_name, 1024);
    
    /*
     3. Get the machine host by using the machine name
     ! if the machine is connected to a network:
     returns <Public host>
     ! else
     returns <Local host> (IPv4: 127.0.0.1)
     */
    machine_host = gethostbyname(machine_name);
    
    /*
     4. Get a readable IPv4 from the machine host
     */
    inet_ntop(AF_INET, machine_host->h_addr_list[0], machine_IPv4, INET_ADDRSTRLEN);
    
    /*
     5. Print the machine name and the readable IPv4
     */
    std::cout
    << "Machine Name: "<<machine_name << std::endl
    << "Machine IPv4: "<<machine_IPv4 << std::endl;
    
    /*
     6. Have a Good day!
     */
    
    return 0;
}
