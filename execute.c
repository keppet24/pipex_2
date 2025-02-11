/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taqi <taqi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 12:17:05 by othmaneetta       #+#    #+#             */
/*   Updated: 2025/02/11 12:57:00 by taqi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_all(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	execute_program_1(int ac, char **av, t_pipex *doc, char **env)
{
	char	**tab;
	char	*envi[1];

	(void)ac;
	envi[0] = NULL;
	tab = ft_split(av[2], ' ');
	tab_of_arg(tab, doc);
	path_for_excve(tab, doc, env);
	if (execve((*doc).path_for_excve, (*doc).arg_for_excve, envi) == -1)
	{
		write(2, "command not found: ", 19);
		write(2, (*doc).path_for_excve, ft_strlen((*doc).path_for_excve));
		write(2, "\n", 1);
		free_all(tab);
		free((*doc).arg_for_excve);
		exit(127);
	}
}

		//if (path_for_excve(tab, doc, env))
		//free((*doc).path_for_excve);
void	execute_program_2(int ac, char **av, t_pipex *doc, char **env)
{
	char	**tab;
	char	*envi[1];

	(void)ac;
	envi[0] = NULL;
	tab = ft_split(av[3], ' ');
	tab_of_arg(tab, doc);
	path_for_excve(tab, doc, env);
	if (execve((*doc).path_for_excve, (*doc).arg_for_excve, envi) == -1)
	{
		write(2, "command not found: ", 19);
		write(2, (*doc).path_for_excve, ft_strlen((*doc).path_for_excve));
		write(2, "\n", 1);
		free_all(tab);
		free((*doc).arg_for_excve);
		free((*doc).path_for_excve);
		exit(127);
	}
}
