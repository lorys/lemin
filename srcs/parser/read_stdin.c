/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_stdin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 10:48:59 by llopez            #+#    #+#             */
/*   Updated: 2018/11/24 19:37:38 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		check_start(char *line, t_infos *infos, t_tube **tube)
{
	if (!ft_strcmp("##start", line))
	{
		if (!save_start(tube, infos))
		{
			free(line);
			return (-1);
		}
		return (1);
	}
	return (0);
}

int		new_room(char *line, t_tube **tube)
{
	char **tmp;

	tmp = NULL;
	if (!ft_strchr(line, '-') && ft_strchr(line, ' ') && \
			check_room(line))
	{
		tmp = ft_strsplit(line, ' ');
		if (!save_room(tube, tmp[0], ft_atoi(tmp[1]), ft_atoi(tmp[2])))
		{
			free(line);
			free_char_tab(tmp);
			return (-1);
		}
		free_char_tab(tmp);
		return (1);
	}
	return (0);
}

int		check_tube(char *line, t_tube *tube)
{
	if (ft_strchr(line, '-') && !ft_strchr(line, ' '))
	{
		make_tube(line, tube);
		return (1);
	}
	return (0);
}

int		check_line(t_tube *tube, t_infos *infos)
{
	char	*line;
	int		ret;

	line = NULL;
	while (get_next_line(0, &line) > 0)
	{
		ret = 0;
		ft_printf("%s\n", line);
		if (line[0] == '#' && line[1] != '#' && int_free(line))
			continue;
		ret += (ret == 0) ? check_ants(line, infos) : 0;
		ret += (ret == 0) ? check_start(line, infos, &tube) : 0;
		ret += (ret == 0) ? check_end(line, infos, &tube) : 0;
		ret += (ret == 0) ? new_room(line, &tube) : 0;
		ret += (ret == 0) ? check_tube(line, tube) : 0;
		if (line[0] == '#' && line[1] == '#' && int_free(line))
			continue;
		else if (line[0] == '\0' && int_free(line))
			break ;
		else if ((ret == -1 || ret == 0) && int_free(line))
			return (0);
		free(line);
	}
	if (line)
		free(line);
	return (1);
}

int		read_stdin(t_tube *tube, t_infos *infos)
{
	if (!check_line(tube, infos))
		return (0);
	write(1, "\n", 1);
	if (infos->fourmis <= 0)
		return (0);
	return (1);
}
