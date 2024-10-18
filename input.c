#include <stdio.h>

int main() {
	printf("Hello World\n");

	int s = 0;
	while (1) s++;

	char line[1024];
	fgets(line, sizeof(line), stdin);

	printf("User said: %s\n", line);

	return 0;
}
