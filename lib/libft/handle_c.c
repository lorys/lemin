/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_c.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 17:13:18 by llopez            #+#    #+#             */
/*   Updated: 2018/04/01 20:41:07 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_printf_c(char const *format, va_list ap, int *skip, t_arg *fg)
{
	int	len;

	len = 0;
	if (format[0] == 'c' && !fg->l)
	{
		*skip += 2;
		len += ft_printf_width_str(fg, 0, "0");
		ft_putchar(va_arg(ap, int));
		len += ft_printf_width_str(fg, 1, "0") + 1;
	}
	return (len);
}
