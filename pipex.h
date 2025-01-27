/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapupier <sapupier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 14:55:11 by sapupier          #+#    #+#             */
/*   Updated: 2025/01/27 15:10:42 by sapupier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
#include <string.h>
# include <sys/wait.h>
# include "libft.h"


int access(const char *pathname, int mode);
int dup2(int oldfd, int newfd);
int pipe(int pipefd[2]);
pid_t fork(void);
pid_t waitpid(pid_t pid, int *status, int options);
pid_t wait(int *status);
int execve(const char *filename, char *const argv[], char *const envp[]);


#endif