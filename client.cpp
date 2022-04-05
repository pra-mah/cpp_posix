#include <iostream>
#include <cstdlib>
#include <signal.h>
#include <string.h>
#include<cstring>
#include <mqueue.h>
#include<fcntl.h>
#include<sys/types.h>
#include <filesystem>
namespace fs = std::filesystem;

const std::string str1  = "/sp-server";
const char * SERVER_QUEUE_NAME   = str1.c_str();
const int QUEUE_PERMISSIONS = 0660;
const int MAX_MESSAGES = 10;
const int MAX_MSG_SIZE = 256;
const int MSG_BUFFER_SIZE = MAX_MSG_SIZE + 10;

int main(int argc, char **argv)
{
    char client_queue_name [64];
    mqd_t qd_server, qd_client;   // queue descriptors
    
    sprintf (client_queue_name, "/sp-client-%d", getpid ());
    
    struct mq_attr attr;

    attr.mq_flags = 0;
    attr.mq_maxmsg = MAX_MESSAGES;
    attr.mq_msgsize = MAX_MSG_SIZE;
    attr.mq_curmsgs = 0;

    if ((qd_client = mq_open (client_queue_name, O_RDONLY | O_CREAT, QUEUE_PERMISSIONS, &attr)) == -1) {
        perror ("Client: mq_open (client)");
        exit (1);
    }

    if ((qd_server = mq_open (SERVER_QUEUE_NAME, O_WRONLY)) == -1) {
        perror ("Client: mq_open (server)");
        exit (1);
    }
    
    char in_buffer [MSG_BUFFER_SIZE];
    
    //std::cout<<"Ask for a token (Press <ENTER>): ";
    
    char temp_buf[10];
    
     while (1) {

        
    // receive response from server queue

        if (mq_receive (qd_client, in_buffer , MSG_BUFFER_SIZE, NULL) == -1) {
            perror ("Client: mq_receive");
            exit (1);
        }
        else{

        std::cout<<"Client received message from server: ", in_buffer;

            }
if (mq_close (qd_client) == -1) {
        perror ("Client: mq_close");
        exit (1);
    }

    if (mq_unlink (client_queue_name) == -1) {
        perror ("Client: mq_unlink");
        exit (1);
    }
    std::cout<<"Client: bye\n";

    exit (0);
    }
    }//end main
    
