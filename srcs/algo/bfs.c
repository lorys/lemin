/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarles <pcarles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 16:06:33 by pcarles           #+#    #+#             */
/*   Updated: 2019/02/19 18:49:26 by pcarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include "common.h"
#include "algo.h"

static void			push(t_queue **queue, unsigned int value)
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

static void			fill_parent_array(int *parent_array, uint32_t **matrix, \
					t_infos *infos)
{
	unsigned int	index;
	unsigned int	tmp;
	unsigned int	status;

	index = infos->room_total;
	tmp = 0;
	status = 0;
	while (index--)
	{
		while (tmp < infos->room_total)
		{
			if (read_matrix(matrix, index, tmp) == 1)
			{
				status = 1;
				break ;
			}
			tmp++;
		}
		tmp = 0;
		parent_array[index] = status == 1 ? -2 : -1;
		status = 0;
	}
}

int					bfs(t_infos *infos, uint32_t **residual_matrix, int *parent)
{
	unsigned int	u;
	unsigned int	v;
	t_path			*tmp;
	t_queue			*queue;

	fill_parent_array(parent, residual_matrix, infos);
	parent[infos->start->id] = -3;
	queue = NULL;
	push(&queue, infos->start->id);
	while (queue != NULL)
	{
		u = pop(&queue);
		tmp = find_room_by_id(u, infos->room_list)->links;
		while (tmp)
		{
			v = tmp->room->id;
			if ((parent[v] == -1 && (read_matrix(infos->adjacency_matrix, u, v) - read_matrix(residual_matrix, u, v)) > 0) \
			|| (parent[v] == -2 && read_matrix(residual_matrix, u, v) == -1))
			{
				parent[v] = u;
				if (v != infos->end->id)
					push(&queue, v);
				else
				{
					while (queue != NULL)
						pop(&queue);
					return (1);
				}
			}
			tmp = tmp->next;
		}
	}
	return (0);
}
