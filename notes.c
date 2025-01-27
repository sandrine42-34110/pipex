/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   notes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapupier <sapupier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 14:58:05 by sapupier          #+#    #+#             */
/*   Updated: 2025/01/27 15:53:09 by sapupier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

//Creer un pipe. pipefd[0] : le côté lecture du pipe, pipefd[1] : le côté écriture du pipe.
int	pipefd[2];
if (pipe(pipefd) == -1)
{
	perror("pipe");
	exit(EXIT_FAILURE);
}

//Forker un processus
pid_t	pid = fork();
if (pid == -1)
{
	perror("fork");
	exit(EXIT_FAILURE);
}

//Fermer les descripteurs de pipe inutiles
close(pipefd[0]);  // Ne va pas lire
close(pipefd[1]);  // Ne va pas écrire

//Executer les cdes avc exec() ds l'enft
write(pipefd[1], "message", 7);  // écrire dans le pipe
execlp("ls", "ls", "-l", NULL);  // Exemple de commande à exécuter

//Lire du pipe dans le parent
char buffer[128];
ssize_t bytesRead = read(pipefd[0], buffer, sizeof(buffer));
if (bytesRead > 0)
{
	write(STDOUT_FILENO, buffer, bytesRead);  // Afficher ce qu'on a lu du pipe
}

//Attendre la fin des processus
int status;
waitpid(pid, &status, 0);  // Attendre la fin de l'enfant

//Exemple de programme complet avec un pipe
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
	int pipefd[2];
	pid_t pid;

	if (pipe(pipefd) == -1)
	{
		perror("pipe");
		exit(EXIT_FAILURE);
	}

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}

	if (pid == 0)
	{  // Code pour l'enfant
		close(pipefd[0]);  // Ne va pas lire

	// Écrire dans le pipe
		const char *msg = "Hello from child!\n";
		write(pipefd[1], msg, 17);
		close(pipefd[1]);  // Fermer après l'écriture

		exit(EXIT_SUCCESS);
	}
	else
	{  // Code pour le parent
		close(pipefd[1]);  // Ne va pas écrire

		// Lire depuis le pipe
		char buffer[128];
		ssize_t bytesRead = read(pipefd[0], buffer, sizeof(buffer));
		if (bytesRead > 0)
		{
			write(STDOUT_FILENO, buffer, bytesRead);  // Afficher ce qu'on a lu du pipe
		}

		close(pipefd[0]);  // Fermer après la lecture
		waitpid(pid, NULL, 0);  // Attendre que l'enfant termine
	}

	return (0);
}

// void pipex(int f1, int f2, char *cmd1, char *cmd2) 
// { 
// 	int end[2]; 
// 	int status; 
// 	pid_t child1; 
// 	pid_t child2;
// 	pipe(end); 
// 	child1 = fork(); 
// 	if (child1 < 0) 
// 		 return (perror("Fork: ")); 
// 	if (child1 == 0) 
// 		child_one(f1, cmd1); 
// 	child2 = fork(); 
// 	if (child2 < 0) 
// 		 return (perror("Fork: ")); 
// 	if (child2 == 0) 
// 		child_two(f2, cmd2); 
// 	close(end[0]); // ceci est le parent 
// 	close(end[1]); // ne fait rien 
// 	waitpid(child1, &status, 0); // supervise les enfants 
// 	waitpid(child2, &status, 0); // pendant qu'ils terminent leurs tâches 
// }


int main ()//int argc, char *argv[])
{
	int	fd[2];
	int	pid1;
	int pid2;
	
	pid1 = fork();
	pid2 = fork();
	if (pipe(fd) == -1)
		return (1);
	if (pid1 < 0)
		return (2);
	if (pid1 == 0) // child process 1 (ping)
	{
		dup2(fd[1], STDOUT_FILENO);
		close(fd[0]);
		close(fd[1]);
		execlp("ping", "ping", "-c", "5, google.com", NULL);
	}
	if (pid2 < 0)
		return (3);
	if (pid2 == 0) // child process 2 (grep)
	{
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
		close(fd[1]);
		execlp("grep", "grep", "rtt", NULL);
	}
	close(fd[0]);
	close(fd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	return (0);
}




