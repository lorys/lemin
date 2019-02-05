/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calc_fg_d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 18:30:51 by llopez            #+#    #+#             */
/*   Updated: 2018/04/04 10:36:03 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_calc_fg_d(t_arg *fg, intmax_t nb)
{
	fg->space = (nb < 0) ? 0 : fg->space;
	fg->zero = (fg->precision > -1 || !fg->width_used || fg->moins) ? \
		0 : fg->zero;
	fg->width = fg->width - fg->zero;
	fg->width = (fg->space && fg->width_used && fg->zero)\
		? fg->width - 1 : fg->width;
	fg->width = (fg->width_used && (nb < 0 || fg->plus)\
		&& fg->precision < fg->width) ? fg->width - 1 : fg->width;
}
