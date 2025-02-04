/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapupier <sapupier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 15:18:15 by sapupier          #+#    #+#             */
/*   Updated: 2025/02/04 16:27:43 by sapupier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// Creer un pipe
// void ft_pipe(int pipe_fd[2])
// {
// 	if (pipe(pipe_fd) == -1)
// 	{
// 		perror("pipe");
// 		exit (1);
// 	}
// }

int	open_file(char *argv, int flags)
{
	(void)flags;
	int	fd;
	
	fd = open(argv, flags, 0644);
	if (fd == -1)
	{
		perror("Erreur lors de l'ouverture du fichier");
        return -1;
	}
	return (fd);
}

// Process parent : ecrit ds le pipe
// void	parent(int pipe_fd[2], const char *str)
// {
// 	close(pipe_fd[0]);
// 	if (write(pipe_fd[1], str, strlen(str)) == -1)
// 	{
//         perror("write");
//         exit(1);
//     }
// 	close(pipe_fd[1]);
// }

