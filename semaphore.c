#include<semaphore.h>
#include<fcntl.h>
int main(int argc, char **argv)
{
	int flags;
	flags = O_RDWR | O_CREAT;
	sem_t *sem1 = sem_open("/named_semaphore1", flags, 0777, 1);
	sem_t *sem2 = sem_open("/named_semaphore2", flags, 0777, 0);
	//sem_close(sem1);
	//sem_close(sem2);
	return 0;
}
