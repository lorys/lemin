/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_room.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarles <pcarles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 22:11:45 by llopez            #+#    #+#             */
/*   Updated: 2019/02/21 18:20:36 by pcarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parser.h"

t_vertice		*create_room(char *name, int x, int y)
{
	t_vertice			*new;
	static unsigned int	id = 0;

	if (!(new = (t_vertice *)ft_memalloc(sizeof(*new))))
		return (NULL);
	if (!(new->name = ft_strdup(name)))
	{
		ft_memdel((void **)&new);
		return (NULL);
	}
	new->x = x;
	new->y = y;
	new->id = id++;
	new->next = NULL;
	new->links = NULL;
	return (new);
}

void			append_room(t_vertice **room_listp, t_vertice *room)
{
	t_vertice	*tmp;

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
}
