/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edmonds_karp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarles <pcarles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 17:08:59 by pcarles           #+#    #+#             */
/*   Updated: 2019/02/12 20:29:56 by pcarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>
#include "ft_printf.h"
#include "common.h"
#include "lem_in.h"

typedef struct		s_queue
{
	unsigned int	value;
	struct s_queue	*next;
}					t_queue;

static void	push(t_queue **queue, unsigned int value)
{
	t_queue	*new;
	t_queue	*tmp;

	new = (t_queue*)malloc(sizeof(*new));
	new->value = value;
	new->next = NULL;
	if (*queue == NULL)
	{
		*queue = new;
		return ;
	}
	tmp = *queue;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

static unsigned int	pop(t_queue **queue)
{
	unsigned int	ret;
	t_queue			*tmp;

	ret = (*queue)->value;
	tmp = (*queue)->next;
	free(*queue);
	*queue = tmp;
	return (ret);
}

static t_vertice	*find_room_by_id(t_vertice *room_list, unsigned int id)
{
	while (room_list)
	{
		if (room_list->id == id)
			return (room_list);
		room_list = room_list->next;
	}
	return (NULL);
}

void		print_path(int *parent_array, t_infos *infos)
{
	t_vertice		*cur_room;
	unsigned int	tmp;

	ft_printf("Path: %s ", infos->end->name);
	tmp = parent_array[infos->end->id];
	while (tmp != infos->start->id)
	{
		cur_room = find_room_by_id(infos->room_list, tmp);
		ft_printf("%s ", cur_room->name);
		tmp = parent_array[tmp];
	}
	ft_printf("%s\n", infos->start->name);
}

static int	bfs(t_infos *infos, uint32_t **residual_matrix, int *parent)
{
	unsigned int	i;
	unsigned int	u;
	unsigned int	v;
	t_paths			*tmp;
	t_queue			*queue;

	i = infos->room_total;
	while (--i > 0)
		parent[i] = -1;
	*parent = -1;
	parent[infos->start->id] = -2;
	queue = NULL;
	push(&queue, infos->start->id);
	while (queue != NULL)
	{
		u = pop(&queue);
		tmp = find_room_by_id(infos->room_list, u)->links;
		while (tmp)
		{
			v = tmp->room->id;
			if (parent[v] == -1 && (read_matrix(infos->adjacency_matrix, u, v) - read_matrix(residual_matrix, u, v)) > 0)
			{
				parent[v] = u;
				if (v != infos->end->id)
					push(&queue, v);
				else
					return (1);
			}
			tmp = tmp->next;
		}
	}
	return (0);
}

int			edmonds_karp(t_infos *infos)
{
	unsigned int	v;
	unsigned int	u;
	int				*parent;
	uint32_t		**residual_graph;

	if ((parent = (int *)malloc(sizeof(*parent) * infos->room_total)) == NULL)
		return (-1);
	create_matrix(&residual_graph, infos->room_total);
	while (42)
	{
		if (!bfs(infos, residual_graph, parent))
			break ;
		else
			print_path(parent, infos);
		v = infos->end->id;
		while (v != infos->start->id)
		{
			u = parent[v];
			write_matrix(residual_graph, 1, u, v);
			write_matrix(residual_graph, -1, v, u);
			v = u;
		}
		// We must check (at each iteration of the infinite loop) if that flow is sufficient for the number of ants we have to move accross the map
		//print_matrix(residual_graph, infos->room_total);
	}
	// If we don't break the loop until the end of edmonds_karp, the maximum flow is returned
	ft_printf("\n\nFlot maximum: \n");
	print_matrix(residual_graph, infos->room_total);
	free(parent);
	return (1);
}