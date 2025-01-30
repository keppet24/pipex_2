/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taqi <taqi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 13:18:35 by oettaqi           #+#    #+#             */
/*   Updated: 2025/01/30 17:44:08 by taqi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

#include <stdio.h> 

int ft_strlen(char *s)
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


int	ft_strncmp(char *s1, char *s2, size_t n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (0);
	while ((unsigned char)s1[i] == (unsigned char)s2[i]
		&& s1[i] && (size_t)i < n - 1)
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}


int main(int ac, char **av, char **env)
{
    int i = 0;
    int j = 0;
    char **tab;
    char *path;

	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
		{
			j = i;
			break;
		}
		i++;
	}
	int path_len = ft_strlen(env[j]) - 5; 
	path = malloc(sizeof(char) * (path_len + 1)); 
	int l = 5;
	int m = 0;
	while (env[j][l])
	{
		path[m] = env[j][l];
		l++;
		m++;
	}
	path[m] = '\0';
    printf("Path to split: %s\n", path);
    tab = ft_split(path, ':');
	i = 0;
    char *dir = tab[i];
	while (tab[i])
	{
		dir = tab[i];
    	char *slash = ft_strjoin(dir, "/");
    	char *full_path = ft_strjoin(slash, "ls");
    	if (access(full_path, F_OK) == 0)
		{
        	printf("ls trouvé dans %s\n", slash);
			break;
		}
    	else
        	printf("ls absent de %s\n", dir);
 	   i++;
	}
    return 0;
}
