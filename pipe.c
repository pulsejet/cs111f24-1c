#include <unistd.h>
#include <stdio.h>

int main () {

	int pipefd[2];

	if (pipe(pipefd) != 0 )
		return 17;

	int r_side = pipefd[0];
	int w_side = pipefd[1];

	char hello[] = "Hello, World!";

	write(w_side, hello, sizeof(hello));

	char buf[100];

	int num_bytes = read(r_side, buf, sizeof(buf));

	printf("r_side: %d, w_side: %d\n", r_side, w_side);
	printf("Buffer contains: %s (%d bytes)", buf, num_bytes);

	return 0;
}
