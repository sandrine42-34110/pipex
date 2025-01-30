/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapupier <sapupier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 15:18:15 by sapupier          #+#    #+#             */
/*   Updated: 2025/01/30 08:21:43 by sapupier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// Creer un pipe
void ft_pipe(int pipe_fd[2])
{
	if (pipe(pipe_fd) == -1)
	{
		perror("pipe");
		exit (1);
	}
}
// Creer processus enft
pid_t	ft_process()	
{
	pid_t	pid;
	
	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		exit (1);
	}
}

// Process parent : ecrit ds le pipe
void	parent(int pipe_fd[2], const char *str)
{
	close(pipe_fd[0]);
	if (write(pipe_fd[1], str, strlen(str)) == -1)
	{
        perror("write");
        exit(1);
    }
	close(pipe_fd[1]);
}

// Process enft : lit ds le pipe
void	child(int pipe_fd[2])
{
    char	buffer[128];
	int		bytesRead;

	close(pipe_fd[1]);
	bytesRead = read(pipe_fd[0], buffer, sizeof(buffer) - 1);
	if (bytesRead == -1)
	{
		perror("read");
		exit(1);
	}
	buffer[bytesRead] = '\0';
	close(pipe_fd[0]);
}
