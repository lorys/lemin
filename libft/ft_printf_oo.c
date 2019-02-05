/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_oo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 18:15:28 by llopez            #+#    #+#             */
/*   Updated: 2018/04/25 17:11:31 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_printf_oo(char const *format, va_list ap,\
		int *skip, t_arg *fg)
{
	uintmax_t	nb;
	int			lenght;
	char		*str;
	int			str_len;

	lenght = 0;
	str_len = 0;
	if (format[0] == 'o' || format[0] == 'O')
	{
		fg->l = (format[0] == 'O') ? 1 : fg->l;
		fg->zero = (fg->precision > -1 || fg->moins) ? 0 : fg->zero;
		nb = ft_printf_unsigned(ap, fg);
		str = ft_printf_itoa_base(nb, 8, format[0]);
		str_len = (fg->hfound && nb != 0) ?\
				(int)ft_strlen(str) + 1 : (int)ft_strlen(str);
		str_len = (fg->precision == 0 && nb == 0 && !fg->hfound) ? 0 : str_len;
		lenght += ft_printf_width(fg, 0, NULL, str_len);
		lenght += ft_preci_oo(fg, str, nb);
		lenght += (fg->hfound && nb != 0) ? ft_printf_putlstr("0") : 0;
		lenght += (fg->precision == 0 && nb == 0 && !fg->hfound) ?\
				0 : ft_printf_putlstr(str);
		lenght += ft_printf_width(fg, 1, NULL, str_len);
		*skip += 2;
	}
	return (lenght);
}
