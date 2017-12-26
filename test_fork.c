// Lab1-Q1
// fork()를 사용하여 child를 만든다.
// x의 값을 확인한다.

#include <stdio.h>
#include <sys/types.h>

int main(void) {
	int x = 100;
	int pid = fork();
	
	if(pid == 0) {
		printf("x of child process == %d\n", x);
	} else {
		printf("x of parent process == %d\n", x);
	}

	return 0;
}
