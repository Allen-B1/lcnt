#include <lcnt_vec.h>
#include <stdio.h>

int main() {
	lcnt_vec v;
	lcnt_vec_init(&v, sizeof(int));
	lcnt_vec_add_value(&v, 2, int);
	lcnt_vec_add_value(&v, 3, int);
	lcnt_vec_add_value(&v, 5, int);
	lcnt_vec_add_value(&v, 6, int);
	printf("pop %d\n", *(int*)lcnt_vec_pop(&v));
	lcnt_vec_add_value(&v, 7, int);
	lcnt_vec_grow(&v, 7);
	lcnt_vec_set_value(&v, 4, 11, int);
	lcnt_vec_set_value(&v, 5, 13, int);
	lcnt_vec_set_value(&v, 6, 17, int);

	for (size_t i = 0; i < v.len; i++) {
		printf("%d ", lcnt_vec_get_value(&v, i, int));
	}
	putchar('\n');

	lcnt_vec_free(&v);
	return 0;
}
