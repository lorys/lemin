/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_tube.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 22:33:52 by llopez            #+#    #+#             */
/*   Updated: 2018/11/12 06:16:19 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		make_tube(char *line, t_tube *room_list)
{
	char	**split_tmp;
	t_tube	*room1;
	t_tube	*room2;

	split_tmp = ft_strsplit(line, '-');
	room1 = find_room(*split_tmp++, room_list);
	room2 = find_room(*split_tmp--, room_list);
	room1->links = realloc_links(room1, room2);
	room2->links = realloc_links(room2, room1);
	free_char_tab(split_tmp);
}
