/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_room.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 22:11:45 by llopez            #+#    #+#             */
/*   Updated: 2018/11/30 08:16:56 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_tube		*save_room(t_tube *room_list, char *name, int x, int y)
{
	t_tube	*new;
	t_tube	*tmp;

	if (!(new = (t_tube *)ft_memalloc(sizeof(*new))))
		return (NULL);
	if (!(new->name = ft_strdup(name)))
	{
		ft_memdel((void **)&new);
		return (new);
	}
	new->x = x;
	new->y = y;
	new->prev = room_list;
	new->next = NULL;
	new->ants = 0;
	new->vu = 0;
	new->links = NULL;
	if (!room_list)
		return (new);
	tmp = room_list;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	return (room_list);
}
