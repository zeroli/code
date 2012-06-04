#include <pthread.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

#define handle_error_en(en, msg) \
	do { errno = en; perror(msg); exit(EXIT_FAILURE); } while (0)

static int done = 0;
static int cleanup_pop_arg = 1;
static int cnt = 0;

static void cleanup_handler(void* arg)
{
	printf("Called clean-up handler\n");
	cnt = 0;
}

static void* thread_start(void* arg)
{
	time_t start, curr;
	printf("New thread started\n");

	pthread_cleanup_push(cleanup_handler, NULL);
	curr = start = time(0);

	while (!done) {
		pthread_testcancel();
		if (curr < time(0)) {
			curr = time(0);
			printf("cnt = %d\n", cnt);
			cnt++;
		}
	}

	pthread_cleanup_pop(cleanup_pop_arg);
	return 0;
}

int main(int argc, char** argv)
{
	pthread_t thr;
	int s;
	void* res;
	s = pthread_create(&thr, NULL, thread_start, NULL);
	if (s != 0)
		handle_error_en(s, "thread_create");
	sleep(2);

	if (argc > 1) {
		if (argc > 2) 
			cleanup_pop_arg = atoi(argv[2]);
		done = 1;
	} else {
		printf("canceling thread\n");
		s = pthread_cancel(thr);
		if (s != 0)
			handle_error_en(s, "thread_cancel");
	}
	s = pthread_join(thr, &res);
	if (s != 0)
		handle_error_en(s, "thread_join");
	if (res == PTHREAD_CANCELED)
		printf("Thread was canceled; cnt = %d\n", cnt);
	else
		printf("Thread terminated normally; cnt = %d\n", cnt);
	exit(0);
}

