#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    pid_t pid;

    pid = fork();

    if (pid < 0) {
        // Error occurred 
        fprintf(stderr, "Fork failed\n");
        return 1;
    } else if (pid == 0) {
        // Child process
        printf("Hello from child process (PID: %d)\n", getpid());

	execl("/bin/ls", "ls", "-lrth", 0);

	printf("Goodbye from child\n");

    } else {
        // Parent process
        printf("Hello from parent process (PID: %d, Child PID: %d)\n", getpid(), pid);
    }

    printf("Last statement\n");

    return 0;
}
