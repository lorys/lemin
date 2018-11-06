/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_tube.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 22:33:52 by llopez            #+#    #+#             */
/*   Updated: 2018/11/06 22:34:56 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

void	make_tube(char *line, t_tube *tube)
{
	char	**split_tmp;
	split_tmp = ft_strsplit(line, '-');
	if (find_room(split_tmp[0], &tube) && find_room(split_tmp[1], &tube))
	{
		find_room(split_tmp[0], &tube)->links = realloc_links(find_room(split_tmp[0], &tube), find_room(split_tmp[1], &tube));
		find_room(split_tmp[1], &tube)->links = realloc_links(find_room(split_tmp[1], &tube), find_room(split_tmp[0], &tube));
	}
}
