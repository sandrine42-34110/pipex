/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapupier <sapupier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 14:58:05 by sapupier          #+#    #+#             */
/*   Updated: 2025/01/29 11:36:48 by sapupier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**ft_path(char **env)
{
	int		i;
	char	**paths;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
		{		
			paths = ft_split((env[i] + 5), ':');
			break;
		}
		i++;
	}
	return (paths);
}

char	**find_path(char **path, char *argv)
{
	char	*folder;
	char	*path_to_cmd;
	int		k;
	k = 0;

	while (path[k])
	{
		folder = ft_strjoin(path[k], "/");
		path_to_cmd = ft_strjoin(folder, argv);
		if (access(path_to_cmd, F_OK) == 0)
			printf("Trouve : %s \n", path_to_cmd);
		else
			printf("Pas trouve dans %s \n", path_to_cmd);
		free(path_to_cmd);
		free(folder);
		k++;
	}
	return (path);
}
