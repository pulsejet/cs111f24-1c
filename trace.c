#include <unistd.h>
#include <stdio.h>

int main() {
	write(1, "Hello World", 12);

	sleep(3);

	printf("Second line");

	return 0;
}
