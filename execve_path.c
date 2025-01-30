/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oettaqi <oettaqi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 13:55:56 by othmaneetta       #+#    #+#             */
/*   Updated: 2025/01/29 18:17:12 by oettaqi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_strlen(char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char  *s1, char  *s2)
{
	int		size2;
	int		i;
	char	*resu;
	int		j;

	size2 = ft_strlen(s2);
	i = 0;
	j = 0;
	resu = malloc(sizeof(char) * (ft_strlen(s1) + size2 + 1));
	if (!resu)
		return (0);
	while (i < ft_strlen(s1))
	{
		resu[i] = s1[i];
		i++;
	}
	while (i < ft_strlen(s1) + size2)
	{
		resu[i] = s2[j];
		j++;
		i++;
	}
	resu[i] = '\0';
	return (resu);
}

// void	check_command_in_path(char *command, pipex *doc, char *path, char **tab)
// {
// 	int i;

// 	i = 0;
// 	while (tab[i])
// 	{
// 		if (access(ft_strjoin(tab[i], "/ls"), F_OK) == 0)
//         	printf("la commande ls est dans %s\n", tab[i]);
//     	else
//         	printf("la commande ls n est pas dans %s\n", tab[i]);
//         i++;
// 	}
// }

void	path_for_excve(char **tab_of_arg, pipex *doc, char **env)
{
	int i;
	int size;
	char *command;
	char *path;

	i = 0;
	if (tab_of_arg[0][0] == '/')
	{
		(*doc).path_for_excve = tab_of_arg[0];
		return ;
	}
	size = ft_strlen(tab_of_arg[0]);
	command = malloc(sizeof(char) * (size + 1));
	while(i < size)
	{
		command[i] = tab_of_arg[0][i];
		i++;
	}
	command[i] = 0;
	//path = extract_path(env);
	(*doc).path_for_excve = ft_strjoin( "/usr/bin/", command);
}

// int main()
// {
// 	pipex doc;
// 	//int i = 0;
	
// 	char *tab[] = {"tr", "'[:lower:]'", "'[:upper:]'", NULL};
// 	path_for_excve(tab, &doc);
// 	printf("%s", doc.path_for_excve);
// 	return (0);
// }