/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   links.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarles <pcarles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 18:27:40 by pcarles           #+#    #+#             */
/*   Updated: 2019/02/07 15:25:39 by pcarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "ft_printf.h"
#include "common.h"
#include "lem_in.h"
#include "parser.h"

static t_paths	*create_link(t_vertice *room)
{
	t_paths		*new;

	if (!(new = (t_paths *)ft_memalloc(sizeof(*new))) || !room)
		return (NULL);
	new->next = NULL;
	new->prev = NULL;
	new->room = room;
	return (new);
}

static void	append_links(t_paths **links, t_paths *to_add)
{
	t_paths	*tmp;

	if (!links || !to_add)
		return ;
	if (!(*links))
	{
		*links = to_add;
		return ;
	}
	tmp = *links;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = to_add;
	to_add->prev = tmp;
}

void		make_tube(char *line, t_vertice *room_list, t_infos *infos)
{
	char		*dash_position;
	t_vertice	*first_room;
	t_vertice	*second_room;

	if ((dash_position = ft_strchr(line, '-')) == NULL)
		return ;
	*dash_position = '\0';
	first_room = find_room(line, room_list);
	*dash_position++ = '-';
	second_room = find_room(dash_position, room_list);
	if (first_room && second_room)
	{
		if (write_matrix(infos, first_room->id, second_room->id) == -1)
		{
			ft_printf("merd\n");
			exit(1);
		}
		if (write_matrix(infos, second_room->id, first_room->id) == -1)
		{
			ft_printf("merd\n");
			exit(1);
		}
		append_links(&first_room->links, create_link(second_room));
		append_links(&second_room->links, create_link(first_room));
	}
}
