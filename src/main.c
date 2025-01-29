/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapupier <sapupier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 15:18:15 by sapupier          #+#    #+#             */
/*   Updated: 2025/01/29 10:38:29 by sapupier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
//#include "ft_printf.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
#include <string.h>
# include <sys/wait.h>


int main(int argc, char **argv, char **env)
{
	(void)argv;
	(void)argc;
	//char	*path;
	// int		i;
	
	// i = 0;
	// path = ft_path(env);

	// printf(ft_strjoin(argv[i], path[i]));
	// while (path[i])
	// {
	// 	if (access(ft_strjoin(argv[1], path[i]), F_OK) == 0)
	// 		printf("Permission granted\n");
	// 	else
    // 	    printf("Permission denied\n");
	// 	i++;
	// }
	

	ft_path(env, argv);
	return (0);
}














/*

int	main(int argc, char **argv, char **env)
{
	
}
*/












































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

