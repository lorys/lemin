/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 16:02:32 by llopez            #+#    #+#             */
/*   Updated: 2018/04/25 17:14:00 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int					ft_valid_wchar(wchar_t c)
{
	if ((c >= 0xD800 && c <= 0xDFFF) || c >= 0x10FFFE || c < 0)
		return (0);
	return (1);
}

int					ft_putwchar(wchar_t c)
{
	char	a[4];

	if (!ft_valid_wchar(c))
		return (-1);
	if (c <= 0x7F)
		write(1, &c, 1);
	else if (c > 0x7F && c <= 0x7FF)
	{
		ft_wchar_one_o(a, c);
		return (2);
	}
	else if (c > 0x7FF && c <= 0xFFFF)
	{
		ft_wchar_two_o(a, c);
		return (3);
	}
	else
	{
		ft_wchar_tree_o(a, c);
		return (4);
	}
	return (1);
}
