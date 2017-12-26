// Lab1-Q6
// 두 child를 pipe로 연결한다.

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define MSGLEN 64

int main(){
	int fd[2];
	pid_t pid1, pid2;

	pipe(fd);
	
	pid1 = fork();
   	if (pid1 < 0) {
		perror("fork1 error");
         	return -1;
    	}

   	if (pid1 == 0) {		
		char message[MSGLEN];
        	memset(message, 0, sizeof(message));
                printf("[pid1] Enter a message: ");
                scanf("%s",message);

                write(fd[1], message, strlen(message));
                return -1;
   	} 


	pid2 = fork();
	if (pid2 < 0) {
		perror("fork2 error");
		return -1;
	}
	if (pid2 == 0) {
		
                char message[MSGLEN];
		memset(message, 0, sizeof(message));
		
		read(fd[0], message, sizeof(message));
         	printf("[pid2] Message entered: %s\n",message);
         	return -1;
     	}


	close(fd[0]);
	close(fd[1]);
	
	waitpid(pid1,0,0);
	waitpid(pid2,0,0);
	printf("[parent]\n");

	return 0;
}
