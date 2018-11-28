/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_start.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 22:24:01 by llopez            #+#    #+#             */
/*   Updated: 2018/11/21 08:01:51 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		save_start(t_tube **tube, t_infos *infos)
{
	char	*line;
	char	**tmp;

	while (get_next_line(0, &line) && ((!ft_strncmp(line, "##", 2)\
			&& ft_strcmp(line, "##start") && ft_strcmp(line, "##end"))\
			|| (line[0] == '#' && line[1] != '#')))
		free(line);
	if (!check_room(line))
	{
		free(line);
		return (0);
	}
	ft_printf("%s\n", line);
	tmp = ft_strsplit(line, ' ');
	save_room(tube, tmp[0], ft_atoi(tmp[1]), ft_atoi(tmp[2]));
	infos->start = (*tube)->prev;
	free(line);
	free_char_tab(tmp);
	return (1);
}
