/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akwadran <akwadran@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 23:03:01 by akwadran          #+#    #+#             */
/*   Updated: 2024/12/08 09:20:45 by akwadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int main (void)
{
    char    ch = 'K';
    char    name[] = "Ania";
    int     num = 123456789;
    int     ctrl;
    unsigned int    uint_max = 4294967295;
    void    *ptr = NULL;


    printf("/* STR, CHAR, INT, %% */\n");
    ctrl = ft_printf("Hej jestem %s%c i mam %d%% tyle.\n", name, ch, num);
    printf("%d\n", ctrl);

    printf("/* UNSIGED INT */\n");
    ctrl = ft_printf("%u\n", uint_max);
    printf("%d\n", ctrl);
    ctrl = printf("%u\n", uint_max);
    printf("%d\n", ctrl);
    
    printf("/* HEXADECIMAL */\n");
    ctrl = printf("p: %x %X\n", 29, 29);
    printf("%d\n", ctrl);
    ctrl = ft_printf("f: %x %X\n", 29, 29);
    printf("%d\n", ctrl);
    ctrl = printf("p: %x %X\n", 5674, 905431);
    printf("%d\n", ctrl);
    ctrl = ft_printf("f: %x %X\n", 5674, 905431);
    printf("%d\n", ctrl);
    
    printf("/* POINTER */\n");
    ptr = &name;
    ctrl = printf("pointer: %p\n\n", ptr);
    ctrl = ft_printf("ft_pointer: %p\n\n", ptr);
    return (0);
}