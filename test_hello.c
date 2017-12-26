// Lab1-Q3
// child에서 hello를 출력하고 parent에서 goodbye를 출력한다.

#include <stdio.h>
#include <sys/types.h>

int main(void) {
	int pid = fork();
	 
	if (pid == 0) {
		printf("hello\n");
	} else {
		sleep(1);
		printf("goodbye\n");
	}
	
	return 0;
}
