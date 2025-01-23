/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapupier <sapupier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 09:08:27 by sapupier          #+#    #+#             */
/*   Updated: 2025/01/22 16:50:10 by sapupier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Compare deux chaines s1 et s2
int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
/*
#include <unistd.h>
#include <stdio.h>
#include <string.h>
int	main(void)
{
	printf("%d\n", ft_strncmp("ABC", "AB", 3));
	printf("%d\n", strncmp("ABC", "AB", 3));
	printf("%d\n", ft_strncmp("ABC", "AB", 2));
        printf("%d\n", strncmp("ABC", "AB", 2));
	return (0);
}*/
