// Lab1-Q5
// parent가 끝날 때 까지 child를 wait한다.
// waitpid의 리턴값을 출력한다.

#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void) {
	int ppid = (int)getpid();
	int pid = fork();
	
	if (pid == 0) {
		printf("return value of wait() in child == %d\n", waitpid(ppid,0,0));
	} else {
	}

	return 0;
}
