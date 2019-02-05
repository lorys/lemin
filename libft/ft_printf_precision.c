/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_precision.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 18:18:38 by llopez            #+#    #+#             */
/*   Updated: 2018/03/28 18:19:08 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_printf_precision(t_arg *fg, int width)
{
	int lenght;
	int	precision;

	precision = fg->precision - width;
	lenght = 0;
	if (fg->precision < 1)
		return (0);
	while (precision > 0)
	{
		if (ft_strchr("oOxX", fg->flag) && !fg->zero && !fg->hfound)
			lenght += ft_printf_putlstr(" ");
		else
			lenght += ft_printf_putlstr("0");
		precision--;
	}
	return (lenght);
}
