#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
	int fdA, fdB, fdC;

	fdA = open("FileA", O_RDONLY);
	fdB = open("FileB", O_RDWR | O_CREAT | O_TRUNC, 0664);
	fdC = open("FileC", O_WRONLY | O_CREAT | O_APPEND, 0664);

	printf("%d, %d, %d\n", fdA, fdB, fdC);

	close(fdA);
	close(fdB);
	close(fdC);

	return 0;
}

