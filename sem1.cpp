#include<iostream>
#include<semaphore.h>
#include<fcntl.h>
#include<sys/stat.h>
using namespace std;
int main(int argc, char **argv)
{
	int flags;
	sem_t *sem;
	unsigned int value;
	flags = O_RDWR | O_CREAT;
	value = atoi(argv[2]);
	sem = sem_open(argv[1], flags, 0777, value);
	sem_getvalue(sem, &value);
	printf("%d\n", value);
	sem_close();
	exit(0);
}
