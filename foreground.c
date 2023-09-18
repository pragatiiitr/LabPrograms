#include<semaphore.h>
#include<fcntl.h>
#include<stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc, char **argv)
{
	int flags;
	flags = O_RDWR | O_CREAT;
	sem_t *sem1 = sem_open("/named_semaphore1", flags, 0777, 1);
	sem_t *sem2 = sem_open("/named_semaphore2", flags, 0777, 0);
	int counter = 0;
	while(counter <= 10)
	{
		printf("calling wait\n");
		sem_wait(sem1);
		printf("PId = %d, Counter = %d\n",getpid(),counter);
		counter++;
		sem_post(sem2);
	}
	//sem_close(sem2);
	return 0;
}
