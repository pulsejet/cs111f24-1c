#include <unistd.h>
#include <stdio.h>

int main () {

	int pipefd[2];

	if (pipe(pipefd) != 0 )
		return 17;

	int r_side = pipefd[0];
	int w_side = pipefd[1];

	dup2(w_side, 1);

	printf("This is the printf Hello World");
	fflush(stdout);
	fprintf(stderr, "This is stderr\n");


	char buf[100];
	int num_bytes = read(r_side, buf, sizeof(buf));

	fprintf(stderr, "r_side: %d, w_side: %d\n", r_side, w_side);
	fprintf(stderr, "Buffer contains: %s (%d bytes)", buf, num_bytes);

	return 0;
}
