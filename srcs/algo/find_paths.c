/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_paths.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarles <pcarles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 12:51:27 by pcarles           #+#    #+#             */
/*   Updated: 2019/02/13 12:43:51 by pcarles          ###   ########.fr       */
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

t_path		*get_path(uint32_t **matrix, unsigned int start, t_infos *infos)
{
	t_path			*res;
	unsigned int	u;
	unsigned int	x;

	res = NULL;
	u = start;
	new_path(&res, infos->start->id, infos);
	new_path(&res, u, infos);
	x = 0;
	while (x < infos->room_total)
	{
		if (u == infos->end->id)
			break ;
		if (read_matrix(matrix, u, x) == 1)
		{
			new_path(&res, x, infos);
			u = x;
			if (x == infos->end->id)
				break ;
			x = 0;
			continue ;
		}
		x++;
	}
	//debug
	ft_printf("Path: ");
	while (res)
	{
		ft_printf("%s ", res->room->name);
		res = res->next;
	}
	ft_printf("\n");
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
	ft_printf("lol\n");
	return (res);
}