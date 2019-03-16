/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 17:07:44 by llopez            #+#    #+#             */
/*   Updated: 2018/04/25 19:18:45 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_printf_width_p(t_arg *fg, int r, int len)
{
	int		len_str;
	int		width;

	width = fg->width;
	len_str = 0;
	if (fg->width_used && r == fg->moins)
	{
		fg->zero = (fg->moins) ? 0 : fg->zero;
		fg->precision = (fg->moins && fg->flag != 'u' && fg->flag != 'U') ? 0 :\
						fg->precision;
		width = (fg->precision >= len) ?\
					width - fg->precision : width - len;
		while (width > 0)
		{
			len_str += ft_printf_putlstr((fg->zero) ? "0" : " ");
			--width;
		}
	}
	return (len_str);
}

int			ft_printf_p(const char *format, va_list ap,\
		int *skip, t_arg *fg)
{
	int		i;
	void	*nb;
	char	*conv;

	i = 0;
	if (format[0] == 'p')
	{
		nb = va_arg(ap, void *);
		conv = ft_printf_itoa_base((uintmax_t)nb, 16, 'a');
		*skip += 2;
		if (fg->zero)
		{
			i += ft_printf_putlstr("0x");
			i += ft_printf_width_p(fg, 0, (int)ft_strlen(conv) + 2);
		}
		else
		{
			i += ft_printf_width_p(fg, 0, (int)ft_strlen(conv) + 2);
			i += ft_printf_putlstr("0x");
		}
		i += ft_printf_precision(fg, (int)ft_strlen(conv));
		i += (nb == 0 && fg->precision == 0) ? 0 : ft_printf_putlstr(conv);
		i += ft_printf_width_p(fg, 1, (int)ft_strlen(conv) + 2);
	}
	return (i);
}
