/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_paths.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarles <pcarles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 12:51:27 by pcarles           #+#    #+#             */
/*   Updated: 2019/03/18 16:08:50 by pcarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "common.h"
#include "algo.h"

static int			new_path(t_path **path, unsigned int id, t_infos *infos)
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

static void			init_vars(size_t *path_size, t_path **path, unsigned int *x)
{
	*path_size = 1;
	*path = NULL;
	*x = 0;
}

static size_t		get_path(uint32_t **matrix, unsigned int start, \
					t_infos *infos, t_path **pathp)
{
	size_t			path_size;
	t_path			*path;
	unsigned int	u;
	unsigned int	x;

	init_vars(&path_size, &path, &x);
	u = start;
	new_path(&path, u, infos);
	while (x < infos->room_total)
	{
		if (u == infos->start->id)
			continue ;
		if (read_matrix(matrix, u, x) == 1 && ++path_size)
		{
			new_path(&path, x, infos);
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

static t_solution	*alloc_solution(size_t path_c)
{
	t_solution	*res;

	if ((res = (t_solution*)malloc(sizeof(*res))) == NULL)
		return (NULL);
	res->nb_paths = path_c;
	if ((res->paths = (t_path**)malloc(sizeof(t_path*) * path_c)) == NULL)
	{
		free(res);
		return (NULL);
	}
	if ((res->path_size = (size_t*)malloc(sizeof(size_t) * path_c)) \
		== NULL)
	{
		free(res->paths);
		free(res);
		return (NULL);
	}
	if ((res->nb_ants = (size_t*)malloc(sizeof(size_t) * path_c)) == NULL)
	{
		free(res->path_size);
		free(res->paths);
		free(res);
		return (NULL);
	}
	return (res);
}

t_solution			*get_paths(uint32_t **matrix, \
					size_t path_counter, t_infos *infos)
{
	t_solution		*res;
	unsigned int	start_id;
	unsigned int	x;

	start_id = infos->start->id;
	if ((res = alloc_solution(path_counter)) == NULL)
		return (NULL);
	x = 0;
	path_counter = 0;
	while (x < infos->room_total)
	{
		if (read_matrix(matrix, start_id, x) == 1)
		{
			res->path_size[path_counter] = get_path(matrix, x, infos, \
				&res->paths[path_counter]);
			path_counter++;
		}
		x++;
	}
	if (res->path_size[0] == 1 && res->nb_paths == 1)
		res->is_start_end = 1;
	else
		res->is_start_end = 0;
	sort_solution(res);
	return (res);
}
