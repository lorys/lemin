/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 23:36:01 by llopez            #+#    #+#             */
/*   Updated: 2018/08/01 15:59:06 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf_bigc(const char *format, va_list ap, int *skip, t_arg *fg)
{
	wchar_t c;
	int		len;
	int		tmp;

	len = 0;
	tmp = 0;
	if (format[0] == 'C' || (format[0] == 'c' && fg->l))
	{
		*skip += 2;
		c = va_arg(ap, wchar_t);
		len += ft_printf_width_wchar(fg, 0, c);
		tmp = ft_putwchar(c);
		len += tmp;
		len += ft_printf_width_wchar(fg, 1, c);
		return ((tmp >= -1) ? len : tmp);
	}
	return (0);
}

int		ft_lstr(t_arg *fg, wchar_t *str, wchar_t *str_char, int where)
{
	return (ft_printf_width(fg, where, NULL, (str == NULL) ? \
				ft_subwstrlen(str_char, fg->precision) : \
				ft_subwstrlen(str, fg->precision)));
}

int		ft_printf_bigs(const char *format, va_list ap, int *skip, t_arg *fg)
{
	wchar_t	*str;
	int		len_str;
	int		width;
	wchar_t	*str_char;

	len_str = 0;
	if (format[0] == 'S' || (format[0] == 's' && fg->l))
	{
		str_char = NULL;
		str_char = ft_fill_null(str_char);
		width = fg->width;
		*skip += 2;
		str = va_arg(ap, wchar_t *);
		fg->precision = ((int)ft_wstrlen(str) > fg->precision &&\
				fg->precision > 0) ? fg->precision : (int)ft_wstrlen(str);
		fg->precision = (str != NULL) ? fg->precision : \
					(int)ft_wstrlen(str_char);
		len_str += ft_lstr(fg, str, str_char, 0);
		len_str += (str == NULL) ? ft_putsubwstr(str_char, fg->precision)\
				: ft_putsubwstr(str, fg->precision);
		len_str += ft_lstr(fg, str, str_char, 1);
		free(str_char);
	}
	return (len_str);
}
