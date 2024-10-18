#include <sys/queue.h>
#include <stdio.h>

struct person {
	char * name;
	TAILQ_ENTRY(person) ptrs;
};

TAILQ_HEAD(people, person);

int main() {
	struct person alice;
	alice.name = "alice";

	struct person bob;
	bob.name = "bob";

	struct person cathy;
	cathy.name = "cathy";

	struct people head;
	TAILQ_INIT(&head);

	if (TAILQ_EMPTY(&head)) printf("1: Queue is empty\n");
	else printf("1: Queue is not empty\n");

	TAILQ_INSERT_TAIL(&head, &alice, ptrs);
	TAILQ_INSERT_TAIL(&head, &bob, ptrs);
	TAILQ_INSERT_TAIL(&head, &cathy, ptrs);

	if (TAILQ_EMPTY(&head)) printf("2: Queue is empty\n");
	else printf("2: Queue is not empty\n");

	struct person* first;

	first = TAILQ_FIRST(&head);
	printf("3: First is %s\n", first->name);
	TAILQ_REMOVE(&head, first, ptrs);
	TAILQ_INSERT_TAIL(&head, first, ptrs);

	first = TAILQ_FIRST(&head);
	printf("4: First is %s\n", first->name);
	TAILQ_REMOVE(&head, first, ptrs);
	TAILQ_INSERT_TAIL(&head, first, ptrs);

	first = TAILQ_FIRST(&head);
	printf("5: First is %s\n", first->name);
	TAILQ_REMOVE(&head, first, ptrs);
	TAILQ_INSERT_TAIL(&head, first, ptrs);

	first = TAILQ_FIRST(&head);
	printf("6: First is %s\n", first->name);
	TAILQ_REMOVE(&head, first, ptrs);
	TAILQ_INSERT_TAIL(&head, first, ptrs);

	return 0;
}
