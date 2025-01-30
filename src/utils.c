/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapupier <sapupier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 14:58:05 by sapupier          #+#    #+#             */
/*   Updated: 2025/01/30 09:09:59 by sapupier         ###   ########.fr       */
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

char	*find_path(char **path, char *argv)
{
	char	*folder;
	char	*cmd_path;
	int		i;
	
	i = 0;
	while (path[i])
	{
		folder = ft_strjoin(path[i], "/");
		cmd_path = ft_strjoin(folder, argv);
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

char	exec_cmd(char **env, char *argv)
{
	char	**path;
	char	*cmd_path;
	//char	**cmd_opt;
	char	*cmd_args[] = {argv, NULL};

   	path = ft_path(env);
	cmd_path = find_path(path, argv);
	//cmd_opt = ft_split(cmd_path, ' ');
	if (!path)
	{
		fprintf(stderr, "No PATH found\n");
        return -1;
	}
	if (cmd_path)
	{                                                                                                                                   
		if (execve(cmd_path, cmd_args, env) == -1)
		{
        	perror("Error execve");
        	free(cmd_path);
	      	exit(1);
		}
	}
    else
	{
		fprintf(stderr, "Command not found\n");
		return (-1);
	}
	return (0);
}

