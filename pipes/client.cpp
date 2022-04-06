#include<stdio.h>
#include<cstdlib>
#include<iostream>
#include<unistd.h>

#include<sys/stat.h>
#include<sys/types.h>
#include<errno.h>
#include<fcntl.h>
#include<ctime>

int main(int argc, char* argv[]){
	int arr[5], i;
	
	srand(time(NULL));//create different sequence of random numbers on every program run.
	for (i=0;i<5;i++){
		arr[i] = rand() % 100;
		std::cout<<"Generated "<< arr[i]<<std::endl;
	}

	int fd = open("sum", O_WRONLY);
	if(fd==-1){
	std::cout<<"Cannot open, check if file descriptor exists or if mkfifo is done correctly";
	}
	
	    if(write(fd, arr, sizeof(int)*5) == -1){
	    	std::cout<<"Something wrong....could not write";
	    	return 2;
	    }
	    
	
	close(fd);	
	

	return 0;
}
