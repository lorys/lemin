/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_paths.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarles <pcarles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 12:51:27 by pcarles           #+#    #+#             */
/*   Updated: 2019/02/28 19:00:08 by pcarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "common.h"
#include "algo.h"

static int		new_path(t_path **path, unsigned int id, t_infos *infos)
{
	t_vertice	*tmp;
	t_path		*tmp_room;
	t_path		*new;

	if (path == NULL \
	|| (tmp = find_room_by_id(id, infos->room_list)) == NULL \
	|| (new = (t_path*)malloc(sizeof(*new))) == NULL)
		return (-1);
	new->room = tmp;
	new->ant = 0;
	new->next = NULL;
	if ((*path) == NULL)
	{
		*path = new;
		return (1);
	}
	tmp_room = *path;
	while (tmp_room->next)
		tmp_room = tmp_room->next;
	tmp_room->next = new;
	return (1);
}

static size_t	get_path(uint32_t **matrix, unsigned int start, t_infos *infos, t_path **pathp)
{
	size_t			path_size;
	t_path			*path;
	unsigned int	u;
	unsigned int	x;

	path_size = 1;
	path = NULL;
	u = start;
	new_path(&path, u, infos);
	x = 0;
	while (x < infos->room_total)
	{
		if (u == infos->start->id)
			continue ;
		if (read_matrix(matrix, u, x) == 1)
		{
			new_path(&path, x, infos);
			path_size++;
			u = x;
			if (x == infos->end->id)
				break ;
			x = 0;
			continue ;
		}
		x++;
	}
	*pathp = path;
	return (path_size);
}

t_solution		*get_paths(uint32_t **matrix, size_t path_counter, t_infos *infos)
{
	t_solution		*res;
	unsigned int	start_id;
	unsigned int	x;

	if ((res = (t_solution*)malloc(sizeof(*res))) == NULL)
		return (NULL);
	start_id = infos->start->id;
	res->nb_paths = path_counter;
	if ((res->paths = (t_path**)malloc(sizeof(t_path*) * path_counter)) == NULL)
	{
		free(res);
		return (NULL);
	}
	if ((res->path_size = (size_t*)malloc(sizeof(size_t) * path_counter)) == NULL)
	{
			free(res->paths);
			free(res);
			return (NULL);
	}
	x = 0;
	path_counter = 0;
	res->total_size = 0;
	while (x < infos->room_total)
	{
		if (read_matrix(matrix, start_id, x) == 1)
		{
			res->path_size[path_counter] = get_path(matrix, x, infos, &res->paths[path_counter]);
			res->total_size += res->path_size[path_counter];
			path_counter++;
		}
		x++;
	}
	return (res);
}