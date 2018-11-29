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

int	make_tube(char *line, t_tube *tube)
{
	int		ret;
	char	**split_tmp;

	ret = 0;
	split_tmp = ft_strsplit(line, '-');
	if (find_room(split_tmp[0], &tube) && find_room(split_tmp[1], &tube))
	{
		find_room(split_tmp[0], &tube)->links = realloc_links(\
				find_room(split_tmp[0], &tube), find_room(split_tmp[1], &tube));
		find_room(split_tmp[1], &tube)->links = realloc_links(\
				find_room(split_tmp[1], &tube), find_room(split_tmp[0], &tube));
		ret = 1;
	}
	free_char_tab(split_tmp);
	return (ret);
}
