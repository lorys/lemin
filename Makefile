# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pcarles <pcarles@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/24 19:15:43 by llopez            #+#    #+#              #
#    Updated: 2019/02/11 16:37:04 by pcarles          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= lem-in
NAME_1		= visualizer

CC			= gcc
C_FLAGS		= -Wall -Wextra -Werror -fsanitize=address -g3
LD_FLAGS	= -fsanitize=address

SRCDIR		= srcs/
INCLDIR		= header/
LIBDIR		= libft/
OBJDIR		= obj/

H_FILES		= lem_in.h \
			libft.h \
			ft_printf.h \
			get_next_line.h

H_FILES_1	= lem_in.h \
			parser.h \
			libft.h \
			ft_printf.h \
			vizualizer.h

C_FILES		= main.c \
			free.c \
			init.c \
			utils.c \
			matrix.c \
			pasrer/errors.c \
			parser/links.c \
			parser/parsing_functions.c \
			parser/read_file.c \
			parser/parse.c \
			parser/save_room.c \
			parser/utils_parser.c \
			algo/find_paths.c \
			algo/select_paths.c \
			algo/edmonds_karp.c

C_FILES_1	= free.c \
			init.c \
			utils.c \
			matrix.c \
			parser/errors.c \
			parser/links.c \
			parser/parsing_functions.c \
			parser/parse.c \
			parser/save_room.c \
			parser/utils_parser.c \
			visualizer/main_vizu.c \
			visualizer/parser.c \
			visualizer/bresenham.c


LIBFT		= $(LIBDIR)libft.a

SRC			= $(addprefix $(SRCDIR), $(C_FILES))
SRC_1		= $(addprefix $(SRCDIR), $(C_FILES_1))
OBJ			= $(patsubst %.c, %.o, $(addprefix $(OBJDIR), $(notdir $(SRC))))
OBJ_1		= $(patsubst %.c, %.o, $(addprefix $(OBJDIR), $(notdir $(SRC_1))))
HDRS		= $(addprefix $(INCLDIR), $(H_FILES))
HDRS_1		= $(addprefix $(INCLDIR), $(H_FILES_1))

VPATH		= $(shell find $(SRCDIR) -type d)

export CC C_FLAGS LD_FLAGS

.PHONY: all clean fclean re norm

all: $(NAME) $(NAME_1)

$(NAME): $(OBJ) $(LIBFT)
	@$(CC) -o $@ $(OBJ) -L$(LIBDIR) -lft $(C_FLAGS) $(LD_FLAGS)
	@printf "\033[32m BINARY FILE $@ CREATED \033[0m\n"

$(NAME_1): $(OBJ_1) $(LIBFT)
	@$(CC) -o $@ $(OBJ_1) -L$(LIBDIR) -lft -lncurses $(C_FLAGS) $(LD_FLAGS)
	@printf "\n\033[32m BINARY FILE $@ CREATED \033[0m\n"

$(LIBFT):
	@$(MAKE) -C $(LIBDIR)

$(OBJDIR)%.o: %.c $(HDRS)
	@mkdir -p $(OBJDIR)
	@$(CC) -o $@ -c $< -I $(INCLDIR) $(C_FLAGS)
	@printf "\e[1A\r\033[34m $@                  \033[0m\n"

clean:
	@$(MAKE) -C $(LIBDIR) $@
	@printf "\033[35m $@ LIBFT \033[0m\n"
	@rm -rf $(OBJDIR)
	@printf "\033[35m DELETE $(OBJDIR) \033[0m\n"

fclean:
	@$(MAKE) -C $(LIBDIR) $@
	@printf "\033[35m $@ LIBFT \033[0m\n"
	@rm -rf $(OBJDIR)
	@printf "\033[35m DELETE $(OBJDIR) \033[0m\n"
	@rm -f $(NAME)
	@printf "\033[35m DELETE $(NAME) \033[0m\n"
	@rm -f $(NAME_1)
	@printf "\033[35m DELETE $(NAME_1) \033[0m\n"

re: fclean all

norm:
	@norminette $(SRCDIR) $(INCLDIR)
