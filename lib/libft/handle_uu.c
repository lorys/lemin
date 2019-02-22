/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_uu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 17:14:28 by llopez            #+#    #+#             */
/*   Updated: 2018/04/04 17:56:29 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_printf_uu(char const *format, va_list ap, int *skip, t_arg *fg)
{
	int		len;
	char	*str;

	len = 0;
	if (format[0] == 'u' || format[0] == 'U')
	{
		if (format[0] == 'U')
			str = ft_printf_itoa_base(va_arg(ap, unsigned long int), 10, 'a');
		else
			str = ft_printf_itoa_base(ft_printf_unsigned(ap, fg), 10, 'a');
		*skip += 2;
		fg->zero = (fg->precision > -1) ? 0 : fg->zero;
		len += ft_printf_width_str(fg, 0, str);
		len += ft_printf_precision(fg, (int)ft_strlen(str));
		len += (str[0] == '0' && fg->precision == 0) ? 0 : \
			ft_printf_putlstr(str);
		len += ft_printf_width_str(fg, 1, str);
	}
	return (len);
}
