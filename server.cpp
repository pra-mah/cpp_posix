#include <iostream>
#include <cstdlib>
#include <signal.h>
#include <string.h>
#include<cstring>
#include <mqueue.h>
#include<fcntl.h>
#include<sys/types.h>
#include <fstream>
#include <filesystem>
namespace fs = std::filesystem;

/*class Message{
public:
	void input();
	void output();
private:
	long token_number;

}*/

const std::string str1  = "/sp-server";
const char * SERVER_QUEUE_NAME   = str1.c_str();
const int QUEUE_PERMISSIONS = 0660;
const int MAX_MESSAGES = 10;
const int MAX_MSG_SIZE = 256;
const int MSG_BUFFER_SIZE = MAX_MSG_SIZE + 10;

int main(int argc, char **argv)
{
    mqd_t qd_server, qd_client;   // queue descriptors
    long token_number = 1; // next token to be given to client

    std::cout<< "Server: Hello, World!\n";
    // Set queue attributes
    struct mq_attr attr;
    attr.mq_flags = 0;  /* Flags (ignored for mq_open()) */
    attr.mq_maxmsg = MAX_MESSAGES;
    attr.mq_msgsize = MAX_MSG_SIZE;
    attr.mq_curmsgs = 0;/* # of messages currently in queue
                                       (ignored for mq_open()) */

    //Replace these with file 
    char in_buffer [MSG_BUFFER_SIZE];
    char out_buffer [MSG_BUFFER_SIZE];
    /*const std::filesystem::path src = "hello";
    cout<<"File read"<<endl;*/

        if ((qd_server = mq_open (SERVER_QUEUE_NAME, O_RDONLY | O_CREAT, QUEUE_PERMISSIONS, &attr)) == -1) {
        perror ("Server: mq_open (server)");
        exit (1);
    }
    while (1) {
        // get the oldest message with highest priority
        if (mq_receive (qd_server, in_buffer, MSG_BUFFER_SIZE, NULL) == -1) {
            perror ("Server: mq_receive");
            exit (1);
        }
        std::cout<<"Server: Message received. \n"<<std::endl;
    
    //Send reply message to client
    if ((qd_client = mq_open (in_buffer, O_WRONLY)) == 1) {
            perror ("Server: Not able to open client queue");
            continue;
        }
        
        std::cout<< out_buffer<<token_number<<std::endl;

        if (mq_send (qd_client, out_buffer, strlen (out_buffer) + 1, 0) == -1) {
            perror ("Server: Not able to send message to client");
            continue;
        }

        std::cout<<"Server: response sent to client.\n";
        token_number++;
    }//end while
    
    
}//end of main


