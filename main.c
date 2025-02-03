/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oettaqi <oettaqi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 20:36:54 by othmaneetta       #+#    #+#             */
/*   Updated: 2025/02/03 18:25:07 by oettaqi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	check_files(pipex *doc, char *input, char *output)
{
	(*doc).infile_fd = open(input,  O_RDONLY);
	if ((*doc).infile_fd == -1)
		perror(input);
	(*doc).outfile_fd = open(output, O_CREAT | O_WRONLY | O_TRUNC,  0644);
	if ((*doc).outfile_fd == -1)
		perror(output);
}	

void	direction_1(int *fd, pipex *doc)
{
		close(fd[0]);
		//close(fd[0]);
		if ((*doc).infile_fd == -1)
		{
			close(fd[1]);
			exit(EXIT_FAILURE) ;
			// dup2(fd[0], STDIN_FILENO);
		}
		else
		{
			//(*doc).infile_fd = open(av[1],  O_RDONLY);
			dup2((*doc).infile_fd, STDIN_FILENO);
			close((*doc).infile_fd);
		}
		dup2(fd[1], STDOUT_FILENO);
		close(fd[1]);
}

void	direction_2(int *fd, pipex *doc)
{
	close(fd[1]);
	dup2(fd[0], STDIN_FILENO);
	close(fd[0]);
	//(*doc).outfile_fd = open(av[ac - 1], O_CREAT | O_WRONLY,  0644);
	dup2((*doc).outfile_fd, STDOUT_FILENO);
	if ((*doc).outfile_fd != -1)
		close((*doc).outfile_fd);
}

int main(int ac, char **av, char **env)
{
	pipex	doc;
	int	fd[2];
	int	id;
	int	id2;
	int wstatus;

	pipe(fd);
	if (ac != 5)
		return (write(2, "Error\n", 6), 0);
	check_files(&doc, av[1], av[ac - 1]);
	id = fork();
	if (id == 0)
	{
		direction_1(fd, &doc); 
		execute_program_1(ac, av, &doc, env);
	}
	id2 = fork();
	if (id2 == 0)
	{
		direction_2(fd, &doc);
		execute_program_2(ac, av, &doc, env);
	}
	close(fd[0]);
	close(fd[1]);
	waitpid(id, NULL, 0);
	waitpid(id2, &wstatus, 0);
	if ((doc).outfile_fd != -1)
		close((doc).outfile_fd);
	if ((doc).infile_fd != -1)
		close((doc).infile_fd);
	return (WEXITSTATUS(wstatus));
}
