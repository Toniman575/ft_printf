#include <stdlib.h>
#include <limits.h>
#include "ft_printf.h"
#include <stdio.h>

int main()
{
	//char *test = "asd";
	int a = ft_printf("%d\n", 10000500);
	printf("Length mine: %d\n", a);
	int b = printf("%d\n", 10000500);
	printf("Length og: %d\n", b);
	a = ft_printf("%d\n", 10);
	printf("Length mine: %d\n", a);
	b = printf("%d\n", 10);
	printf("Length og: %d\n", b);

	a = ft_printf("%d\n", 1);
	printf("Length mine: %d\n", a);
	b = printf("%d\n", 1);
	printf("Length og: %d\n", b);

	a = ft_printf("%d\n", INT_MAX);
	printf("Length mine: %d\n", a);
	b = printf("%d\n", INT_MAX);
	printf("Length og: %d\n", b);
	
	a = ft_printf("%d\n", INT_MIN);
	printf("Length mine: %d\n", a);
	b = printf("%d\n", INT_MIN);
	printf("Length og: %d\n", b);
	
	a = ft_printf("%d\n", 0);
	printf("Length mine: %d\n", a);
	b = printf("%d\n", 0);
	printf("Length og: %d\n", b);

	a = ft_printf("%s\n", "imagine");
	printf("Length mine: %d\n", a);
	b = printf("%s\n", "imagine");
	printf("Length og: %d\n", b);
	
	a = ft_printf(" %s %s ", "", "-");
	printf("Length mine: %d\n", a);
	b = printf(" %s %s ", "", "-");
	printf("Length og: %d\n", b);
	
	b = printf(" NULL %s NULL ", NULL);
	printf("Length og: %d\n", b);
	a = ft_printf(" NULL %s NULL ", NULL);
	printf("Length mine: %d\n", a);

	a = ft_printf("%c", 'i');
	printf("Length mine: %d\n", a);
	b = printf("%c", 'i');
	printf("Length og: %d\n", b);
	
	a = ft_printf("%c", '0' - 256);
	printf("Length mine: %d\n", a);
	b = printf("%c", '0' - 256);
	printf("Length og: %d\n", b);

	void *random_pointer = malloc(5);

	a = ft_printf("%p", random_pointer);
	printf("Length mine: %d\n", a);
	b = printf("%p", random_pointer);
	printf("Length og: %d\n", b);

	a = ft_printf(" %p %p ", LONG_MIN, LONG_MAX);
	printf("Length mine: %d\n", a);
	b = printf(" %p %p ", LONG_MIN, LONG_MAX);
	printf("Length og: %d\n", b);

	a = ft_printf( " %p %p ", ULONG_MAX, -ULONG_MAX);
	printf("Length mine: %d\n", a);
	b = printf( " %p %p ", ULONG_MAX, -ULONG_MAX);
	printf("Length og: %d\n", b);

	free(random_pointer);
}