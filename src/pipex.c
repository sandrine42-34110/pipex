/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapupier <sapupier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 15:18:15 by sapupier          #+#    #+#             */
/*   Updated: 2025/02/04 14:47:37 by sapupier         ###   ########.fr       */
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

// Process enft : lit ds le pipe
void create_child_process(char **argv, char **env, int infile, int *pipefd)
{
    pid_t pid = fork();  // Crée un processus enfant

    if (pid == -1) {
        perror("fork failed");  // Si fork échoue
        exit(1);
    }

    if (pid == 0)
	{
		if (infile != -1)
			dup2(infile, 0); // Rediriger stdin vers infile
		if (pipefd != NULL)
			dup2(pipefd[1], 1); // Rediriger stdout vers le pipe
        close(pipefd[0]);
        close(pipefd[1]);
        close(infile);
        		
        if (execve(argv[0], argv, env) == -1)
		{
            perror("execve failed");
            exit(1);
        }
    }
    // Si nous sommes dans le processus parent, on peut faire d'autres actions
    else {
        // Vous pouvez attendre le processus enfant ou faire d'autres actions ici
        printf("Parent process: Child PID is %d\n", pid);
    }
}
