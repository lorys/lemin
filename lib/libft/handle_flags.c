/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 17:13:47 by llopez            #+#    #+#             */
/*   Updated: 2018/04/25 17:25:05 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_prfcw(char const *format, int lenght, \
		int first_width)
{
	return (ft_isdigit(format[lenght])\
			&& format[lenght] != '0' && first_width == -1);
}

int			ft_printf_flags(char const *format, int *skip, t_arg *fg)
{
	int		lenght;
	int		first_width;
	int		last_width;
	int		pass_precision;

	pass_precision = 0;
	lenght = 0;
	first_width = -1;
	last_width = 0;
	while (!ft_strchr("sSpdDioOuUxXcC%*", format[lenght]) && format[lenght])
	{
		if (!ft_strchr("#0-+ hljz.123456789", format[lenght]))
		{
			*skip += (lenght > 0) ? lenght : 1;
			return (0);
		}
		*skip += (ft_strchr("#0-+ hljz.123456789", format[lenght])) ? 1 : 0;
		first_width += (ft_prfcw(format, lenght, first_width)) ? lenght : 0;
		last_width += (ft_isdigit(format[lenght]) && first_width > -1) ? 1 : 0;
		ft_printf_flags_detect(&format[0], fg, pass_precision, lenght);
		lenght++;
	}
	fg->flag = format[lenght];
	fg->width = ft_get_width(&format[0], fg);
	return (lenght);
}
