/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akwadran <akwadran@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 23:36:19 by akwadran          #+#    #+#             */
/*   Updated: 2024/12/08 00:14:13 by akwadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"

/*

va_start()  initializes ap
va_arg()    ap can be passed to va_arg for each argument to be processed
va_copy()   
va_end      calling va_end signals that there are no further aguments and invalidates ap

each call to va_start must be matched to va_end in the same function

ap = arguments pointer

*/
int ft_printf(char const *str, ...)
{
    va_list ap;
    int     i;
    int     count;

    va_start(ap, str);
    i = 0;
    count = 0;
    while (str[i])
    {
        if (str[i] != '%')
            count = count + ft_putchar(str[i++]);
        else 
        {
            count = count + get_format(str[i + 1], ap);
            i+=2;
        }
    }
    va_end(ap);
    return (count);
}

int get_format(char format, va_list ap)
{
    int count;

    count = 0;
    if (format == 'c')
        count = ft_putchar(va_arg(ap, int));
    else if (format == 's')
        count = ft_putstr(va_arg(ap, char *));
    else if (format == 'p')
    {}
    else if (format == 'd' || format == 'i')
        count = ft_putnbr(va_arg(ap, int));
    else if (format == 'u')
    {}
    else if (format == 'x')
    {}
    else if (format == 'X')
    {}
    else if (format == '%')
        count = ft_putchar('%');
    return (count);
}