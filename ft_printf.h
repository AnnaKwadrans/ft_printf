/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akwadran <akwadran@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 19:21:58 by akwadran          #+#    #+#             */
/*   Updated: 2024/12/08 00:20:56 by akwadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H
# include <stdarg.h>

int ft_printf(char const *str, ...);
int get_format(char format, va_list ap);

int ft_putchar(char c);
int ft_putstr(char *s);
int ft_putnbr(int n);


#endif