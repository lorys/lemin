/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_room.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 22:11:45 by llopez            #+#    #+#             */
/*   Updated: 2018/12/04 23:12:33 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_tube		*create_room(char *name, int x, int y)
{
	t_tube	*new;

	if (!(new = (t_tube *)ft_memalloc(sizeof(*new))))
		return (NULL);
	if (!(new->name = ft_strdup(name)))
	{
		ft_memdel((void **)&new);
		return (NULL);
	}
	new->x = x;
	new->y = y;
	new->prev = NULL;
	new->next = NULL;
	new->links = NULL;
	new->ants = 0;
	new->vu = 0;
	return (new);
}

void		append_room(t_tube **room_listp, t_tube *room)
{
	t_tube	*tmp;

	if (!room_listp || !room)
		return ;
	if (!(*room_listp))
	{
		*room_listp = room;
		return ;
	}
	tmp = *room_listp;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = room;
	room->prev = tmp;
}
