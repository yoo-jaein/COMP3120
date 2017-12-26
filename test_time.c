// Lab2-Q1
// gettimeofday()를 사용하여 프로그램 시작과 끝의 시간을 출력한다.
// 1 마이크로초까지 나타낼 수 있다.

#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>

int main(void) {
	struct timeval mytime;

	gettimeofday(&mytime, NULL);
	printf("%ld:%ld\n", mytime.tv_sec, mytime.tv_usec);


	gettimeofday(&mytime, NULL);
	printf("%ld:%ld\n", mytime.tv_sec, mytime.tv_usec);
	return 0;
}
