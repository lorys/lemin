/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_width.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 12:05:11 by llopez            #+#    #+#             */
/*   Updated: 2018/04/25 15:59:24 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_printf_width(t_arg *fg, int r, char *str, int len)
{
	int lenght;
	int	width;
	int	strlen;

	strlen = (str == NULL || fg->flag == 'x' || fg->flag == 'X') ? len :\
			(int)ft_strlen(str);
	width = fg->width;
	lenght = 0;
	if (fg->width_used && fg->moins == r)
	{
		if (fg->precision > -1 && fg->precision >= strlen)
			width = width - fg->precision;
		else
			width = width - strlen;
		width = (fg->space && !fg->zero) ? width - 1 : width;
		while (width > 0)
		{
			lenght += ft_printf_putlstr((fg->zero) ? "0" : " ");
			--width;
		}
	}
	return (lenght);
}
