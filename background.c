#include<semaphore.h>
#include<fcntl.h>
#include<stdio.h>
int main(int argc, char **argv)
{
	int flags;
	flags = O_RDWR | O_CREAT;
	sem_t *sem1 = sem_open("/named_semaphore1", flags, 0777, 1);
	sem_t *sem2 = sem_open("/named_semaphore2", flags, 0777, 0);
	int counter = 0;
	while(counter <= 10)
	{
		sem_wait(sem2);
		printf("PId = %d, Counter = %d\n",getpid(),counter);
		counter++;
		sem_post(sem1);
	}
	//sem_close(sem1);
	//sem_unlink("/named_semaphore");
	return 0;
}
