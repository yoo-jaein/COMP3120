// Lab2-Q2
// num_thread개 만큼의 스레드를 만들고 counter를 0부터 goal까지 센다.
// 실행시간을 출력한다.

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/time.h>
#include <unistd.h>

#define num_thread 4
#define goal 1000

struct thread_args {
	int thread_id;
	int start;
	int end;
};

int counter = 0;

void mythread(void *args) {
	struct thread_args *arg = (struct thread_args *) args;
	int i;

	for(i = arg->start; i <= arg->end; i++)
		counter++;

	pthread_exit(0);
}

int main(void) {
	struct timeval mytime[2], result;
	struct thread_args arr[num_thread];
	pthread_t thrd[num_thread];
	int i;
		
	gettimeofday(&mytime[0], NULL);
	
	for(i = 0; i < num_thread; i++) {
		arr[i].thread_id = i;
		arr[i].start = (goal/num_thread)*i+1;
		arr[i].end = (goal/num_thread)*(i+1);
		pthread_create(&thrd[i], NULL, mythread, &arr[i]);
	}
	
	for(i = 0; i < num_thread; i++) {
		pthread_join(thrd[i], NULL);
	}
	
	printf("counter = %d\n", counter);
	printf("number of threads = %d\n", num_thread);

	gettimeofday(&mytime[1], NULL);
	timersub(&mytime[1], &mytime[0], &result);
	printf("time.tv_usec = %ld\n", result.tv_usec);
	
	return 0;
}
