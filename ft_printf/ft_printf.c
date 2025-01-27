/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapupier <sapupier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 09:22:06 by sapupier          #+#    #+#             */
/*   Updated: 2024/11/25 16:00:13 by sapupier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
// # include <stdio.h>
// # include <unistd.h>
// # include <stdarg.h>

// int	ft_putchar_pf(char c)
// {
// 	int	i;

// 	i = write(1, &c, 1);
// 	return (i);
// }

// int	ft_putnbr_pf(int n)
// {
// 	int	i;
	
// 	i = 0;
// 	if (n == -2147483648)
// 	{
// 		i = write(1, "-2147483648", 11);
// 		return (i);
// 	}
// 	if (n < 0)
// 	{
// 		i += write(1, "-", 1);
// 		n = -n;
// 	}
// 	if (n > 9)
// 	{
// 		i += ft_putnbr_pf((n / 10));
// 	}
// 	i += ft_putchar_pf(((n % 10) + '0'));
// 	return (i);
// }

// static	int	ft_putstr_pf(char *str)
// {
// 	int	i;

// 	i = 0;
// 	while(str[i])
// 	{
// 		write(1, &str[i], 1);
// 		i++;
// 	}
// 	return (i);
// }

static int	convert(va_list args, char format)
{
	int	i;
	
	i = 0;
	if (format == 'c')
		i += ft_putchar_pf(va_arg(args, int));
	else if ((format == 's'))
		i += ft_putstr_pf(va_arg(args, char *));
	else if ((format == 'd'))
		i += ft_putnbr_pf(va_arg(args, int));
	else if ((format == '%'))
		i += write(1, "%", 1);
	else if ((format == 'p'))
		i += ft_putptr_pf(va_arg(args, void *));
	else if ((format == 'i'))
		i += ft_putnbr_pf(va_arg(args, int));
	else if ((format == 'u'))
		i += ft_putnbr_u_pf(va_arg(args, unsigned int));
	else if ((format == 'x'))
	i += ft_putnbr_hex_pf(va_arg(args, unsigned int), 0);
	else if ((format == 'x'))
	i += ft_putnbr_hex_pf(va_arg(args, unsigned int), 1);
	return (i);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;

	i = 0;
	va_start(args, format);
	{
		while (*format)
		{
			if(*format == '%' && *(format + 1))
			{
				format ++;
				i += convert(args, *format);
			}
			else
			{
				ft_putchar_pf(*format);
				i++;
			}
		format++;
		}	
    }
	va_end(args);
	return (i);
}
int	main()
{
	int	i = 0;
	// char c = 'A';
    // i = printf("Le caractère est : %c\n", c);
   	// printf("\nNombre de caractères imprimés : %d\n", i);
	// i = ft_printf("Le caractère est : %c\n", c);
	// printf("\nNombre de caractères imprimés : %d\n", i);
	// char *c = "BONJOUR";
    // i = printf("La chaine de caractères est : %s\n", c);
   	// printf("\nNombre de caractères imprimés : %d\n", i);
	// i = ft_printf("La chaine de caractères est : %s\n", c);
	// printf("\nNombre de caractères imprimés : %d\n", i);	
	// int c = 123;
    // i = printf("Le nombre est : %d\n", c);
   	// printf("\nNombre de caractères imprimés : %d\n", i);
	// i = ft_printf("Le nombre est : %d\n", c);
	// printf("\nNombre de caractères imprimés : %d\n", i);
	// char c = '%';
    // i = printf("Le caractere est : %c\n", c);
   	// printf("\nNombre de caractères imprimés : %d\n", i);
	// i = ft_printf("Le caractere est : %c\n", c);
	// printf("\nNombre de caractères imprimés : %d\n", i);
	// char *c = "BONJOUR";
    // i = printf("L adresse de ce pointeur est : %p\n", c);
   	// printf("\nNombre de caractères imprimés : %d\n", i);
	// i = ft_printf("L adresse de ce pointeur est : %p\n", c);
	// printf("\nNombre de caractères imprimés : %d\n", i);
	// int c = -2147483648;
	// i = printf("Le nombre est : %i\n", c);
	// printf("\nNombre de caractères imprimés : %d\n", i);
	// i = ft_printf("Le nombre est : %i\n", c);
	// printf("\nNombre de caractères imprimés : %d\n", i);
	// int c = -2147483648;
	// i = printf("Le nombre est : %u\n", c);
	// printf("\nNombre de caractères imprimés : %d\n", i);
	// i = ft_printf("Le nombre est : %u\n", c);
	// printf("\nNombre de caractères imprimés : %d\n", i);
	// int c = -2147483648;
	// i = printf("Le nombre est : %x\n", c);
	// printf("\nNombre de caractères imprimés : %d\n", i);
	// i = ft_printf("Le nombre est : %x\n", c);
	// printf("\nNombre de caractères imprimés : %d\n", i);
	int c = 648;
	i = printf("Le nombre est : %X\n", c);
	printf("\nNombre de caractères imprimés : %d\n", i);
	i = ft_printf("Le nombre est : %X\n", c);
	printf("\nNombre de caractères imprimés : %d\n", i);
	return (0);
}
