#include<stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/shm.h>
#include <string.h>

int main(){
	void *shared_memory;
	char buff[100];//To store user input message
	int shmid;
	shmid=shmget((key_t)1122,1024,0666);//creating shared memory segment with key
	printf("Key of shared memory is  :%d\n",shmid);
	shared_memory=shmat(shmid,NULL,0);//process attached to memory segment
	printf("Process attached at address :%p\n",shared_memory);
	printf("Data read from shared memory is  : %s\n",(char *)shared_memory);
	
	return 0;
}
