/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_putspace.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 12:13:58 by llopez            #+#    #+#             */
/*   Updated: 2018/04/04 09:02:54 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_printf_putspace(t_arg *fg, char *str)
{
	(void)str;
	if (!fg->space)
		return (0);
	if (fg->space && fg->width_used)
		return (0);
	if (fg->space && fg->width_used && fg->width <= fg->precision)
		return (0);
	if (fg->space && fg->width_used && fg->width <= (int)ft_strlen(str))
		return (0);
	if (fg->space && fg->plus)
		return (0);
	ft_putchar(' ');
	return (1);
}
