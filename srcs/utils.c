/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 15:17:38 by llopez            #+#    #+#             */
/*   Updated: 2018/11/28 17:23:27 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_stris(char *str, int (*f)(int c))
{
	while (*str)
	{
		if (!f((int)*str))
			return (0);
		str++;
	}
	return (1);
}

int		ft_strisnumber(char *str)
{
	if (*str == '-' || *str == '+')
		str++;
	return (ft_stris(str, &ft_isdigit));
}