#include<stdio.h>
#include<cstdlib>
#include<iostream>
#include<unistd.h>

#include<sys/stat.h>
#include<sys/types.h>
#include<errno.h>
#include<fcntl.h>
#include<time.h>

int main(int argc, char* argv[]){
	int arr[5], i;
		
	int fd = open("sum", O_RDONLY);
	
	if(fd==-1){
	   std::cout<<"Error opening. Check if file descriptor exists already or check if mkfifo is done properly";
	   return 1;
	}
	
	for (i=0;i<5;i++){
	    if(read(fd, &arr[i], sizeof(int))==-1){
	    std::cout<<"Something wrong...could not read array";
	    return 2;}//close if
	    std::cout<<"Read "<< arr[i]<<std::endl;
	}
	
	int sum = 0;
	for (i = 0; i < 5; i++){
		sum += arr[i];}//all elements summed
	std::cout<<"Sum result is "<< sum;
	
	close(fd);
	
return 0;
}
