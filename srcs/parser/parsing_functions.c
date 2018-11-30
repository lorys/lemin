/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarles <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 07:49:24 by pcarles           #+#    #+#             */
/*   Updated: 2018/11/30 07:49:25 by pcarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "parser.h"

int			is_tube_valid(char *line)
{
	if (ft_strchr(line, '-') && !ft_strchr(line, ' '))
		return (1);
	return (0);
}

int			save_tube_if_valid(char *line, t_tube *rooms, int nline)
{
	if (is_tube_valid(line))
	{
		if (make_tube(line, rooms))
			return (1);
		error_parsing("unknown room", nline);
		return (0);
	}
	error_parsing("tube not well formated", nline);
	return (0);
}

static int	check_overflow(char *n1, char *n2, int nline)
{
	long	tmp1;
	long	tmp2;

	tmp1 = ft_atoi_long(n1);
	tmp2 = ft_atoi_long(n2);
	if (tmp1 < INT_MIN || tmp1 > INT_MAX || tmp2 < INT_MIN || \
	tmp2 > INT_MAX || ft_strlen(n1) > 10 || ft_strlen(n2) > 10)
	{
		error_parsing("int overflow", nline);
		return (0);
	}
	return (1);
}

int			save_room_if_valid(char *line, t_tube **rooms, int nline)
{
	char	**tmp;
	int		i;

	i = 0;
	tmp = ft_strsplit(line, ' ');
	while (tmp[i])
		i++;
	if (i != 3 || **tmp == 'L' || **tmp == '#' || !ft_strisdigit(tmp[1]) || \
		!ft_strisdigit(tmp[2]))
	{
		i = 0;
		error_parsing("room not well formated", nline);
	}
	else if (!check_overflow(tmp[1], tmp[2], nline))
		i = 0;
	else
	{
		i = 0;
		if (save_room(rooms, tmp[0], ft_atoi(tmp[1]), ft_atoi(tmp[2])))
			i = 1;
		else
			error_parsing("room already exists", nline);
	}
	free_char_tab(tmp);
	return (i);
}

long		ft_atoi_long(char const *s)
{
	int		flag;
	long	res;

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
	while (*s <= '9' && *s >= '0')
	{
		res *= 10;
		res += *s - '0';
		s++;
	}
	if (flag)
		res = -res;
	return (res);
}
