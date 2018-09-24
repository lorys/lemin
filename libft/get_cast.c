/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_hashtag.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 12:20:16 by llopez            #+#    #+#             */
/*   Updated: 2018/04/04 15:18:44 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

intmax_t	ft_printf_signed(va_list ap, t_arg *fg)
{
	if (fg->l)
		return (va_arg(ap, long));
	if (fg->ll)
		return (va_arg(ap, long long));
	if (fg->z)
		return (va_arg(ap, ssize_t));
	if (fg->hh)
		return ((char)va_arg(ap, int));
	if (fg->h)
		return ((short int)va_arg(ap, int));
	if (fg->j)
		return (va_arg(ap, intmax_t));
	return (va_arg(ap, int));
}

uintmax_t	ft_printf_unsigned(va_list ap, t_arg *fg)
{
	if (fg->l)
		return (va_arg(ap, unsigned long));
	if (fg->ll)
		return (va_arg(ap, unsigned long long));
	if (fg->hh)
		return ((unsigned char)va_arg(ap, unsigned int));
	if (fg->h)
		return ((unsigned short int)va_arg(ap, unsigned int));
	if (fg->j)
		return (va_arg(ap, uintmax_t));
	if (fg->z)
		return (va_arg(ap, size_t));
	return (va_arg(ap, unsigned int));
}
