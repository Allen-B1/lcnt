#include <lcnt_list.h>
#include <stdio.h>

#define intoptr(val, T) (T[]){(val)}

int main() {
	lcnt_list primes;
	lcnt_list_init(&primes, sizeof(int));
	lcnt_list_add(&primes, intoptr(3, int));
	lcnt_list_add(&primes, intoptr(5, int));
	lcnt_list_add(&primes, intoptr(7, int));
	lcnt_list_prepend(&primes, intoptr(2, int));

	lcnt_list_node* node;
	lcnt_list_foreach(&primes, &node) {
		printf("%d ", *(int*)node->data);
	}
	putchar('\n');

	lcnt_list_free(&primes);
	return 0;
}
