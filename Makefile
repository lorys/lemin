# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: llopez <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/24 19:15:43 by llopez            #+#    #+#              #
#    Updated: 2018/11/24 15:47:12 by llopez           ###   ########.fr        #
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
		show_struct.c\
		read_stdin.c\
		toend.c\
		ft_tubelen.c\
		move_ants.c\
		set_ants.c\
		free_char_tab.c\
		set_research.c\
		display_error.c\
		free_everything.c\
		free_list.c\
		set_tube.c\
		get_shortest_path.c\
		utils.c

CC = gcc

LINK_LIBFT = -Llibft/ -lft -lpthread

NAME = lem_in

CFLAG = -Wall -Wextra -Werror

LIBFT = libft/libft.a

LIBFT_PATH = libft/

INCLUDES = -I libft/ -I header/

OBJDIR = obj/

$(OBJDIR)%.o: srcs/%.c libft/libft.h header/lem_in.h
	@mkdir -p $(OBJDIR)
	@$(CC) -o $@ $(CFLAG) -c $< $(INCLUDES)
	@printf "\e[1A\r\033[34m $@                  \033[0m\n"

all: $(NAME)

$(LIBFT):
	@make -C libft/

OBJ = $(SRCS:%.c=$(OBJDIR)%.o)

$(NAME): $(LIBFT) $(OBJ)
	@$(CC) -o $(NAME) $(CFLAG) $(OBJ) $(INCLUDES) $(LINK_LIBFT)
	@printf "\033[32m BINARY FILE $(NAME) CREATED \033[0m\n"

fclean:
	@make -C libft/ fclean
	@printf "\033[35m fclean LIBFT \033[0m\n"
	@rm -rf $(OBJDIR)
	@printf "\033[35m DELETE OBJ/ \033[0m\n"
	@rm -rf $(NAME)
	@printf "\033[35m DELETE $(NAME) \033[0m\n"

clean:
	@make -C $(LIBFT_PATH) clean
	@printf "\033[35m clean LIBFT \033[0m\n"
	@rm -rf $(OBJDIR)
	@printf "\033[35m DELETE OBJ/ \033[0m\n"

re: fclean all
