#include "ft_printf.h"
#include <stdio.h>
int main (void)
{
	printf("%d - ", printf("%p", NULL));
	printf("\n");
	printf("\n%d - ", ft_printf("%p", NULL));
	return (0);
}