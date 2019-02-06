/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarles <pcarles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 05:40:44 by pcarles           #+#    #+#             */
/*   Updated: 2019/02/05 18:09:01 by pcarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"
#include "get_next_line.h"
#include "parser.h"

int				parse(t_vertice **room_listp, t_infos *infos)
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
