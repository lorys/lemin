/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_stdin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 10:48:59 by llopez            #+#    #+#             */
/*   Updated: 2018/11/09 09:56:44 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

int		read_stdin(t_tube *tube, t_infos *infos)
{
	char	*line;
	char	**tmp;

	tmp = NULL;
	while (get_next_line(0, &line))
	{
		ft_printf("%s\n", line);
		if (ft_isdigit(line[0]) && !ft_strchr(line, ' ') &&\
				!ft_strchr(line, '-'))
			infos->fourmis = ft_atoi(line);
		else if (line[0] == '#' && line[1] != '#')
			continue;
		else if (!ft_strcmp("##start", line))
			save_start(&tube, infos);
		else if (!ft_strcmp("##end", line))
			save_end(&tube, infos);
		else if (!ft_strchr(line, '-') && ft_strchr(line, ' '))
		{
			tmp = ft_strsplit(line, ' ');
			save_room(&tube, tmp[0], ft_atoi(tmp[1]), ft_atoi(tmp[2]));
		}
		else if (ft_strchr(line, '-') && !ft_strchr(line, ' '))
			make_tube(line, tube);
	}
	return (1);
}
