#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <mutex>

#define THREAD_COUNT 20

int shared = 0;
std::mutex m;

void* my_thread(void * param) {
	printf("Entered the thread\n");

	for (int i = 0; i < 10000; i++) {
		std::lock_guard<std::mutex> _lock(m);
		shared++;

		if (shared == 200) return NULL;
	}

	printf("Exiting the thread, shared=%d\n", shared);
}

int main() {
	pthread_t thread[THREAD_COUNT];

	printf("Started main function\n");

	for (size_t i = 0; i < THREAD_COUNT; i++)
		pthread_create(&thread[i], NULL, my_thread, NULL);

	for (size_t i = 0; i < THREAD_COUNT; i++)
		pthread_join(thread[i], NULL);

	printf("Final value of shared=%d", shared);

	return 0;
}
