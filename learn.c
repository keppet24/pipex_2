/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   learn.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: othmaneettaqi <othmaneettaqi@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 16:38:02 by othmaneetta       #+#    #+#             */
/*   Updated: 2025/01/21 11:47:18 by othmaneetta      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h> // Pour fork() et sleep()

// int main()
// {
// 	int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
// 	int fd[2];
// 	int sum;
// 	int sum_y;
// 	int i_y;
// 	int id;
// 	int i;

// 	sum = 0;
// 	pipe(fd);
// 	id = fork();
// 	i = 0;
// 	if (id == 0)
// 	{
// 		close(fd[0]);
// 		while (i < 5)
// 		{
// 			sum += arr[i];
// 			i++;
// 		}
// 		printf("Avant d envoyer sum dans la pipe il est egale a %d\n", sum);
// 		write(fd[1], &sum, sizeof(int));
// 		write(fd[1], &i, sizeof(int));
// 	}
// 	else
// 	{
// 		close(fd[1]);
// 		wait(NULL);
// 		read(fd[0], &sum_y, sizeof(int));
// 		printf("Je recupere  pour sum_y : %d\n", sum_y);
// 		read(fd[0], &i_y, sizeof(int));
// 		printf("Je recupere  pour i_y : %d\n", i_y);
// 		while (i_y < 10)
// 		{
// 			sum_y += arr[i_y];
// 			i_y++;
// 		}
// 		printf("La somme est %d\n", sum_y);
// 	}
// }



int main()
{
	int test;

	// char *path = "/bin/ls";

	// char *arg[] = {"/bin/ls",NULL};

	// char *env[] = {NULL};

	// if  (execve(path, arg, env) == -1)
	// 	perror("lol");
	
	int fd = access("main.c", F_OK);
	printf("%d",fd);
	return(0);
}