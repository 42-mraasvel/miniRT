#include <stdio.h>

typedef enum	e_type
{
	sphere,
	plane,
	square,
	cylinder,
	triangle
}				t_type;

typedef struct s_str
{
	t_type type;
	int a;
}				t_str;

typedef void (*t_intersect)(void*);

void intersect_sphere(void* str)
{
	printf("%d\n", ((t_str*)str)->a);
}

int func(void *str)
{
	static const t_intersect table[] = {
		intersect_sphere
	};
	table[*(t_type*)str](str);
	return (0);
}

int	main(void)
{
	t_str test;
	test.type = sphere;
	test.a = 12387;
	
	func((void*)&test);
	return (0);
}