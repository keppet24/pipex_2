/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oettaqi <oettaqi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 20:36:54 by othmaneetta       #+#    #+#             */
/*   Updated: 2025/01/29 16:17:12 by oettaqi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	direction_1(int *fd, pipex *doc, char **av)
{
		//close(fd[0]);
		if ((access(av[1], R_OK) == -1) || (access(av[1], F_OK) == -1))
		{
			write(2, "Infile cannot be found\n", 25);
			dup2(fd[0], STDIN_FILENO);
			close(fd[0]);
		}
		else
		{
			close(fd[0]);
			(*doc).infile_fd = open(av[1],  O_RDONLY);
			dup2((*doc).infile_fd, STDIN_FILENO);
			close((*doc).infile_fd);
		}
		dup2(fd[1], STDOUT_FILENO);
		close(fd[1]);	
}


void	direction_2(int *fd, pipex *doc,int ac, char **av)
{
	close(fd[1]);
	dup2(fd[0], STDIN_FILENO);
	close(fd[0]);
	(*doc).outfile_fd = open(av[ac - 1], O_CREAT | O_WRONLY,  0644);
	dup2((*doc).outfile_fd, STDOUT_FILENO);
	close((*doc).outfile_fd);
}

int main(int ac, char **av, char **env)
{
	pipex	doc;
	int	fd[2];
	int	id;
	int	id2;

	pipe(fd);
	if (ac != 5)
		return (write(2, "Error\n", 6), 0);
	id = fork();
	if (id == 0)
	{
		direction_1(fd, &doc,  av); 
		execute_program_1(ac, av, &doc, env);
	}
	id2 = fork();
	if (id2 == 0)
	{
		direction_2(fd, &doc, ac, av); 
		execute_program_2(ac, av, &doc);
	}
	close(fd[0]);
	close(fd[1]);
	waitpid(id, NULL, 0);
	waitpid(id2, NULL, 0);
	return (0);
}
