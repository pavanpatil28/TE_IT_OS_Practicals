#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/shm.h>
#include <string.h>

int main(){
	void *shared_memory;
	char buff[100];//To store user input message
	int shmid;
	shmid=shmget((key_t)1122,1024,0666|IPC_CREAT);//creating shared memory segment with key
	
	printf("Key of shared memory is: %d\n",shmid);
	
	shared_memory=shmat(shmid,NULL,0);//process attached to memory segment
	
	printf("Process attached at address: %p\n",shared_memory);
	
	printf("Enter a message to write to shared memory: \n");
	
	read(0,buff,100);//get some input from user
	
	strcpy(shared_memory,buff);//data written to shared memory
	
	printf("Your Entered Message :%s\n",(char *)shared_memory);
	
}



