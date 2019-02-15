/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_paths.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarles <pcarles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 12:51:27 by pcarles           #+#    #+#             */
/*   Updated: 2019/02/15 16:51:08 by pcarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "common.h"
#include "lem_in.h"

int			new_path(t_path **path, unsigned int id, t_infos *infos)
{
	t_vertice	*tmp;
	t_path		*tmp_room;
	t_path		*new;

	if (path == NULL \
	|| (tmp = find_room_by_id(infos->room_list, id)) == NULL \
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

//debug
static void	print_path(t_path *path)
{
	ft_printf("Path :");
	while (path)
	{
		ft_printf("%s ", path->room->name);
		path = path->next;
	}
	ft_printf("\n");
}

t_path		*get_path(uint32_t **matrix, unsigned int start, t_infos *infos)
{
	t_path			*res;
	unsigned int	u;
	unsigned int	x;

	res = NULL;
	u = start;
	new_path(&res, u, infos);
	x = 0;
	while (x < infos->room_total)
	{
		if (u == infos->start->id)
			continue ;
		if (read_matrix(matrix, u, x) == 1)
		{
			write_matrix(matrix, -1, u, x);
			new_path(&res, x, infos);
			u = x;
			if (x == infos->end->id)
				break ;
			x = 0;
			continue ;
		}
		x++;
	}
	print_path(res);
	return (res);
}

t_solution		*get_paths(uint32_t **matrix, t_infos *infos)
{
	t_solution		*res;
	size_t			paths_counter;
	unsigned int	start_id;
	unsigned int	x;

	if ((res = (t_solution*)malloc(sizeof(*res))) == NULL)
		return (NULL);
	paths_counter = 0;
	start_id = infos->start->id;
	x = 0;
	while (x < infos->room_total)
	{
		if (read_matrix(matrix, start_id, x) == 1)
			paths_counter++;
		x++;
	}
	res->nb_paths = paths_counter;
	ft_printf("PATH_COUNTER: %d\n", paths_counter);
	if ((res->paths = (t_path**)malloc(sizeof(t_path*) * paths_counter)) == NULL)
	{
		free(res);
		return (NULL);
	}
	x = 0;
	paths_counter = 0;
	while (x < infos->room_total)
	{
		if (read_matrix(matrix, start_id, x) == 1)
			res->paths[paths_counter++] = get_path(matrix, x, infos);
		x++;
	}
	ft_printf("\n");
	return (res);
}