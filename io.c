#include <stdio.h>
#include <unistd.h>

int main() {
	
	char buf[10];

	int num_bytes = read(0, buf, sizeof(buf));

	printf("The buffer has: %s (%d bytes)", buf, num_bytes);

	return 0;
}
