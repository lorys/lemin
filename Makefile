# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pcarles <pcarles@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/22 21:11:24 by pcarles           #+#    #+#              #
#    Updated: 2019/03/17 17:16:54 by pcarles          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

HDRDIR			:= header
SRCDIR			:= srcs
DEBUG			:= 1

CC				:= gcc
C_FLAGS			:= -Wall -Wextra -Werror -Ofast

TARGETS			:= lem-in visualizer
LIBS			:= libft

lem-in_LIB		:= ft
visualizer_LIB	:= ft ncurses

lem-in_SRC		:=	main.c \
					free.c \
					init.c \
					utils.c \
					matrix.c \
					parser/errors.c \
					parser/links.c \
					parser/parsing_functions.c \
					parser/read_file.c \
					parser/parse.c \
					parser/save_room.c \
					parser/utils_parser.c \
					algo/find_paths.c \
					algo/edmonds_karp.c \
					algo/show_output.c \
					algo/show_output2.c \
					algo/bfs.c

visualizer_SRC :=	free.c \
					init.c \
					utils.c \
					matrix.c \
					parser/errors.c \
					parser/links.c \
					parser/parsing_functions.c \
					parser/read_file.c \
					parser/parse.c \
					parser/save_room.c \
					parser/utils_parser.c \
					visualizer/main_vizu.c \
					visualizer/init_vizu.c \
					visualizer/bresenham.c

include generic_c.mk
