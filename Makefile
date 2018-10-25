# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: llopez <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/24 19:15:43 by llopez            #+#    #+#              #
#    Updated: 2018/10/23 12:15:39 by llopez           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	main.c

BIN = Lem-in

all:
	gcc -o $(BIN) $(SRCS) -I lem-in.h -I libft/ libft/libft.a

fsani:
	gcc -o $(BIN) $(SRCS) -I lem-in.h -I libft/ libft/libft.a -fsanitize=address
