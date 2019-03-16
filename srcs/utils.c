/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarles <pcarles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 15:17:38 by llopez            #+#    #+#             */
/*   Updated: 2019/03/16 18:08:55 by pcarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "common.h"

int			ft_stris(char *str, int (*f)(int c))
{
	while (*str)
	{
		if (!f((int)*str))
			return (0);
		str++;
	}
	return (1);
}

int			ft_strisnumber(char *str)
{
	if (*str == '-' || *str == '+')
		str++;
	return (ft_stris(str, &ft_isdigit));
}

void		display_error(t_infos *infos)
{
	free_everything(infos);
	write(2, "ERROR\n", 6);
	exit(EXIT_FAILURE);
}

t_vertice	*find_room(char *room_name, t_vertice *room_list)
{
	if (!room_name)
		return (NULL);
	while (room_list)
	{
		if (!ft_strcmp(room_list->name, room_name))
			return (room_list);
		room_list = room_list->next;
	}
	return (NULL);
}

t_vertice	*find_room_by_id(unsigned int id, t_vertice *room_list)
{
	while (room_list)
	{
		if (room_list->id == id)
			return (room_list);
		room_list = room_list->next;
	}
	return (NULL);
}
