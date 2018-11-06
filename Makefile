# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: llopez <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/24 19:15:43 by llopez            #+#    #+#              #
#    Updated: 2018/11/06 23:13:30 by llopez           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	main.c\
		find_path.c\
		find_room.c\
		make_tube.c\
		realloc_links.c\
		save_end.c\
		save_room.c\
		save_start.c\
		show_struct.c

BIN = Lem-in

FLAG = -Wall -Wextra -Werror

OBJDIR = obj/

$(OBJDIR)%.o: srcs/%.c libft/libft.a libft/libft.h header/lem-in.h
	mkdir -p $(OBJDIR)
	gcc -o $@ $(FLAG) -c $< -I libft/ -I header/

OBJ = $(SRCS:%.c=$(OBJDIR)%.o)

all: $(OBJ)
	gcc -o $(BIN) $(FLAG) $(OBJ) -I libft/ -I header/ libft/libft.a

