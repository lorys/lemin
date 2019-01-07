/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_paths.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarles <pcarles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 12:51:27 by pcarles           #+#    #+#             */
/*   Updated: 2019/01/07 20:47:35 by pcarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "lem_in.h"

/* Temporary function */
static void	print_path(t_tube **path, int size)
{
	int		i;

	i = 0;
	ft_putstr("Path: ");
	while (i <= size)
	{
		ft_printf("%s ", path[i]->name);
		i++;
	}
	ft_putchar('\n');
}

static void	check_dead_end(t_paths *edges, t_tube *position)
{
	static int	test = 0;
	if (!edges->next || (((edges->room == position && edges->next->room->vu == 2) || (edges->room->vu == 2 && edges->next->room == position)) && !edges->next->next))
	{
		position->vu = 2;
		ft_printf("lol: %d\n", ++test);
	}
}

/* This function find ALL the possible paths (too slow) */
static int	explore(t_tube *position, t_infos *infos, int depth, t_tube **buf)
{
	t_paths	*edges;
	t_tube	*tmp;
	int		found;

	found = 0;
	buf[depth] = position;
	if (position == infos->end)
	{
		/* TODO: save path (save the buffer state) */
		print_path(buf, depth);
		return (1);
	}
	edges = position->links;
	position->vu = 1;
	check_dead_end(edges, position);
	while (edges)
	{
		tmp = edges->room;
		if (tmp->vu || tmp == position)
		{
			edges = edges->next;
			continue ;
		}
		found += explore(tmp, infos, depth + 1, buf);
		edges = edges->next;
	}
	if (position->vu == 1 && found > 0)
		position->vu = 0;
	return (found);
}

void		find_paths(t_infos *infos)
{
	t_tube		**res;

	if (!(res = (t_tube**)malloc(sizeof(res) * infos->room_total)))
		return ;
	explore(infos->start, infos, 0, res);
	free(res);
}