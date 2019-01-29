/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarles <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 05:40:44 by pcarles           #+#    #+#             */
/*   Updated: 2018/11/30 05:40:47 by pcarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "parser.h"

int				parse(t_tube **room_listp, t_infos *infos)
{
	char		*line;
	int			nline;
	int			ret;

	line = NULL;
	nline = 0;
	while (get_next_line(0, &line) > 0 && ++nline)
	{
		if (*line == '\0')
			break ;
		ret = line_is_valid(room_listp, infos, line, nline);
		if (!ret)
			break ;
		ft_strdel(&line);
	}
	ft_strdel(&line);
	return (1);
}