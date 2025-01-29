/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapupier <sapupier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 14:58:05 by sapupier          #+#    #+#             */
/*   Updated: 2025/01/29 10:42:58 by sapupier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

//





char	**ft_path(char **env, char **argv)
{
	int		i;
	char	**paths;
	char	*folder;
	char	*path_to_cmd;
	int		k;

	i = 0;
	k = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
		{		
			paths = ft_split((env[i] + 5), ':');
			break;
		}
		i++;
	}
	// printf("Les dossiers dans PATH sont : \n");
	// int	j = 0;
	// while (paths[j] != NULL)
	// {
	// 	printf("Dossier %d : %s\n", j + 1, paths[j]);
    // 	j++;
	// }

	while (paths[k])
	{
		folder = ft_strjoin(paths[k], "/");
		path_to_cmd = ft_strjoin(folder, argv[1]);
		if (access(path_to_cmd, F_OK) == 0)
			printf("Trouve : %s \n", path_to_cmd);
		else
			printf("Pas trouve dans %s \n", path_to_cmd);


		
		free(path_to_cmd);
		free(folder);
		k++;
	}
	



	
	return (paths);
}
