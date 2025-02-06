/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve_arg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taqi <taqi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 11:01:57 by othmaneetta       #+#    #+#             */
/*   Updated: 2025/02/06 01:05:16 by taqi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while ((unsigned char)s1[i] == (unsigned char)s2[i] && s1[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int	size_of_new_tab(char **tab)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (tab[i] != NULL)
	{
		if (ft_strcmp(tab[i], "'") == 0 && ft_strcmp(tab[i - 1], "'") == 0)
			j++;
		i++;
	}
	return (i - j);
}

void	tab_of_arg(char **tab, t_pipex *doc)
{
	int	i;
	int	j;
	int	size_of_arg;

	i = 0;
	j = 0;
	size_of_arg = size_of_new_tab(tab);
	(*doc).arg_for_excve = malloc(sizeof(char *) * (size_of_arg + 1));
	while (i < size_of_arg)
	{
		if (ft_strcmp(tab[i], "'") == 0 && ft_strcmp(tab[i + 1], "'") == 0)
		{
			(*doc).arg_for_excve[i] = " ";
			j = i + 2;
			i++;
		}
		(*doc).arg_for_excve[i] = tab[j];
		i++;
		j++;
	}
	(*doc).arg_for_excve[i] = NULL;
}
// int main()
// {
// 	char **tab;
// 	pipex doc;
// 	//char **new_tab;
// 	int i = 0;
// 	int j = 0;
// 	char *s = "cut -d ' ' -f1";
// 	//char *s1 = "cut -d grep -f1";
// 	char sep = ' ';
// 	tab = ft_split(s, sep);
// 	printf("Le tableau de base est : \n");
// 	while (tab[i] != NULL)
// 	{
// 		printf("%s\n", tab[i]);
// 		i++;
// 	}
// 	printf("La taille du tableau est %d\n", i);
// 	printf("=========================================\n");
// 	tab_of_arg(tab, &doc);
// 	while (j < size_of_new_tab(tab))
// 	{
// 		printf("%s\n", doc.arg_for_excve[j]);
// 		j++;
// 	}
// 	printf("La taille du nouveau tableau est %d\n", size_of_new_tab(tab));
// 	return (0);
// }