#include <lcnt.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>
#include <time.h>

#define intoptr(val, T) (T[]){(val)}

void test_list() {
	lcnt_list nums;
	lcnt_list_init(&nums, sizeof(int));
	lcnt_list_append(&nums, intoptr(2, int));
	lcnt_list_node* three = lcnt_list_append(&nums, intoptr(3, int));
	lcnt_list_append(&nums, intoptr(5, int));
	lcnt_list_insert(&nums, three, intoptr(4, int));
	lcnt_list_prepend(&nums, intoptr(1, int));

	lcnt_list_node* node;
	lcnt_list_foreach(&nums, &node) {
		printf("%d ", *(const int*)lcnt_list_get(&nums, node));
	}
	putchar('\n');

	free(lcnt_list_remove_after(&nums, three));
	free(lcnt_list_remove_start(&nums));
	lcnt_list_append(&nums, intoptr(7, int));

	lcnt_list_foreach(&nums, &node) {
		printf("%d ", *(const int*)lcnt_list_get(&nums, node));
	}
	putchar('\n');

	lcnt_list_free(&nums);
}

void test_vec() {
	lcnt_vec nums;
	lcnt_vec_init(&nums, sizeof(double));
	*(double*)lcnt_vec_append(&nums) = 2.71;
	*(double*)lcnt_vec_append(&nums) = 8.0;
	*(double*)lcnt_vec_append(&nums) = 3.14;

	lcnt_vec_remove(&nums, 1);
	*(double*)lcnt_vec_append(&nums) = 5.0;
	*(double*)lcnt_vec_insert(&nums, 1) = 7.0;

	size_t index;
	printf("nums = ");
	lcnt_vec_foreach(&nums, &index) {
		printf("%.2f ", *(const double*)lcnt_vec_get(&nums, index));
	}
	putchar('\n');

	lcnt_vec_free(&nums);
}

void test_map() {
	lcnt_map grades;
	lcnt_map_init(&grades, &lcnt_ktype_string, sizeof(uint8_t), 16);
	*(uint8_t*)lcnt_map_set(&grades, &"Alice") = rand() % 100;
	*(uint8_t*)lcnt_map_set(&grades, &"Bob") = rand() % 100;
	*(uint8_t*)lcnt_map_set(&grades, &"Charlie") = rand() % 100;
	*(uint8_t*)lcnt_map_set(&grades, &"David") = rand() % 100;

	lcnt_map_remove(&grades, &"David");

	size_t len;
	const char** keys = lcnt_map_keys(&grades, &len);
	for (size_t i = 0; i < len; i++) {
		printf("%s has a %" PRIu8 "%%\n", keys[i], *(const uint8_t*)lcnt_map_get(&grades, keys[i]));
	}
	free(keys);

	lcnt_map_free(&grades);
}

int main() {
	srand(time(NULL));

	puts("== TESTING LIST ==");
	test_list();

	puts("== TESTING VEC ==");
	test_vec();

	puts("== TESTING MAP ==");
	test_map();

	return 0;
}
