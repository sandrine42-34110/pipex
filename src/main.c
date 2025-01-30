/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapupier <sapupier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 15:18:15 by sapupier          #+#    #+#             */
/*   Updated: 2025/01/30 09:08:38 by sapupier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
//#include "ft_printf.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
#include <string.h>
# include <sys/wait.h>

// int	pipe(int pipefd[2])
// {
	
// }

// void 
// {

	
// }


char	**cmd_opt(const char *cmd_path)
{
	char	**cmd_opt;

	cmd_opt = ft_split(cmd_path, ' ');
	if (!cmd_opt)
	{
        perror("ft_split failed");
        return NULL;
    }
    return cmd_opt;
}









int main(int argc, char **argv, char **env)
{
	(void)argv;
	(void)argc;
	char	**path;
	char	*path1;
	char	*path2;
	
	//const char	*cmd1;
	// int		i;
	if (argc != 5)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	// i = 0;
	path = ft_path(env);
	path1 = find_path(path, argv[2]);
	path2 = find_path(path, argv[3]);
	printf("%s\n%s\n", path1, path2);
	if (path1 && path2)
    {
		if (exec_cmd(env, argv[1]) == -1)
        {
            perror("Error execve for command 1");
            return 1;
        }
    }
    else
    {
        fprintf(stderr, "Command not found: %s or %s\n", argv[1], argv[2]);
        return 1;
    }
	
	return (0);
}





































// int main (int argc, char **argv)
// {
// 	int	fd[2];
// 	int	pid1;
// 	int pid2;
	
// 	pid1 = fork();
// 	pid2 = fork();
// 	if (pipe(fd) == -1)
// 		return (1);
// 	if (pid1 < 0)
// 		return (2);
// 	if (pid1 == 0) // child process 1 (ping)
// 	{
// 		dup2(fd[1], STDOUT_FILENO);
// 		close(fd[0]);
// 		close(fd[1]);
// 		execlp("ping", "ping", "-c", "5, google.com", NULL);
// 	}
// 	if (pid2 < 0)
// 		return (3);
// 	if (pid2 == 0) // child process 2 (grep)
// 	{
// 		dup2(fd[0], STDIN_FILENO);
// 		close(fd[0]);
// 		close(fd[1]);
// 		execlp("grep", "grep", "rtt", NULL);
// 	}
// 	close(fd[0]);
// 	close(fd[1]);
// 	waitpid(pid1, NULL, 0);
// 	waitpid(pid2, NULL, 0);
// 	return (0);
// }

