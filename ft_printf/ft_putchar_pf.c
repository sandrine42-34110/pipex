/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_pf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapupier <sapupier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 14:51:41 by sapupier          #+#    #+#             */
/*   Updated: 2024/11/21 10:39:56 by sapupier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar_pf(char c)
{
	int	i;

	i = write(1, &c, 1);
	return (i);
}
/*
int main (void)
{
	int result;

    result = ft_putchar_pf('c');
    printf("\nNombre de caractères imprimés : %d\n", result);
    return (0);
}*/