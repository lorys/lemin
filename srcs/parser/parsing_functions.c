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
	else
	{
		i = 1;
		if (!save_room(rooms, tmp[0], ft_atoi(tmp[1]), ft_atoi(tmp[2])))
		{
			error_parsing("room already exists", nline);
			i = 0;
		}
	}
	free_char_tab(tmp);
	return (i);
}
