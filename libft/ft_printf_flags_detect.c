/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flags_detect.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 13:45:30 by llopez            #+#    #+#             */
/*   Updated: 2018/04/04 21:46:51 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_printf_flags_detect(char const *format, t_arg *fg,\
				int pass_precision, int lenght)
{
	if (format[lenght] == '#')
		fg->hfound = 1;
	if (format[lenght] == '0' && !ft_isdigit(format[lenght - 1])\
			&& !pass_precision)
		fg->zero = 1;
	if (format[lenght] == '-')
		fg->moins = 1;
	if (format[lenght] == '+')
		fg->plus = 1;
	if (format[lenght] == ' ')
		fg->space = 1;
	if (format[lenght] == 'h' && format[lenght + 1] == 'h')
		fg->hh = 1;
	if (format[lenght] == 'l' && format[lenght + 1] == 'l')
		fg->ll = 1;
	if (fg->hh == 0 && format[lenght] == 'h')
		fg->h = 1;
	if (fg->ll == 0 && format[lenght] == 'l')
		fg->l = 1;
	if (format[lenght] == 'j')
		fg->j = 1;
	if (format[lenght] == 'z')
		fg->z = 1;
	if (format[lenght] == '.' && ++pass_precision)
		fg->precision = ft_get_precision(&format[lenght]);
}
