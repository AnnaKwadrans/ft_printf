/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akwadran <akwadran@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 23:03:01 by akwadran          #+#    #+#             */
/*   Updated: 2024/12/08 00:19:12 by akwadran         ###   ########.fr       */
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

    ctrl = ft_printf("Hej jestem %s%c i mam %d%% tyle.\n", name, ch, num);
    printf("%d\n", ctrl);
    return (0);
}