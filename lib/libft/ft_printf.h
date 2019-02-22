/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 06:39:39 by llopez            #+#    #+#             */
/*   Updated: 2018/04/25 17:38:25 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdint.h>
# include <locale.h>
# include <stddef.h>
# include <wchar.h>
# include "libft.h"

typedef struct		s_arg
{
	int				hh;
	int				h;
	int				l;
	int				ll;
	int				j;
	int				z;
	int				width;
	int				precision;
	int				min;
	int				max;
	int				hfound;
	int				moins;
	int				plus;
	int				space;
	int				zero;
	int				width_used;
	int				flag;
}					t_arg;

int					ft_printf(const char*format, ...);
int					ft_printf_s(const char*format, va_list ap,\
						int *skip, t_arg *fg);
int					ft_printf_putlstr(char *str);
int					ft_printf_p(const char *format, va_list ap,\
						int *skip, t_arg *fg);
int					ft_printf_bigc(const char *format, va_list ap,\
						int *skip, t_arg *fg);
int					ft_printf_d(const char *format, va_list ap,\
						int *skip, t_arg *fg);
int					ft_printf_c(char const *format, va_list ap,\
						int *skip, t_arg *fg);
char				*ft_printf_itoa_base(uintmax_t nb, unsigned int base,\
						int	type);
int					ft_printf_flags(char const *format, int *skip, t_arg *fg);
int					ft_printf_xx(char const *format, va_list ap,\
						int *skip, t_arg *fg);
int					ft_printf_oo(char const *format, va_list ap, int *skip,\
						t_arg *fg);
int					ft_printf_uu(char const *format, va_list ap, int *skip,\
						t_arg *fg);
void				ft_initialize_struct(t_arg *fg);
int					ft_add(int *nb, int plus);
int					ft_printf_width(t_arg *fg, int r, char *str, int len);
int					ft_get_precision(const char *str);
int					ft_get_width(const char *str, t_arg *fg);
int					ft_printf_percent(char const*format, int *skip, t_arg *fg);
intmax_t			ft_printf_signed(va_list ap, t_arg *fg);
uintmax_t			ft_printf_unsigned(va_list ap, t_arg *fg);
int					ft_printf_precision(t_arg *fg, int width);
int					ft_printf_putspace_d(t_arg *fg, char *str);
int					ft_printf_putspace(t_arg *fg, char *str);
int					ft_printf_width_str(t_arg *fg, int r, char *str);
int					ft_xx_calc_length(t_arg *fg, uintmax_t nb, char *str);
int					ft_preci_xx(int preci, char *str);
int					ft_preci_oo(t_arg *fg, char *str, int nb);
int					ft_p_details_x(t_arg *fg, intmax_t nb, char const *format);
void				ft_width_oo(t_arg *fg, int nb);
void				ft_calc_fg_d(t_arg *fg, intmax_t nb);
void				ft_printf_flags_detect(char const *format, t_arg *fg,\
						int pass_precision, int lenght);
int					ft_printf_bigs(const char *format, va_list ap, int *skip, \
						t_arg *fg);
int					ft_rest_s_flag(t_arg *fg, char *str);
int					ft_wstrlen(wchar_t *c);
int					ft_wcharlen(wchar_t c);
int					ft_putwstr(wchar_t *str);
int					ft_putwchar(wchar_t c);
int					ft_wstrlen_unit(wchar_t *c);
int					ft_putsubwstr(wchar_t *str, int length);
int					ft_subwstrlen_unit(wchar_t *str, int length);
int					ft_subwstrlen(wchar_t *str, int length);
int					ft_printf_bigc(const char *format, va_list ap, int *skip, \
						t_arg *fg);
wchar_t				*ft_fill_null(wchar_t *str);
int					ft_printf_width_wchar(t_arg *fg, int where, wchar_t c);
int					ft_putwchar(wchar_t c);
int					ft_valid_wchar(wchar_t c);
int					ft_putsubstr(char *str, int len);
void				ft_wchar_one_o(char *a, wchar_t c);
void				ft_wchar_two_o(char *a, wchar_t c);
void				ft_wchar_tree_o(char *a, wchar_t c);

#endif
