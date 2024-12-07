/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akwadran <akwadran@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 22:42:02 by akwadran          #+#    #+#             */
/*   Updated: 2024/12/08 00:18:54 by akwadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdlib.h>
#include <unistd.h>
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
	static int count = 0;
    
    if (n == -2147483648)
        return (ft_putstr("-2147483648"));
    else if (n < 0)
    {
        ft_putchar('-');
        count++;
        n = -n;
    }
    if (n >= 10)
	{
        ft_putnbr((n / 10));
		ft_putchar(((n % 10) + '0'));
        count++;
    }
	if (n < 10)
    {
		ft_putchar((n + '0'));
        count++;
    }
    return (count);
}