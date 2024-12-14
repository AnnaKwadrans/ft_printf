/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_uns.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akwadran <akwadran@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 16:05:45 by akwadran          #+#    #+#             */
/*   Updated: 2024/12/14 16:19:42 by akwadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h> //quitar
#include "ft_printf.h"

static int	calc_len_uns(unsigned long long n)
{
	int	len;

	len = 0;
	/*if (n < 0)
	{
		n = -n;
		len++;
	}*/
	while (n > 9)
	{
		n /= 10;
		len++;
	}
	len++;
	return (len);
}


char	*ft_itoa_uns(unsigned long long n)
{
	char	*str_n;
	int		len;

	//if (n == -2147483648)
	//	return (ft_strdup("-2147483648"));
	len = calc_len_uns(n);
	str_n = (char *)malloc(sizeof(char) * (len + 1));
	if (str_n == NULL)
		return (NULL);
	/*if (n < 0)
	{
		str_n[0] = '-';
		n = -n;
	}*/
	str_n[len] = '\0';
	while (n > 9)
	{
		str_n[len - 1] = (n % 10) + '0';
		n = n / 10;
		len --;
	}
	str_n[--len] = n + '0';
	return (str_n);
}

char	*ft_itoa_hexa(unsigned long long n, char *base)
{
	char	*str_n;
	int		len;

	//if (n == -2147483648)
	//	return (ft_strdup("-2147483648"));
	len = calc_len_uns(n);
	str_n = (char *)malloc(sizeof(char) * (len + 1));
	if (str_n == NULL)
		return (NULL);
	/*if (n < 0)
	{
		str_n[0] = '-';
		n = -n;
	}*/
	str_n[len] = '\0';
	while (n > 15)
	{
		str_n[len - 1] = (base[n % 16]);
		n = n / 16;
		len --;
	}
	str_n[--len] = base[n];
	return (str_n);
}
