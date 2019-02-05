/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 17:06:53 by llopez            #+#    #+#             */
/*   Updated: 2018/04/04 23:24:32 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*ft_printf_itoa_base(uintmax_t nb, unsigned int base,\
		int type)
{
	int				i;
	static char		str[64];

	i = 62;
	if (nb == 0)
		return ("0");
	while (nb > 0 && i > 0)
	{
		if (type >= 'A' && type <= 'Z')
			str[i] = "0123456789ABCDEF"[nb % base];
		else if (type >= 'a' && type <= 'z')
			str[i] = "0123456789abcdef"[nb % base];
		nb /= base;
		--i;
	}
	return (str + i + 1);
}
