/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hex_pf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapupier <sapupier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:43:08 by sapupier          #+#    #+#             */
/*   Updated: 2024/11/25 16:04:57 by sapupier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// to print numbers in hexadecimal format
int	ft_putnbr_hex_pf(unsigned int n, int uppercase)
{
	int		i;
	char	*base;
	
	i = 0;
	//base = uppercase;
	if (uppercase)
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	if (n >= 16)
	{
		i += ft_putnbr_hex_pf(n / 16, uppercase);
	}
	i += ft_putchar_pf(base[n % 16]);
	return (i);
}
