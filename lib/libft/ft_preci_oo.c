/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_preci_oo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 18:01:23 by llopez            #+#    #+#             */
/*   Updated: 2018/04/25 15:33:35 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_preci_oo(t_arg *fg, char *str, int nb)
{
	int		lenght;
	int		preci;
	int		strlen;

	strlen = (fg->hfound && nb != 0) ? (int)ft_strlen(str) + 1 : \
				(int)ft_strlen(str);
	nb = 0;
	preci = fg->precision;
	lenght = 0;
	preci = (preci > -1) ? preci - strlen : preci;
	while (preci > 0)
	{
		lenght += ft_printf_putlstr("0");
		preci--;
	}
	return (lenght);
}
