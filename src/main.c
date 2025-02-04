/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapupier <sapupier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 15:18:15 by sapupier          #+#    #+#             */
/*   Updated: 2025/02/04 17:24:38 by sapupier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
//#include "ft_printf.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
#include <string.h>
# include <sys/wait.h>


void	child(char **argv, char **env, int *fd)
{
	int		infile;
	char	**path;
	char	*cmd_path;
	char	**cmd_args;
	
	infile = open(argv[1], O_RDONLY);
	if (infile == -1)
		error("Error opening input file");
	if (dup2(infile, STDIN_FILENO) == -1)
		error("Error duplicating pipe descriptor");
	if (dup2(fd[1], STDOUT_FILENO) == -1)
		error("Error duplicating pipe descriptor");
	close(infile);
	close(fd[0]);
	close(fd[1]);
	path = ft_path(env);
	cmd_args = ft_split(argv[2], ' ');
	cmd_path = find_path(path, cmd_args[0]);
	
//	fprintf(stderr, "Debug: Entering child process\n");

	
	if (!cmd_path)
		error("Command not found");
	
	exec_cmd(cmd_path, cmd_args);
}

void parent(char **argv, char **env, int *fd)
{
	int outfile;
	char **path;
	char *cmd_path;
	char **cmd_args;
	
	outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (outfile == -1)
		error("Error opening input file");
	if (dup2(fd[0], STDIN_FILENO) == -1)
		error("Error duplicating pipe descriptor");
	if (dup2(outfile, STDOUT_FILENO) == -1)
		error("Error duplicating pipe descriptor");
	close(outfile);
	close(fd[0]);
	close(fd[1]);
	path = ft_path(env);
	cmd_args = ft_split(argv[3], ' ');
	cmd_path = find_path(path, cmd_args[0]);
	if (!cmd_path)
		error("Command not found");
	exec_cmd(cmd_path, cmd_args);
}

int main(int argc, char **argv, char **env)
{
	int		fd[2];
	pid_t	pid;

	if (argc != 5)
		error("Usage: ./pipex infile cmd1 cmd2 outfile");
	if (pipe(fd) == -1)
		error("Error creating pipe");  
	pid = fork();
	if (pid == -1)
		error("Error creating pipe");
	else if (pid == 0)
	{
		child(argv, env, fd);
	}
	else
	{
		pid = fork();
		if (pid == -1)
			error("Error forking process");
		else if (pid == 0)
			parent(argv, env, fd);
		else 
		{
			close(fd[0]);
			close(fd[1]);
			waitpid(-1, NULL, 0);
			waitpid(-1, NULL, 0);
		}
	}
	return (0);
}
