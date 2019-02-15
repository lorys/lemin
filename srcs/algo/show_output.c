/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_output.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarles <pcarles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 16:01:01 by pcarles           #+#    #+#             */
/*   Updated: 2019/02/15 16:41:20 by pcarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "ft_printf.h"
#include "common.h"

static t_path	*get_next_path(t_solution *solution)
{
	static size_t	last_path = 0;

	if (last_path >= solution->nb_paths)
		last_path = 0;
	return (solution->paths[last_path++]);
}

static void		push_ants(t_path *path, unsigned int new_ant)
{
	unsigned int	tmp;

	while (path && new_ant > 0)
	{
		tmp = path->ant;
		path->ant = new_ant;
		ft_printf("L%d-%s ", new_ant, path->room->name);
		new_ant = tmp;
		path = path->next;
	}
}

void			show_output(t_solution *solution, size_t nb_ants)
{
	unsigned int	next_ant;
	t_path			*next_path;

	next_ant = 1;
	next_path = get_next_path(solution);
	while (next_ant <= nb_ants)
	{
		push_ants(next_path, next_ant);
		next_path = get_next_path(solution);
		if (next_path == solution->paths[0])
			ft_printf("\n");
		next_ant++;
	}
}