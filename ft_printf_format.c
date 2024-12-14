/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_format.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akwadran <akwadran@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 22:42:02 by akwadran          #+#    #+#             */
/*   Updated: 2024/12/14 16:17:23 by akwadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdlib.h>
#include <unistd.h>
#include <stdlib.h>
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

    if (s == NULL)
        return (ft_putstr("(null)"));
    len = 0;
    while (s[len])
	{
		write(1, &s[len], 1);
		len++;
	}
    return (len);
}

int ft_putnbr(int n)
{
    int     count;
    char    *n_str;

    n_str = ft_itoa(n);
    count = ft_putstr(n_str);
    free(n_str);
    return (count);
}

int	ft_putnbr_unsigned(unsigned long long n)
{
   /* static int count = 0;

    if (n >= 10)
	{
        ft_putnbr_unsigned((n / 10));
		count += ft_putchar(((n % 10) + '0'));
    }
	if (n < 10)
		count += ft_putchar((n + '0'));
    return (count);*/
    int     count;
    char    *n_str;

    n_str = ft_itoa_uns(n);
    count = ft_putstr(n_str);
    free(n_str);
    return (count);

}

int ft_puthexa(unsigned long long n, char *base)
{
    /*static int      count;

    count = 0;
    if (n >= 16)
    {
        ft_puthexa(n / 16, base);
        count += ft_putchar((base[n % 16]));
    }
    if (n < 16)
    {
        count += ft_putchar(base[n]);
        return (count);
    }
    return (count);*/

    int     count;
    char    *n_str;

    n_str = ft_itoa_hexa(n, base);
    count = ft_putstr(n_str);
    free(n_str);
    return (count);

}
