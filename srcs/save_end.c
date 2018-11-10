/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_end.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 22:28:56 by llopez            #+#    #+#             */
/*   Updated: 2018/11/10 12:10:35 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"
#include "libft.h"

int		save_end(t_tube **tube, t_infos *infos)
{
	char	*line;
	char	**tmp;

	get_next_line(0, &line);
	if (!check_room(line))
	{
		free(line);
		return (0);
	}
	ft_printf("%s\n", line);
	tmp = ft_strsplit(line, ' ');
	save_room(tube, tmp[0], ft_atoi(tmp[1]), ft_atoi(tmp[2]));
	infos->end = (*tube)->prev;
	free(line);
	return (1);
}
