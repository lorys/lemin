/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_start.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 22:24:01 by llopez            #+#    #+#             */
/*   Updated: 2018/11/09 09:59:59 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

void	save_start(t_tube **tube, t_infos *infos)
{
	char	*line;
	char	**tmp;

	get_next_line(0, &line);
	ft_printf("%s\n", line);
	tmp = ft_strsplit(line, ' ');
	save_room(tube, tmp[0], ft_atoi(tmp[1]), ft_atoi(tmp[2]));
	infos->start = (*tube)->prev;
}
