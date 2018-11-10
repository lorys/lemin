/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_stdin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 10:48:59 by llopez            #+#    #+#             */
/*   Updated: 2018/11/10 11:54:28 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

int		ft_strisdigit(char *str)
{
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

int		check_room(char *line)
{
	char	**tmp;
	int		i;

	i = 0;
	tmp = ft_strsplit(line, ' ');
	while (tmp[i])
		i++;
	if (i != 3 || tmp[0][0] == 'L' || tmp[0][0] == '#' || !ft_strisdigit(tmp[1])\
			|| !ft_strisdigit(tmp[2]))
		return (0);
	return (1);
}

int		int_free(void *data)
{
	free(data);
	return (1);
}

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
		{
			if (!save_start(&tube, infos) && int_free(line))
				return (0);
		}
		else if (!ft_strcmp("##end", line))
			save_end(&tube, infos);
		else if (!ft_strchr(line, '-') && ft_strchr(line, ' ') && check_room(line))
		{
			tmp = ft_strsplit(line, ' ');
			save_room(&tube, tmp[0], ft_atoi(tmp[1]), ft_atoi(tmp[2]));
		}
		else if (ft_strchr(line, '-') && !ft_strchr(line, ' '))
			make_tube(line, tube);
		else if (line[0] == '#' && line[1] == '#')
			continue;
		else
		{
			free(line);
			return (0);
		}
		free(line);
	}
	return (1);
}
