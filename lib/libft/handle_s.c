/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 17:12:47 by llopez            #+#    #+#             */
/*   Updated: 2018/04/25 17:33:30 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_rest_s_flag(t_arg *fg, char *str)
{
	int len_str;

	len_str = ft_printf_width_str(fg, 0, str);
	while (fg->precision > 0 && fg->precision > (int)ft_strlen(str) \
			&& fg->width_used && !fg->moins)
	{
		len_str++;
		ft_putchar(' ');
		fg->precision--;
	}
	len_str += (ft_printf_putlstr(str) + ft_printf_width_str(fg, 1, str));
	return (len_str);
}

int			ft_pr_calc_lenstr(char *str_new, char *str, t_arg *fg,\
		char *str_tmp)
{
	int	len_str;

	len_str = 0;
	len_str += ((str != NULL && fg->precision > -1) || \
				(str == NULL && fg->precision > -1)) ? \
				ft_rest_s_flag(fg, str_tmp) : 0;
	len_str += (str == NULL && fg->precision == -1) ?\
				ft_rest_s_flag(fg, str_new) : 0;
	len_str += (str != NULL && fg->precision == -1) ?\
				ft_rest_s_flag(fg, str) : 0;
	return (len_str);
}

int			ft_pr_calc_preci(char *str, t_arg *fg)
{
	return (str != NULL && (str[0] == '\0' || \
				(int)ft_strlen(str) < fg->precision));
}

int			ft_printf_s(char const *format, va_list ap, int *skip, t_arg *fg)
{
	char	*str;
	int		len_str;
	char	*str_new;
	char	*str_tmp;

	len_str = 0;
	str_tmp = NULL;
	str_new = NULL;
	if (format[0] == 's' && !fg->l)
	{
		*skip += 2;
		str = va_arg(ap, char *);
		fg->precision = (ft_pr_calc_preci(str, fg)) ? -1 : fg->precision;
		if (str == NULL)
			str_new = ft_strdup("(null)");
		if (fg->precision > -1)
			str_tmp = ft_strndup((str == NULL) ? str_new : &str[0], \
					fg->precision);
		len_str += ft_pr_calc_lenstr(str_new, str, fg, str_tmp);
		if (str == NULL)
			free(str_new);
		if (fg->precision > -1)
			free(str_tmp);
	}
	return (len_str);
}
