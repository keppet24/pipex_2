/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oettaqi <oettaqi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 20:36:54 by othmaneetta       #+#    #+#             */
/*   Updated: 2025/02/11 17:29:16 by oettaqi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	check_files(t_pipex *doc, char *input, char *output)
{
	doc->infile_fd = open(input, O_RDONLY);
	if (doc->infile_fd == -1)
		perror(input);
	doc->outfile_fd = open(output, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (doc->outfile_fd == -1)
		perror(output);
}

void	direction_1(int *fd, t_pipex *doc)
{
	close(doc->outfile_fd);
	close(fd[0]);
	if (doc->infile_fd == -1)
	{
		close(fd[1]);
		exit(EXIT_FAILURE);
	}
	dup2(doc->infile_fd, STDIN_FILENO);
	close(doc->infile_fd);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[1]);
}

void	direction_2(int *fd, t_pipex *doc)
{
	close(doc->infile_fd);
	close(fd[1]);
	dup2(fd[0], STDIN_FILENO);
	close(fd[0]);
	if (doc->outfile_fd == -1)
	{
		//close(doc->infile_fd);
		exit(EXIT_FAILURE);
	}
	dup2(doc->outfile_fd, STDOUT_FILENO);
	close(doc->outfile_fd);
}

static int	finalize_processes(t_pipex *doc, int fd[2], int id, int id2)
{
	int	wstatus;

	close(fd[0]);
	close(fd[1]);
	waitpid(id, NULL, 0);
	waitpid(id2, &wstatus, 0);
	if (doc->outfile_fd != -1)
		close(doc->outfile_fd);
	if (doc->infile_fd != -1)
		close(doc->infile_fd);
	return (WEXITSTATUS(wstatus));
}

int	main(int ac, char **av, char **env)
{
	t_pipex	doc;
	int		fd[2];
	int		id;
	int		id2;

	if (ac != 5)
		return (write(2, "Error\n", 6), 1);
	pipe(fd);
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
	return (finalize_processes(&doc, fd, id, id2));
}
