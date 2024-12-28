#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int main (void)
{
	char    ch = 'K';
    char    name[] = "Ania";
    int     num = 123456789;
    int     ctrl;
    unsigned int    uint_max = 4294967295;
    void    *ptr = NULL; 


    printf("/ STR, CHAR, INT, %% /\n");
    printf("F: ");
    ctrl = ft_printf("Hej jestem %s%c i mam %d%% tyle.\n", name, ch, num);
    printf("%d\n", ctrl);
    printf("P: ");
    ctrl = printf("Hej jestem %s%c i mam %d%% tyle.\n", name, ch, num);
    printf("%d\n", ctrl);

    char *strptr = NULL;
    ch = '\0';
    num = 0;
    printf("F: ");
    ctrl = ft_printf("Hej jestem %s%c i mam %d%% tyle.\n", strptr, ch, num);
    printf("%d\n", ctrl);
    printf("P: ");
    ctrl = printf("Hej jestem %s%c i mam %d%% tyle.\n", strptr, ch, num);
    printf("%d\n", ctrl);

    printf("/ UNSIGED INT /\n");
    ctrl = ft_printf("%u\n", uint_max);
    printf("%d\n", ctrl);
    ctrl = printf("%u\n", uint_max);
    printf("%d\n", ctrl);
    
    printf("/ HEXADECIMAL /\n");
    ctrl = printf("p: %x %X\n", 29, 29);
    printf("%d\n", ctrl);
    ctrl = ft_printf("f: %x %X\n", 29, 29);
    printf("%d\n", ctrl);
    ctrl = printf("p: %x %X\n", 5674, 905431);
    printf("%d\n", ctrl);
    ctrl = ft_printf("f: %x %X\n", 5674, 905431);
    printf("%d\n", ctrl);

    printf("/ HEXADECIMAL MIN MAX/\n");
    ctrl = printf("p: %lx %lX\n", __LONG_MAX__, __LONG_MAX__);
    printf("%d\n", ctrl);
    ctrl = ft_printf("f: %x %X\n", __LONG_MAX__, __LONG_MAX__);
    printf("%d\n", ctrl);

    printf("/ POINTER /\n");
    ptr = &name;
    ctrl = printf("pointer: %p\n\n", ptr);
    ctrl = ft_printf("ft_pointer: %p\n\n", ptr);
    

    int n = 12345;
    ctrl = ft_printf("%d\n", n);
    printf("%d\n", ctrl);
    ctrl = printf("%d\n", n);
    printf("%d\n", ctrl);
	
	
	
	//printf("%d - ", printf("%p", NULL));
	//printf("\n");
	//printf("\n%d - ", ft_printf("%p", NULL));


	void	*ptr3 = NULL;
	
	printf("%d\n", printf("%p\n", ptr3));
	ft_printf("%d\n", ft_printf("%p\n", ptr3));	

	printf("%d\n", printf("%d %x\n", LONG_MAX, LONG_MAX));
	ft_printf("%d\n", ft_printf("%d %x\n", LONG_MAX, LONG_MAX));

	printf("%d\n", printf("%d %x\n", LONG_MIN, LONG_MIN));
	ft_printf("%d\n", ft_printf("%d %x\n", LONG_MIN, LONG_MIN));

	printf("%d\n", printf("%u %x\n", ULONG_MAX, ULONG_MAX));
	ft_printf("%d\n", ft_printf("%u %x\n", ULONG_MAX, ULONG_MAX));


	ft_printf("%pp%p%p\n", (void *)LONG_MAX + 423856, (void *)0, (void *)INT_MAX); //returned: 34, but expected: 32
    printf("%pp%p%p\n", (void *)LONG_MAX + 423856, (void *)0, (void *)INT_MAX); //different memory

	return (0);
}