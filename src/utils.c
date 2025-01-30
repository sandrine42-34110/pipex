/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapupier <sapupier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 14:58:05 by sapupier          #+#    #+#             */
/*   Updated: 2025/01/30 12:02:05 by sapupier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**ft_path(char **env)
{
	int		i;
	char	**path;
	
	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
		{		
			path = ft_split((env[i] + 5), ':');
			return (path);
		}
		i++;
	}

	return (0);
}

char	*find_path(char **path, char *cmd)
{
	char	*folder;
	char	*cmd_path;	
	//char	**cmd;
	int		i;
	
	i = 0;
	//cmd = ft_split(argv[1], ' ');
	while (path[i])
	{
		folder = ft_strjoin(path[i], "/");
		cmd_path = ft_strjoin(folder, cmd);
		printf("%s\n", cmd_path);
		if (access(cmd_path, X_OK) == 0)
			return (cmd_path);
		// if (access(ft_strjoin(path[i], argv), X_OK) == 0)
		// 	return (ft_strjoin(path[i], argv));
		free(cmd_path);
		free(folder);
		i++;
	}
	return (0);
}

int	exec_cmd(char *path, char **argv)
{
	//char	**cmd_opt;

	//cmd_opt = ft_split(argv[2], ' ');
	
	execve(path, argv, NULL);
	
	//execve(path, argv, NULL);
	
	//if (execve(path, cmd_opt, NULL) == -1)
	// {
    //  	perror("Error execve");
    // 	free(path);
	//     exit(1);
	// }
	// else
	// {
	// 	free(path);
	// 	fprintf(stderr, "Command not found\n");
	// 	return (-1);
	// }
	return (0);
}

