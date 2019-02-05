/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 17:15:00 by llopez            #+#    #+#             */
/*   Updated: 2018/03/19 17:15:19 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_initialize_struct(t_arg *fg)
{
	fg->hh = 0;
	fg->h = 0;
	fg->l = 0;
	fg->ll = 0;
	fg->j = 0;
	fg->z = 0;
	fg->width = 0;
	fg->precision = -1;
	fg->min = 0;
	fg->max = 0;
	fg->hfound = 0;
	fg->moins = 0;
	fg->plus = 0;
	fg->space = 0;
	fg->zero = 0;
	fg->width_used = 0;
	fg->flag = 0;
}
