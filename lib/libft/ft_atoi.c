/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 17:33:18 by llopez            #+#    #+#             */
/*   Updated: 2017/11/16 20:07:40 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_numblen(const char *str)
{
	int b;

	b = 0;
	while (str[b] == ' ' || (str[b] >= 9 && str[b] <= 13))
		b++;
	b = (str[b] == '-' || str[b] == '+') ? b + 1 : b;
	while (ft_isdigit(str[b]))
		b++;
	return (b);
}

int				ft_atoi(char const *str)
{
	int i;
	int zero;
	int tmp;
	int result;
	int positive;

	result = 0;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	positive = (str[i] == '-') ? -1 : 1;
	positive = (str[i] == '+') ? 1 : positive;
	i = (str[i] == '-' || str[i] == '+') ? i : i - 1;
	while (ft_isdigit(str[++i]))
	{
		zero = 0;
		tmp = ((int)str[i] - '0') * positive;
		while (zero++ < ((int)ft_numblen((char const *)str) - i - 1))
			tmp *= 10;
		result += tmp;
	}
	return (result);
}
