#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    pid_t pid;

    int pipefd[2];
    pipe(pipefd);

    pid = fork();

    if (pid < 0) {
        // Error occurred 
        fprintf(stderr, "Fork failed\n");
        return 1;
    } else if (pid == 0) {
        // Child process
        printf("Hello from child process (PID: %d)\n", getpid());

	write(pipefd[1], "Hello", 6);
    } else {
        // Parent process
        printf("Hello from parent process (PID: %d, Child PID: %d)\n", getpid(), pid);


	char buf[100];
	read(pipefd[0], buf, sizeof(buf));

	printf("The child said: %s\n", buf);
    }

    return 0;
}
