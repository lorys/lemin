/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 17:09:00 by llopez            #+#    #+#             */
/*   Updated: 2018/04/04 12:08:21 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int			ft_printf_d_print(t_arg *fg, char *str, intmax_t nb, \
						int str_len)
{
	int lenght;

	lenght = 0;
	lenght += ft_printf_putspace_d(fg, str);
	lenght += (!fg->zero) ? ft_printf_width(fg, 0, NULL, str_len) : 0;
	lenght += (fg->plus && nb >= 0) ? \
			ft_printf_putlstr("+") : 0;
	lenght += (nb < 0) ? ft_printf_putlstr("-") : 0;
	lenght += (fg->zero && fg->width >= str_len) ? ft_printf_putlstr("0") : 0;
	lenght += (fg->zero && fg->width > 0) ? \
			ft_printf_width(fg, 0, NULL, str_len) : 0;
	lenght += ft_printf_precision(fg, str_len);
	lenght += (nb == 0 && fg->precision == 0) ? 0 : ft_printf_putlstr(str);
	lenght += ft_printf_width(fg, 1, NULL, str_len);
	return (lenght);
}

int					ft_printf_d(const char *format, va_list ap, int *skip,\
		t_arg *fg)
{
	int				lenght;
	intmax_t		nb;
	char			*str;
	int				str_len;

	lenght = 0;
	nb = 0;
	str_len = 0;
	if (format[0] == 'd' || format[0] == 'D' || format[0] == 'i')
	{
		fg->l = (fg->l == 0 && format[0] == 'D') ? 1 : fg->l;
		*skip += 2;
		nb = ft_printf_signed(ap, fg);
		fg->space = (nb < 0) ? 0 : fg->space;
		str = ft_printf_itoa_base((nb < 0) ? nb * -1 : nb, 10, 'a');
		ft_calc_fg_d(fg, nb);
		str_len = (nb == 0 && fg->precision == 0) ? 0 : (int)ft_strlen(str);
		lenght = ft_printf_d_print(fg, str, nb, str_len);
		ft_initialize_struct(fg);
	}
	return (lenght);
}
