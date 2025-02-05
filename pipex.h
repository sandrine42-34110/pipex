/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapupier <sapupier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 14:55:11 by sapupier          #+#    #+#             */
/*   Updated: 2025/02/05 08:30:43 by sapupier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <errno.h>
# include <fcntl.h>
# include "libft.h"

int		main(int argc, char **argv, char **env);
char	**ft_path(char **env);
char	*find_path(char **path, char *cmd);
int		exec_cmd(char *path, char **argv);
int		open_file(char *argv, int flags);
void	error(const char *message);
#endif