/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wlen.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 16:01:41 by llopez            #+#    #+#             */
/*   Updated: 2018/04/25 17:14:34 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int					ft_wstrlen_unit(wchar_t *c)
{
	int		i;

	i = 0;
	if (c == NULL)
		return (0);
	while (c[i])
		i++;
	return (i);
}

int					ft_wstrlen(wchar_t *c)
{
	int		len;
	int		i;

	i = 0;
	len = 0;
	if (c == NULL)
		return (0);
	while (c[i])
	{
		if (c[i] <= 0x7F)
			len += 1;
		else if (c[i] > 0x7F && c[i] <= 0x7FF)
			len += 2;
		else if (c[i] > 0x7FF && c[i] <= 0xFFFF)
			len += 3;
		else
			len += 4;
		i++;
	}
	return (len);
}

int					ft_wcharlen(wchar_t c)
{
	if (!ft_valid_wchar(c))
		return (-1);
	if (c <= 0x7F)
		return (1);
	else if (c > 0x7F && c <= 0x7FF)
		return (2);
	else if (c > 0x7FF && c <= 0xFFFF)
		return (3);
	else
		return (4);
	return (-1);
}
