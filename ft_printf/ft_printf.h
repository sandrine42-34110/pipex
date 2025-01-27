/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapupier <sapupier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 15:38:27 by sapupier          #+#    #+#             */
/*   Updated: 2024/11/25 15:33:04 by sapupier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

int		ft_printf(const char *format, ...);
int		ft_putchar_pf(char c);
int		ft_putnbr_hex_pf(unsigned int n, int uppercase);
int		ft_putnbr_pf(int n);
int		ft_putnbr_u_pf(unsigned int n);
int		ft_putptr_pf(void *ptr);
int		ft_putstr_pf(char *str);
#endif