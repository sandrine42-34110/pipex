/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapupier <sapupier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 15:18:15 by sapupier          #+#    #+#             */
/*   Updated: 2025/02/05 10:03:43 by sapupier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	open_file(char *argv, int flags)
{
	int		fd;

	(void) flags;
	fd = open(argv, flags, 0644);
	if (fd == -1)
	{
		perror("Erreur lors de l'ouverture du fichier");
		return (-1);
	}
	return (fd);
}
