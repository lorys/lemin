/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_xx.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 17:58:43 by llopez            #+#    #+#             */
/*   Updated: 2018/04/04 19:49:38 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_printf_xx(char const *format, va_list ap, int *skip, t_arg *fg)
{
	int			lenght;
	char		*str;
	uintmax_t	nb;

	lenght = 0;
	if (format[0] == 'x' || format[0] == 'X')
	{
		fg->zero = (fg->precision > -1 || fg->moins) ? 0 : fg->zero;
		nb = ft_printf_unsigned(ap, fg);
		fg->hfound = (nb == 0) ? 0 : fg->hfound;
		str = ft_printf_itoa_base(nb, 16, format[0]);
		lenght += (fg->zero) ? ft_p_details_x(fg, nb, format) : 0;
		lenght += ft_printf_width(fg, 0, str, ft_xx_calc_length(fg, nb, str));
		lenght += (!fg->zero) ? ft_p_details_x(fg, nb, format) : 0;
		lenght += ft_preci_xx(fg->precision, str);
		lenght += (fg->precision == 0 && nb == 0) ? 0 : ft_printf_putlstr(str);
		lenght += ft_printf_width(fg, 1, str, ft_xx_calc_length(fg, nb, str));
		*skip += 2;
	}
	return (lenght);
}
