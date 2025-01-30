/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oettaqi <oettaqi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 11:55:44 by othmaneetta       #+#    #+#             */
/*   Updated: 2025/01/29 17:02:58 by oettaqi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
#define PIPEX_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <fcntl.h>

typedef struct pipex
{
	int infile_fd;
	int	outfile_fd;
	char *path_for_excve;
	char **arg_for_excve;
	char *env;
}				pipex;

void	execute_program_1(int ac, char **av, pipex *doc);
void	execute_program_2(int ac, char **av,  pipex *doc);
void	tab_of_arg(char **tab, pipex *doc);
char	**ft_split(char const *s, char c);
void	path_for_excve(char **tab_of_arg, pipex *doc, char **env);
void	free_all(char **tab);
char	*ft_strjoin(char  *s1, char  *s2);
int	ft_strlen(char *s);


#endif