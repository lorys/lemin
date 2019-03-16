/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarles <pcarles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 21:46:30 by pcarles           #+#    #+#             */
/*   Updated: 2019/03/09 01:09:21 by pcarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "libft.h"
#include "parser.h"

int				count_char(char *str, char c)
{
	int	ret;

	ret = 0;
	if (!str)
		return (-1);
	while (*str)
	{
		if (*str == c)
			ret++;
		str++;
	}
	return (ret);
}

int				check_overflow(char *str)
{
	long	tmp;

	tmp = ft_atoi_long(str);
	if (tmp < INT_MIN || tmp > INT_MAX || ft_strlen(str) > 10)
		return (0);
	return (1);
}

long			ft_atoi_long(char const *s)
{
	unsigned int	flag;
	long			res;

	flag = 0;
	res = 0;
	while ((*s >= 9 && *s <= 13) || *s == ' ')
		s++;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			flag = 1;
		s++;
	}
	while (ft_isdigit(*s))
	{
		res = (res * 10) + (*s - '0');
		s++;
	}
	return (flag ? -res : res);
}

unsigned int	count_room(t_vertice *room_list)
{
	unsigned int	count;

	count = 0;
	while (room_list && ++count)
		room_list = room_list->next;
	return (count);
}
