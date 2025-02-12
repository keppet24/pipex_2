/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oettaqi <oettaqi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 11:55:44 by othmaneetta       #+#    #+#             */
/*   Updated: 2025/02/12 13:30:50 by oettaqi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <unistd.h>
# include <fcntl.h>
# include <errno.h>

typedef struct s_pipex
{
	int		infile_fd;
	int		outfile_fd;
	char	*path_for_excve;
	char	**arg_for_excve;
	char	*env;
}	t_pipex;

void	execute_program_1(int ac, char **av, t_pipex *doc, char **env);
void	execute_program_2(int ac, char **av, t_pipex *doc, char **env);
void	tab_of_arg(char **tab, t_pipex *doc);
char	**ft_split(char const *s, char c);
int		path_for_excve(char **tab_of_arg, t_pipex *doc, char **env);
void	free_all(char **tab);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strlen(char *s);
int		ft_strncmp(char *s1, char *s2, size_t n);
int		ft_strlen(char *s);
char	*ft_strchr(char *s, int c);
int		check_slash(char **tab_of_arg, t_pipex *doc);
char	*ft_strdup(char *src);


#endif