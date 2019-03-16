/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putsubstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 14:26:37 by llopez            #+#    #+#             */
/*   Updated: 2018/04/25 14:26:52 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_putsubstr(char *str, int len)
{
	if (len <= (int)ft_strlen(str))
		write(1, str, len);
	else
		write(1, str, (int)ft_strlen(str));
	return ((len <= (int)ft_strlen(str)) ? len : (int)ft_strlen(str));
}
