/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_details_x.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 18:17:55 by llopez            #+#    #+#             */
/*   Updated: 2018/03/28 18:18:13 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_p_details_x(t_arg *fg, intmax_t nb, char const *format)
{
	int	lenght;

	lenght = 0;
	if (fg->hfound == 1 && nb != 0)
	{
		ft_putchar('0');
		ft_putchar(format[0]);
		lenght += 2;
	}
	return (lenght);
}
