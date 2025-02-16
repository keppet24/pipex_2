/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oettaqi <oettaqi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 18:05:30 by oettaqi           #+#    #+#             */
/*   Updated: 2025/02/16 19:57:31 by oettaqi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	check_empty_command_2(char **av)
{
	if (av[3][0] == '\0')
	{
		errno = EACCES;
		perror("Erreur");
		exit(EXIT_FAILURE);
	}
}

void	handle_exec_2_error(t_pipex *doc, char **tab)
{
	write(2, "command not found: ", 19);
	write(2, (*doc).path_for_excve, ft_strlen((*doc).path_for_excve));
	write(2, "\n", 1);
	free_all(tab);
	free((*doc).arg_for_excve);
	exit(127);
}

	//free((*doc).path_for_excve);
void	handle_exec_2_error_2(t_pipex *doc, char **tab)
{
	write(2, "command not found: ", 19);
	write(2, (*doc).path_for_excve, ft_strlen((*doc).path_for_excve));
	write(2, "\n", 1);
	free_all(tab);
	free((*doc).arg_for_excve);
	free((*doc).path_for_excve);
	exit(127);
}

void	execute_program_2(int ac, char **av, t_pipex *doc, char **env)
{
	char	**tab;
	char	*envi[1];

	(void)ac;
	envi[0] = NULL;
	check_empty_command_2(av);
	tab = ft_split(av[3], ' ');
	if (!tab)
		return ;
	tab_of_arg(tab, doc);
	if (path_for_excve(tab, doc, env) == 1)
	{
		if (execve((*doc).path_for_excve, (*doc).arg_for_excve, envi) == -1)
			handle_exec_2_error(doc, tab);
	}
	else
	{
		if (execve((*doc).path_for_excve, (*doc).arg_for_excve, envi) == -1)
			handle_exec_2_error_2(doc, tab);
	}
}

//path_for_excve(tab, doc, env);