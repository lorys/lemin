/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_tube.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 22:33:52 by llopez            #+#    #+#             */
/*   Updated: 2018/12/06 07:17:35 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int				make_tube(char *line, t_tube *tube)
{
	char	**split_tmp;
	t_tube	*room_first;
	t_tube	*room_second;


	split_tmp = ft_strsplit(line, '-');
	room_first = find_room(split_tmp[0], &tube);
	room_second = find_room(split_tmp[1], &tube);
	if (room_first && room_second)
	{
		realloc_paths(room_first->links, room_second);
		realloc_paths(room_second->links, room_first);
		ret = 1;
	}
	free_char_tab(split_tmp);
}
