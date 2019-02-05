/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_putspace_d.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 12:06:06 by llopez            #+#    #+#             */
/*   Updated: 2018/04/04 10:05:00 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_printf_putspace_d(t_arg *fg, char *str)
{
	(void)str;
	if ((!fg->space) || (fg->space && fg->plus))
	{
		fg->space = 0;
		return (0);
	}
	ft_putchar(' ');
	return (1);
}
