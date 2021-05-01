#include <stdio.h>

typedef struct s_data {
	int a, b;
} t_data;

int test(t_data *data) {
	data->a = 5;
	(*data).a = 5;
}

int main (void) {
	t_data data;

	test(&data);
}
