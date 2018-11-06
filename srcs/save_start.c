/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_start.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 22:24:01 by llopez            #+#    #+#             */
/*   Updated: 2018/11/06 23:51:57 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

void	save_start(t_tube *tube, t_infos *infos)
{
	char *line;

	get_next_line(0, &line);
	ft_printf("%s\n", line);
	save_room(&tube, ft_strsplit(line, ' '));
	infos->start = tube->ev;
}
