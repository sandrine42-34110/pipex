/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converters.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapupier <sapupier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 14:48:33 by sapupier          #+#    #+#             */
/*   Updated: 2024/11/21 14:49:44 by sapupier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// convertisseur pour les entiers
void convert_int(int i)
{
	printf("%d", i);
}

// Convertisseur pour les chaînes de caractères
void convert_string(const char *str) {
    printf("%s", str);
}

// Convertisseur pour les nombres flottants
void convert_double(double d) {
    printf("%f", d);
}
