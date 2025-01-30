# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oettaqi <oettaqi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/21 12:24:21 by othmaneetta       #+#    #+#              #
#    Updated: 2025/01/23 16:41:22 by oettaqi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

LIB = libftpipex.a

SRCS = main.c execute.c execve_arg.c execve_path.c 

CFLAGS = -Wall -Wextra -Werror

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