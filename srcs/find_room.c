/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_room.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 22:22:35 by llopez            #+#    #+#             */
/*   Updated: 2019/02/03 23:17:16 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_tube*	find_room(char *room_name, t_tube *room_list)
{
	t_tube	*tmp;

	if (!room_name || !room_list)
		return (NULL);
	tmp = room_list->next;
	while (room_list)
	{
		if (!ft_strcmp(room_list->name, room_name))
			return (room_list);
		room_list = room_list->prev;
	}
	while (tmp)
	{
		if (!ft_strcmp(tmp->name, room_name))
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}
