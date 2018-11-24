/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 15:17:38 by llopez            #+#    #+#             */
/*   Updated: 2018/11/24 15:18:20 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

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
	if (i != 3 || tmp[0][0] == 'L' || tmp[0][0] == '#'\
			|| !ft_strisdigit(tmp[1]) || !ft_strisdigit(tmp[2]))
	{
		free_char_tab(tmp);
		return (0);
	}
	free_char_tab(tmp);
	return (1);
}

int		int_free(void *data)
{
	free(data);
	return (1);
}

int		check_ants(char *line, t_infos *infos)
{
	if (ft_isdigit(line[0]) && !ft_strchr(line, ' ') &&\
				!ft_strchr(line, '-'))
	{
		infos->fourmis = ft_atoi(line);
		return (1);
	}
	return (0);
}

int		check_end(char *line, t_infos *infos, t_tube **tube)
{
	if (!ft_strcmp("##end", line))
	{
		if (!save_end(tube, infos))
		{
			free(line);
			return (-1);
		}
		return (1);
	}
	return (0);
}
