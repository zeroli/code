#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

pthread_mutex_t count_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t condition_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t condition_cond = PTHREAD_COND_INITIALIZER;

void* functionCount1(void*);
void* functionCount2(void*);

int count = 0;

#define COUNT_DONE 10
#define COUNT_HALT1 3
#define COUNT_HALT2 6

int main()
{
	pthread_t thread1, thread2;
	pthread_create(&thread1, NULL, &functionCount2, NULL);
	pthread_create(&thread2, NULL, &functionCount1, NULL);

	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);

	return 0;
}

void* functionCount1(void*)
{
#if 1
	int cnt = 0;
	while (cnt < 20) {
		pthread_mutex_lock(&condition_mutex);
		if (count>0)
			pthread_cond_signal(&condition_cond);
		pthread_mutex_unlock(&condition_mutex);		

		pthread_mutex_lock(&count_mutex);
		printf("One packge put into queue.count=%d\n", count);
		++count;
		pthread_mutex_unlock(&count_mutex);
		cnt++;
	}
#else
	for (; ; ) {
		pthread_mutex_lock(&condition_mutex);
		while (count >= COUNT_HALT1 && count <= COUNT_HALT2)
			pthread_cond_wait(&condition_cond, &condition_mutex);
		pthread_mutex_unlock(&condition_mutex);

		pthread_mutex_lock(&count_mutex);
		count++;
		printf("Counter value functionCount1: %d\n", count);
		pthread_mutex_unlock(&count_mutex);
		
		if (count >= COUNT_DONE) return NULL;
	}
#endif
}

void* functionCount2(void*)
{
#if 1
	int cnt=0;
	while (cnt<20) {
		pthread_mutex_lock(&condition_mutex);
		while (count<=0) 
			pthread_cond_wait(&condition_cond, &condition_mutex);
		pthread_mutex_unlock(&condition_mutex);
		
		pthread_mutex_lock(&count_mutex);
		count--;
		printf("pack removed from queue: count=%d\n", count);
		pthread_mutex_unlock(&count_mutex);
		cnt++;
	}
#else
	for (; ; ) {
		pthread_mutex_lock(&condition_mutex);
		if (count < COUNT_HALT1 || count > COUNT_HALT2)
			pthread_cond_signal(&condition_cond);
		pthread_mutex_unlock(&condition_mutex);
		
		pthread_mutex_lock(&count_mutex);
		count++;
		printf("Counter value functionCount2:%d\n", count);
		pthread_mutex_unlock(&count_mutex);
		
		if (count >= COUNT_DONE) return NULL;
	}
#endif
}
		
