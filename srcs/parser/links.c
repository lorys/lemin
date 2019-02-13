/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   links.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarles <pcarles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 18:27:40 by pcarles           #+#    #+#             */
/*   Updated: 2019/02/13 11:47:44 by pcarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "ft_printf.h"
#include "common.h"
#include "lem_in.h"
#include "parser.h"

static t_path	*create_link(t_vertice *room)
{
	t_path		*new;

	if (!(new = (t_path *)ft_memalloc(sizeof(*new))) || !room)
		return (NULL);
	new->room = room;
	new->next = NULL;
	return (new);
}

static void	append_links(t_path **links, t_path *to_add)
{
	t_path	*tmp;

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
		if (write_matrix(infos->adjacency_matrix, 1, first_room->id, second_room->id) == -1)
		{
			ft_printf("merd\n");//whooo
			exit(1);
		}
		if (write_matrix(infos->adjacency_matrix, 1, second_room->id, first_room->id) == -1)
		{
			ft_printf("merd\n");//whooooooooooo
			exit(1);
		}
		append_links(&first_room->links, create_link(second_room));
		append_links(&second_room->links, create_link(first_room));
	}
}
