/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 20:20:53 by llopez            #+#    #+#             */
/*   Updated: 2018/04/25 17:13:08 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_putwstr(wchar_t *str)
{
	int		len;

	len = 0;
	while (*str)
	{
		ft_putwchar(*str);
		len += ft_wcharlen(*str);
		str++;
	}
	return (len);
}

int			ft_subwstrlen(wchar_t *str, int length)
{
	int		i;
	int		len;

	len = 0;
	i = 0;
	while (*str && (length - ft_wcharlen(*str)) >= 0)
	{
		len += ft_wcharlen(*str);
		length -= ft_wcharlen(*str);
		str++;
		i++;
	}
	return (len);
}

int			ft_subwstrlen_unit(wchar_t *str, int length)
{
	int		i;

	i = 0;
	while (*str && (length - ft_wcharlen(*str)) >= 0)
	{
		length -= ft_wcharlen(*str);
		str++;
		i++;
	}
	return (i);
}

int			ft_putsubwstr(wchar_t *str, int length)
{
	int		len;

	len = 0;
	while (*str && (length - ft_wcharlen(*str)) >= 0)
	{
		ft_putwchar(*str);
		len += ft_wcharlen(*str);
		length -= ft_wcharlen(*str);
		str++;
	}
	return (len);
}
