/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oettaqi <oettaqi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 17:52:39 by taqi              #+#    #+#             */
/*   Updated: 2025/02/16 19:56:00 by oettaqi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (unsigned char)c)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == (unsigned char) c)
		return ((char *)&s[i]);
	return (0);
}

int	check_slash(char **tab_of_arg, t_pipex *doc)
{
	if (ft_strchr(tab_of_arg[0], '/'))
	{
		(*doc).path_for_excve = tab_of_arg[0];
		return (1);
	}
	return (0);
}

char	*ft_strdup(char *src)
{
	int		n;
	int		i;
	char	*copy;

	i = 0;
	n = ft_strlen(src);
	copy = (char *)malloc((n + 1) * sizeof (char));
	if (!copy)
		return (0);
	while (src[i])
	{
		copy[i] = src[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}
