/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_output.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarles <pcarles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 16:01:01 by pcarles           #+#    #+#             */
/*   Updated: 2019/02/15 20:51:07 by pcarles          ###   ########.fr       */
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

static int		push_ants(t_path *path, unsigned int new_ant)
{
	int				ret;
	unsigned int	tmp;

	ret = 0;
	while (path)
	{
		tmp = path->ant;
		path->ant = new_ant;
		if (new_ant != 0)
		{
			ft_printf("L%d-%s ", new_ant, path->room->name);
			ret++;
		}
		new_ant = tmp;
		path = path->next;
	}
	return (ret);
}

void			show_output(t_solution *solution, size_t nb_ants, int display_rounds)
{
	unsigned int	rounds;
	unsigned int	status;
	unsigned int	next_ant;
	t_path			*next_path;

	rounds = 0;
	status = 0;
	next_ant = 1;
	next_path = get_next_path(solution);
	while (42)
	{
		status += push_ants(next_path, next_ant);
		next_path = get_next_path(solution);
		if (next_path == solution->paths[0])
		{
			ft_printf("\n");
			if (status == 0)
				break ;
			rounds++;
			status = 0;
		}
		if (next_ant == 0)
			continue ;
		if (next_ant < nb_ants)
			next_ant++;
		else
			next_ant = 0;
	}
	if (display_rounds == 1)
		ft_printf("%d rounds\n", rounds);
}