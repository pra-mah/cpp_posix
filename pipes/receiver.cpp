//
// Created by pramah on 4/11/22.
//

#include "helper.h"

void receive(std::string name, std::string fname) {
    std::cout << "Starting pipeReceive.." << std::endl;
    int pd, bytes, total=0;// fileSize(0), total(0);
    std::vector<char> buffer(PIPE_BUF);

    // open pipe
    while ((pd = open(name.c_str(), O_RDONLY)) == -1) {
        sleep(2);
    }

    // Start read and write loop
   


    close(pd);
}
