// Lab1-Q2
// open을 사용하여 파일을 연다.
// child에서도 open으로 파일을 열고 write()한다.

#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int main(void) {
	int filedesc = open("testfile.txt", O_WRONLY | O_APPEND);
	int pid;	

	if (filedesc < 0)
		return 1;

	pid = fork();

	if (pid == 0) {
		filedesc = open("testfile.txt", O_WRONLY | O_APPEND);		
		printf("child %d\n", filedesc);
		if (write(filedesc, "This will be output to testfile.txt using child\n", 48) != 48) {
			write(2, "[c] There was an error writing to testfile.txt\n", 47);
			return -1;
		}
		if (write(filedesc, "hello child\n", 12) != 12) {
			printf("error\n");
			return -1;
		}
	} else {
		printf("parent %d\n", filedesc);
		if (write(filedesc, "This will be output to testfile.txt using parent\n", 49) != 49) {
			write(2, "[p] There was an error writing to testfile.txt\n", 47);
			return -1;
		}
		if (write(filedesc, "hello parent\n", 13) != 13) {
			printf("error\n");
			return -1;
		}
	}

	return 0;
}
