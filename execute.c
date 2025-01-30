/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oettaqi <oettaqi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 12:17:05 by othmaneetta       #+#    #+#             */
/*   Updated: 2025/01/29 16:29:56 by oettaqi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_all(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	execute_program_1(int ac, char **av, pipex *doc, char **env)
{

	(void)ac;
	char  **tab;


	tab = ft_split(av[2],' ');
	tab_of_arg(tab, doc);
	path_for_excve(tab , doc);
	char *env[] = {NULL};
	if  (execve((*doc).path_for_excve, (*doc).arg_for_excve, env) == -1)
		perror("lol");
}

void	execute_program_2(int ac, char **av, pipex *doc, char **env)
{
	(void)ac;
	char  **tab;

	//char *path = "/usr/bin/cut";
	//char *arg[] = {"cut", "-d", " ", "-f1",NULL};
	tab = ft_split(av[3],' ');
	tab_of_arg(tab, doc);
	path_for_excve(tab , doc);
	char *env[] = {NULL};
	if  (execve((*doc).path_for_excve, (*doc).arg_for_excve, env) == -1)
		perror("lol");
}
