/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_end.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 22:28:56 by llopez            #+#    #+#             */
/*   Updated: 2018/11/06 22:55:15 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"
#include "libft.h"

void	save_end(t_tube *tube, t_infos *infos)
{
	char	**tmp;
	int		i;
	char	*line;

	i = 0;
	get_next_line(0, &line);
	ft_printf("%s\n", line);
	save_room(&tube, (tmp = ft_strsplit(line, ' ')));
	infos->end = tube->prev;
	while (tmp[i])
	{
		free(tmp[i]);
		i++;
	}
}
