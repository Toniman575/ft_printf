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
	printf("Length mine:: %d\n", a);
	b = printf("%d\n", 1);
	printf("Length og: %d\n", b);

	a = ft_printf("%d\n", INT_MAX);
	printf("Length mine:: %d\n", a);
	b = printf("%d\n", INT_MAX);
	printf("Length og: %d\n", b);
	
	a = ft_printf("%d\n", INT_MIN);
	printf("Length mine:: %d\n", a);
	b = printf("%d\n", INT_MIN);
	printf("Length og: %d\n", b);
	
	a = ft_printf("%d\n", 0);
	printf("Length mine:: %d\n", a);
	b = printf("%d\n", 0);
	printf("Length og: %d\n", b);

	a = ft_printf("%s\n", "imagine");
	printf("Length mine:: %d\n", a);
	b = printf("%s\n", "imagine");
	printf("Length og: %d\n", b);

}