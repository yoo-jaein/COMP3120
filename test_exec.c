// Lab1-Q4
// child에서 exec()의 한 종류를 사용하여 ls를 실행한다.

#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void) {
	int pid = fork();
	char *argv[]={"ls", ".", NULL};

	if (pid == 0) {
		execv("/bin/ls", argv);
	} else {
		waitpid(pid,0,0);
	}
		
	return 0;
}
