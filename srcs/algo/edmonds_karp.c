/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edmonds_karp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarles <pcarles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 17:08:59 by pcarles           #+#    #+#             */
/*   Updated: 2019/02/10 00:07:17 by pcarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>
#include "ft_printf.h"
#include "common.h"
#include "lem_in.h"

typedef struct		s_flow
{
	uint32_t		**matrix;
	size_t			value;
}					t_flow;

typedef struct		s_queue
{
	unsigned int	value;
	struct s_queue	*next;
}					t_queue;



static void	push(t_queue **queue, unsigned int value)
{
	t_queue	*new;

	new = (t_queue*)malloc(sizeof(*new));
	new->value = value;
	new->next = *queue;
	*queue = new;
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

static int	*bfs(t_infos *infos, t_flow *residual, int *parent)
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
			if (parent[v] == -1 && read_matrix(infos->adjacency_matrix, u, v) - read_matrix(residual->matrix, u, v))
			{
				parent[v] = u;
				if (v != infos->end->id)
					push(&queue, v);
				else
					return (parent);
			}
			tmp = tmp->next;
		}
	}
	return (parent);
}

int			edmonds_karp(t_infos *infos)
{
	//unsigned int	v;
	//unsigned int	u;
	int				*parent;
	t_flow			residual_graph;

	if ((parent = (int *)malloc(sizeof(*parent) * infos->room_total)) == NULL)
		return (-1);
	residual_graph.value = 0;
	parent = bfs(infos, &residual_graph, parent);
	ft_printf("maybe\n");
	return (1);
	free(parent);
}