# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oettaqi <oettaqi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/21 12:24:21 by othmaneetta       #+#    #+#              #
#    Updated: 2025/02/16 18:38:37 by oettaqi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

LIB = libftpipex.a

SRCS = main.c execute_1.c execute_2.c execve_arg.c execve_path.c utils.c ft_split.c

CFLAGS = -Wall -Wextra -Werror -g

CC = cc

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	cc $(OBJS) -o $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all