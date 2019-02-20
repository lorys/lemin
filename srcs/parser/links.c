/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   links.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarles <pcarles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 18:27:40 by pcarles           #+#    #+#             */
/*   Updated: 2019/02/20 18:10:06 by pcarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "common.h"
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

static void		append_links(t_path **links, t_path *to_add)
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

void			make_tube(char *line, t_vertice *room_list, t_infos *infos)
{
	char		*dash_position;
	t_vertice	*fst_room;
	t_vertice	*scd_room;

	if ((dash_position = ft_strchr(line, '-')) == NULL)
		return ;
	*dash_position = '\0';
	fst_room = find_room(line, room_list);
	*dash_position++ = '-';
	scd_room = find_room(dash_position, room_list);
	if (fst_room && scd_room)
	{
		write_matrix(infos->adjacency_matrix, 1, fst_room->id, scd_room->id);
		write_matrix(infos->adjacency_matrix, 1, scd_room->id, fst_room->id);
		append_links(&fst_room->links, create_link(scd_room));
		append_links(&scd_room->links, create_link(fst_room));
	}
}
