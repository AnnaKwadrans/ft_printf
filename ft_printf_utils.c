/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akwadran <akwadran@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 22:42:02 by akwadran          #+#    #+#             */
/*   Updated: 2024/12/08 09:18:24 by akwadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdlib.h>
#include <unistd.h>
#include <stdio.h> //quitar
#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
    return (1);
}

int	ft_putstr(char *s)
{
	int len;

    len = 0;
    while (s[len])
	{
		write(1, &s[len], 1);
		len++;
	}
    return (len);
}

int	ft_putnbr(int n)
{
    static int  count = 0;
    int         aux;

    if (n == -2147483648)
        return (ft_putstr("-2147483648"));
    else if (n < 0)
    {
        count = count + ft_putchar('-');
        n = -n;
    }
    if (n >= 10)
	{
        ft_putnbr((n / 10));
		count = count + ft_putchar(((n % 10) + '0'));
    }
	if (n < 10)
		count = count + ft_putchar((n + '0'));
    aux = count;
    count = 0;
    return (aux);
}

int	ft_putnbr_unsigned(unsigned int n)
{
    static int count = 0;

    if (n >= 10)
	{
        ft_putnbr_unsigned((n / 10));
		count = count + ft_putchar(((n % 10) + '0'));
    }
	if (n < 10)
		count = count + ft_putchar((n + '0'));
    return (count);
}

int ft_puthexa(unsigned long long int n, char *base)
{
    static int      count = 0;
    int             aux;

    if (n >= 16)
    {
        ft_puthexa(n / 16, base);
        count = count + ft_putchar((base[n % 16]));
    }
    if (n < 16)
    {
        count = count + ft_putchar(base[n]);
        aux = count;
        count = 0;
        return (aux);
    }
    return (count);
}
