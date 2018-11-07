# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: llopez <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/12 18:15:23 by llopez            #+#    #+#              #
#    Updated: 2018/11/07 16:44:23 by llopez           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SOURCES = ft_atoi.c \
		  ft_bzero.c \
		  ft_isalnum.c \
		  ft_isalpha.c \
		  ft_isascii.c \
		  ft_isdigit.c \
		  ft_isprint.c \
		  ft_memccpy.c \
		  ft_memcpy.c \
		  ft_memmove.c \
		  ft_memset.c \
		  ft_putchar.c \
		  ft_putstr.c \
		  ft_strlen.c \
		  ft_tolower.c \
		  ft_toupper.c \
		  ft_strncmp.c \
		  ft_strcmp.c \
		  ft_strnstr.c \
		  ft_strstr.c \
		  ft_strrchr.c \
		  ft_strchr.c \
		  ft_strcat.c \
		  ft_strncat.c \
		  ft_strlcat.c \
		  ft_strdup.c \
		  ft_strndup.c \
		  ft_memchr.c \
		  ft_memcmp.c \
		  ft_strcpy.c \
		  ft_strncpy.c \
		  ft_memalloc.c \
		  ft_memdel.c \
		  ft_strnew.c \
		  ft_strclr.c \
		  ft_strdel.c \
		  ft_striter.c \
		  ft_striteri.c \
		  ft_strmap.c \
		  ft_strmapi.c \
		  ft_strequ.c \
		  ft_strnequ.c \
		  ft_strsub.c \
		  ft_strjoin.c \
		  ft_strtrim.c \
		  ft_putendl.c \
		  ft_itoa.c \
		  ft_intlen.c \
		  ft_putnbr.c \
		  ft_putchar_fd.c \
		  ft_putstr_fd.c \
		  ft_putendl_fd.c \
		  ft_putnbr_fd.c \
		  ft_swap.c \
		  ft_strsplit.c \
		  ft_lstnew.c \
		  ft_lstdelone.c \
		  ft_lstdel.c \
		  ft_lstadd.c \
		  ft_lstiter.c \
		  ft_lstmap.c \
		  ft_realloc.c \
		  ft_sqrt.c \
		  ft_printf.c \
		  bigs.c \
		  ft_putlnbr.c \
		  get_precision.c \
		  get_width.c \
		  handle_c.c \
		  handle_d.c \
		  handle_flags.c \
		  get_cast.c \
		  handle_p.c \
		  handle_percent.c \
		  handle_s.c \
		  handle_uu.c \
		  init_struct.c \
		  itoa_base.c \
		  putnbr_base.c \
		  width_str.c \
		  ft_xx_calc_length.c \
		  ft_preci_xx.c \
		  ft_printf_xx.c \
		  ft_preci_oo.c \
		  ft_width_oo.c \
		  ft_printf_oo.c \
		  ft_calc_fg_d.c \
		  ft_p_details_x.c \
		  ft_printf_precision.c \
		  ft_printf_flags_detect.c \
		  ft_printf_putspace_d.c \
		  ft_printf_width.c \
		  ft_printf_putlstr.c \
		  ft_printf_getnb.c \
		  ft_printf_width_wchar.c \
		  ft_fill_null.c \
		  ft_wlen.c \
		  ft_putwstr.c \
		  ft_wchar_one_o.c \
		  ft_putwchar.c \
		  get_next_line.c

OBJ = $(SOURCES:%.c=$(OBJDIR)%.o)

FLAG = -Wall -Werror -Wextra

OBJDIR = obj/

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

$(OBJDIR)%.o: %.c libft.h
	@mkdir -p $(OBJDIR) 
	@printf "\e[1A\r\033[33m $@                      \033[0m\n"
	@gcc -o $@ $(FLAG) -c $< -I ../includes

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all
