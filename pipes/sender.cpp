//
// Created by pramah on 4/11/22.
//

#include "helper.h"



int main(){

    return 0;
}
void send(std::string name, std::string fname) {
    std::cout << "Starting pipeSend.." << std::endl;
    unlink(name.c_str());

    int pd;
    int total=0;
    std::vector<char> buffer(PIPE_BUF);
    std::vector<std::string> vec_str;
    std::ifstream ifs;
    unsigned bytes_read, bytes_write;

    //Pipe created
    if(mkfifo(name.c_str(),0666)==-1){
        throw(std::runtime_error("Sending failed. mkfifo"));
    }

    //Open the pipe
    pd = open(name.c_str(),O_RDWR);
    if(pd==-1){
        throw(std::runtime_error("Send(): Pipe onpening failed"));
    }

    //Read and write operation
    while(ifs){
        bytes_read=getFileContent(fname, vec_str);
        if(bytes_read>0) {
            throw(std::runtime_error("Send: readFile"));
        }
    }//reading input stream done

    //Write to pipe
    bytes_write = write(pd,buffer.data(),bytes_read);
    if(bytes_write==-1){
        throw(std::runtime_error("send: write to pipe"));
    }

    if(bytes_read==bytes_write){
        total +=bytes_read;
    }
    else{
        throw(std::runtime_error("send: read write difference"));
    }
    ifs.close();
    close(pd);
    std::cout<<"File deliverd from the pipe."<<std::endl;
    /*


}
