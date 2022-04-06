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

class Message{
public:
	std::string input();
	void output();
	
	
private:
	std::string src;
	
};

std::string Message::input()
{
	src = "hello";
	const char * message = src.c_str();
	std::cout<<message;
}

void Message::output() 
{
	std::cout << "\nMessage sent to client\n";
}


const std::string str1  = "/sp-server";
const char * SERVER_QUEUE_NAME   = str1.c_str();
const int QUEUE_PERMISSIONS = 0660;
const int MAX_MESSAGES = 10;
const int MAX_MSG_SIZE = 256;
const int MSG_BUFFER_SIZE = MAX_MSG_SIZE + 10;

int main(int argc, char **argv)
{

    // Creating object of the class
    Message obj;
  
   
   mqd_t qd_server, qd_client;   // queue descriptors
    //long token_number = 1; 

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
 

        if ((qd_server = mq_open (SERVER_QUEUE_NAME, O_RDONLY | O_CREAT, QUEUE_PERMISSIONS, &attr)) == -1) {
        perror ("Server: mq_open (server)");
        exit (1);
    }
    while (1) {
        
        
        std::cout<< out_buffer<<obj.input()<<std::endl;//call object ("hello")

        if (mq_send (qd_client, out_buffer, strlen (out_buffer) + 1, 0) == -1) {
            perror ("Server: Not able to send message to client");
            continue;
        }

        //std::cout<<"Server: response sent to client.\n";
        obj.output();//call object (input/output)
    }//end while
    
    
}//end of main


