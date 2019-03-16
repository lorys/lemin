/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarles <pcarles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 07:49:24 by pcarles           #+#    #+#             */
/*   Updated: 2019/03/16 18:06:59 by pcarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "common.h"
#include "parser.h"

int			is_tube_valid(char *line, t_vertice *room_list, int nline)
{
	int		ret;
	char	**tmp;

	ret = 0;
	tmp = ft_strsplit(line, '-');
	if (!(ft_strchr(line, '-') && !ft_strchr(line, ' ')) || !tmp \
		|| count_char(line, '-') != 1)
		error_parsing("tube not well formated", nline);
	else if (!find_room(tmp[0], room_list) || !find_room(tmp[1], room_list))
		error_parsing("unknown room", nline);
	else
		ret = 1;
	free_char_tab(tmp);
	return (ret);
}

t_vertice	*is_room_valid(char *line, t_vertice *room_list, int nline)
{
	int			i;
	char		**tmp;
	t_vertice	*new;

	i = 0;
	tmp = ft_strsplit(line, ' ');
	new = NULL;
	while (tmp[i])
		i++;
	if (i != 3 || **tmp == 'L' || **tmp == '#' || !ft_strisnumber(tmp[1]) \
		|| !ft_strisnumber(tmp[2]) || count_char(line, ' ') != 2 \
		|| ft_strchr(tmp[0], '-'))
		error_parsing("room not well formated", nline);
	else if (!check_overflow(tmp[1]) && !check_overflow(tmp[2]))
		error_parsing("int overflow on room coordinates", nline);
	else if (find_room(tmp[0], room_list))
		error_parsing("room already exists", nline);
	else
		new = create_room(tmp[0], ft_atoi(tmp[1]), ft_atoi(tmp[2]));
	free_char_tab(tmp);
	return (new);
}

int			save_tube_if_valid(char *line, t_vertice *rooms, t_infos *infos, \
			int nline)
{
	if (is_tube_valid(line, rooms, nline))
	{
		make_tube(line, rooms, infos);
		return (1);
	}
	return (0);
}

int			save_room_if_valid(char *line, t_vertice **room_listp, \
			t_infos *infos, int nline)
{
	t_vertice	*tmp;

	if ((tmp = is_room_valid(line, *room_listp, nline)))
	{
		append_room(room_listp, tmp);
		infos->room_total++;
		return (1);
	}
	return (0);
}
