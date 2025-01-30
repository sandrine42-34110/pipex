/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapupier <sapupier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 14:55:11 by sapupier          #+#    #+#             */
/*   Updated: 2025/01/30 13:54:14 by sapupier         ###   ########.fr       */
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

int		dup2(int oldfd, int newfd);
int		pipe(int pipefd[2]);
pid_t	fork(void);
pid_t	waitpid(pid_t pid, int *status, int options);
pid_t	wait(int *status);
//int		execve(char *path, char *argv, char *env);
int		main(int argc, char **argv, char **env);
//int		ft_printf(const char *format, ...);
char	**ft_path(char **env);
char	*find_path(char **path, char *cmd);
int		exec_cmd(char *path, char **argv);
int		open_file(char **argv, int flags);
#endif