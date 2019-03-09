/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarles <pcarles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 16:06:33 by pcarles           #+#    #+#             */
/*   Updated: 2019/03/09 02:38:11 by pcarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include <stddef.h>
#include <stdlib.h>
#include "common.h"
#include "algo.h"

static void			push(t_queue **queue, unsigned int value, int flag)
{
	t_queue	*new;
	t_queue	*tmp;

	new = (t_queue*)malloc(sizeof(*new));
	new->value = value;
	new->check_only_annulable = flag;
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

static unsigned int	pop(t_queue **queue, int *state)
{
	unsigned int	ret;
	t_queue			*tmp;

	ret = (*queue)->value;
	if (state != NULL)
		*state = (*queue)->check_only_annulable;
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
	while (index--)
	{
		tmp = 0;
		status = 0;
		while (tmp < infos->room_total)
		{
			if (read_matrix(matrix, index, tmp) == 1)
			{
				status = 1;
				break ;
			}
			tmp++;
		}
		parent_array[index] = (status == 1) ? -2 : -1;
	}
	parent_array[infos->start->id] = -3;
}

static int			bfs1(unsigned int u, unsigned int v, \
					t_algo *all, t_infos *infos)
{
	int				*parent;

	parent = infos->parent_array;
	if ((all->state == 1 && parent[v] == -2 \
		&& read_matrix(infos->residual_matrix, u, v) == -1)
		|| (all->state == 0 && ((parent[v] == -1 || parent[v] == -2) \
		&& (read_matrix(infos->adjacency_matrix, u, v) - \
		read_matrix(infos->residual_matrix, u, v)) > 0)))
	{
		if (parent[v] == -2 && read_matrix(infos->residual_matrix, u, v) == 0)
			push(&all->queue, v, 1);
		else if (v != infos->end->id)
			push(&all->queue, v, 0);
		else
		{
			parent[v] = u;
			while (all->queue != NULL)
				pop(&all->queue, NULL);
			return (1);
		}
		parent[v] = u;
	}
	return (0);
}

int					bfs(t_infos *infos, uint32_t **residual_matrix, int *parent)
{
	unsigned int	u;
	unsigned int	v;
	t_path			*tmp;
	t_algo			all;

	all.state = 0;
	fill_parent_array(parent, residual_matrix, infos);
	all.queue = NULL;
	push(&all.queue, infos->start->id, 0);
	while (all.queue != NULL)
	{
		u = pop(&all.queue, &all.state);
		tmp = find_room_by_id(u, infos->room_list)->links;
		while (tmp)
		{
			v = tmp->room->id;
			if (bfs1(u, v, &all, infos) == 1)
				return (1);
			tmp = tmp->next;
		}
	}
	return (0);
}
