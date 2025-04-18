/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapupier <sapupier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 14:58:05 by sapupier          #+#    #+#             */
/*   Updated: 2025/02/05 11:09:33 by sapupier         ###   ########.fr       */
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
		perror("Error opening file");
		return (-1);
	}
	return (fd);
}

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
	int		i;

	if (access(cmd, X_OK) == 0)
		return (ft_strdup(cmd));
	i = 0;
	while (path[i])
	{
		folder = ft_strjoin(path[i], "/");
		if (!folder)
			return (NULL);
		cmd_path = ft_strjoin(folder, cmd);
		free(folder);
		if (!cmd_path)
			return (NULL);
		if (access(cmd_path, X_OK) == 0)
			return (cmd_path);
		free(cmd_path);
		i++;
	}
	return (0);
}

int	exec_cmd(char *path, char **argv)
{
	if (execve(path, argv, NULL) == -1)
	{
		perror("Error execve");
		free(path);
		exit(1);
	}
	return (0);
}

void	error(const char *message)
{
	perror(message);
	exit (1);
}
