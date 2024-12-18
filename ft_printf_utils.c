/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akwadran <akwadran@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 15:45:01 by akwadran          #+#    #+#             */
/*   Updated: 2024/12/14 15:58:30 by akwadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h> //quitar
#include "ft_printf.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	unsigned int	i;

	if (size == 0)
		return (ft_strlen(src));
	i = 0;
	while (src[i] && i < (size - 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}

char	*ft_strdup(const char *s)
{
	int		len;
	char	*ptr;

	len = ft_strlen(s) + 1;
	ptr = malloc(sizeof(char) * len);
	if (ptr == NULL)
		return (ptr);
	ft_strlcpy(ptr, s, sizeof(char) * len);
	return (ptr);
}

static int	calc_len(int n)
{
	int	len;

	len = 0;
	if (n < 0)
	{
		n = -n;
		len++;
	}
	while (n > 9)
	{
		n /= 10;
		len++;
	}
	len++;
	return (len);
}


char	*ft_itoa(int n)
{
	char	*str_n;
	int		len;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = calc_len(n);
	str_n = (char *)malloc(sizeof(char) * (len + 1));
	if (str_n == NULL)
		return (NULL);
	if (n < 0)
	{
		str_n[0] = '-';
		n = -n;
	}
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
