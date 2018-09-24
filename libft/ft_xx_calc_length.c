/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xx_calc_length.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 17:36:49 by llopez            #+#    #+#             */
/*   Updated: 2018/04/04 19:57:02 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_xx_calc_length(t_arg *fg, uintmax_t nb, char *str)
{
	int		calc_length;

	calc_length = 0;
	calc_length += (fg->precision == 0 && nb == 0) ? 0 : (int)ft_strlen(str);
	calc_length += (fg->hfound && nb != 0) ? 2 : 0;
	calc_length += (fg->precision > (int)ft_strlen(str)\
			&& nb != 0) ? (fg->precision - (int)ft_strlen(str)) : 0;
	return (calc_length);
}
