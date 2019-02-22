/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_precision.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 17:09:45 by llopez            #+#    #+#             */
/*   Updated: 2018/04/05 01:44:05 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int					ft_get_precision(const char *str)
{
	int		i;
	char	*tmp;
	int		result;

	i = 1;
	if (!ft_isdigit(str[i]))
		return (0);
	while (ft_isdigit(str[i]))
		i++;
	tmp = ft_strndup(&str[1], i - 1);
	result = ft_atoi(tmp);
	free(tmp);
	return (result);
}
