# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: llopez <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/24 19:15:43 by llopez            #+#    #+#              #
#    Updated: 2018/11/29 05:28:18 by llopez           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= lem-in
NAME_1		= vizualizer

CC			= gcc
C_FLAGS		= -Wall -Wextra -Werror
LD_FLAGS	=

OBJDIR		= obj/
SRCDIR		= srcs/
INCLDIR		= header/
LIBDIR		= libft/

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
			find_path.c \
			find_room.c \
			make_tube.c \
			realloc_links.c \
			save_room.c \
			show_struct.c \
			parser/read_stdin.c \
			paser/errors.c \
			toend.c \
			ft_tubelen.c \
			move_ants.c \
			set_ants.c \
			free_char_tab.c \
			set_research.c \
			display_error.c \
			free_everything.c \
			free_list.c \
			set_tube.c \
			get_shortest_path.c \
			utils.c

C_FILES_1	= vizualizer/main_vizu.c \
			vizualizer/parser.c \
			parser/read_stdin.c \
			parser/errors.c \
			set_tube.c \
			save_room.c \
			make_tube.c \
			utils.c \
			free_everything.c \
			free_char_tab.c \
			toend.c \
			find_room.c \
			free_list.c \
			realloc_links.c \
			vizualizer/bresenham.c

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
	@$(CC) -o $@ -L$(LIBDIR) -lft $(OBJ) $(C_FLAGS) $(LD_FLAGS)
	@printf "\033[32m BINARY FILE $@ CREATED \033[0m\n"

$(NAME_1): $(OBJ_1) $(LIBFT)
	@$(CC) -o $@ -L$(LIBDIR) -lft -lncurses $(OBJ_1) $(C_FLAGS) $(LD_FLAGS)
	@printf "\033[32m BINARY FILE $@ CREATED \033[0m\n"

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
