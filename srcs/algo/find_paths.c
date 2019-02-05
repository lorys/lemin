/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_paths.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarles <pcarles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 12:51:27 by pcarles           #+#    #+#             */
/*   Updated: 2019/02/03 20:34:09 by pcarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "lem_in.h"

/* Temporary function */
static void	print_path(t_tube **path, int size)
{
	int		i;

	i = 0;
	ft_putstr("Path    : ");
	while (i <= size)
	{
		ft_printf("%s ", path[i]->name);
		i++;
	}
	ft_putchar('\n');
}

static void	check_dead_end(t_paths *edges, t_tube *position)
{
	if (!edges->next || (((edges->next->room->vu == STATUS_DEAD_END) || (edges->room->vu == STATUS_DEAD_END)) && !edges->next->next))
	{
		if (!edges->next)
			ft_printf("Dead end: \033[31;1m%s\033[0m\n", position->name);
		else
			ft_printf("Dead end: \033[36;1m%s\033[0m\n", position->name);
		position->vu = STATUS_DEAD_END;
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
	if (position->ants == 0 || position->ants >= depth)
		position->ants = depth;
	else
	{
		printf("mabite\n");
		return (0);
	}
	
	if (position == infos->start)
	{
		/* TODO: save path (save the buffer state) */
		print_path(buf, depth);
		infos->nb_paths++;
		return (1);
	}
	edges = position->links;
	position->vu = STATUS_VISITED;
	//check_dead_end(edges, position);
	while (edges)
	{
		tmp = edges->room;
		// if (tmp == infos->start)
		// {
		// 	print_path(buf, depth);
		// 	infos->nb_paths++;
		// 	return (1);
		// }
		if (tmp->vu != STATUS_OK || tmp == position)
		{
			edges = edges->next;
			continue ;
		}
		found += explore(tmp, infos, depth + 1, buf);
		edges = edges->next;
	}
	check_dead_end(position->links, position);
	if (position->vu == STATUS_VISITED && found > 0)
		position->vu = STATUS_OK;
	return (found);
}

void		find_paths(t_infos *infos)
{
	t_tube		**res;

	if (!(res = (t_tube**)malloc(sizeof(res) * infos->room_total)))
		return ;
	explore(infos->end, infos, 0, res);
	free(res);
}