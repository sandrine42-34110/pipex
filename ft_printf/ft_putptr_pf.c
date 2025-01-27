/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapupier <sapupier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 14:51:41 by sapupier          #+#    #+#             */
/*   Updated: 2024/11/25 09:28:50 by sapupier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// Affiche l adresse d un pointeur en format hexadecimal, precedee de 0x.
// Gere le cas ou l adresse est NULL en affichant 0x0.
int	ft_putptr_pf(void *ptr)
{
	unsigned long		p;
	char				*str;
	char				buffer[16];
	int					i;
	
	i = 0;
	p = (unsigned long)ptr;
	str = "0123456789abcdef";
	ft_putstr_pf("0x");
	i += 2;

	if (p == 0) 
	{
		ft_putchar_pf('0');
		return (i + 1);
	}

	while (p > 0)
	{
		buffer[i++] = str[p % 16];
		p /= 16;
	}

	while (--i >= 0)
	{
		ft_putchar_pf(buffer[i]);
	}
	return (i);
}