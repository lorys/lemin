/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarles <pcarles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 15:17:38 by llopez            #+#    #+#             */
/*   Updated: 2019/02/03 23:54:15 by pcarles          ###   ########.fr       */
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
