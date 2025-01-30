/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taqi <taqi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 13:55:56 by othmaneetta       #+#    #+#             */
/*   Updated: 2025/01/30 18:10:53 by taqi             ###   ########.fr       */
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

char	*line_of_path(char *str)
{
	char	*resu;
	int		l;
	int		path_len;
	int		m;

	l = 5;
	m = 0;
	path_len = ft_strlen(str) - 5; 
	resu = malloc(sizeof(char) * (path_len + 1)); 
	while (str[l])
	{
		resu[m] = str[l];
		l++;
		m++;
	}
	resu[m] = '\0';
	return (resu);
}

char	**split_path_env(char **env)
{
	int		i;
	int		j;
	char	*path;
	char	**resu;

	i = 0;
	j = 0;	
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
		{
			j = i;
			break;
		}
		i++;
	}
	path = line_of_path(env[j]);
	resu = ft_split(path, ':');
	return (resu);
}

void	set_path(pipex *doc, char **env, char *command)
{
	char 	**repo_of_env;
	char	*dir;
	char	*slash;
	char	*full_path;
	int	i;

	i = 0;
	repo_of_env = split_path_env(env);
	while (repo_of_env[i])
	{
		dir = repo_of_env[i];
    	slash = ft_strjoin(dir, "/");
    	full_path = ft_strjoin(slash, command);
    	if (access(full_path, F_OK) == 0)
		{
			(*doc).env = slash;
			return;
		}
		i++;
	}
}

void	path_for_excve(char **tab_of_arg, pipex *doc, char **env)
{
	int i;
	int size;
	char *command;
	//char *path;

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
	set_path(doc ,env, command);
	//(*doc).path_for_excve = ft_strjoin( "/usr/bin/", command);
	(*doc).path_for_excve = ft_strjoin( (*doc).env, command);
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