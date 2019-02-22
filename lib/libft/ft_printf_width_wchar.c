/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_width_wchar.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 16:03:56 by llopez            #+#    #+#             */
/*   Updated: 2018/04/25 16:04:14 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int					ft_printf_width_wchar(t_arg *fg, int where, wchar_t c)
{
	int		width;

	width = 0;
	(void)c;
	if (fg->width_used && fg->width > 0 && where == fg->moins)
	{
		while (fg->width - ft_wcharlen(c) > width)
		{
			ft_putchar(' ');
			width++;
		}
		return (fg->width);
	}
	return (0);
}
