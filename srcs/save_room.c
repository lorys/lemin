/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_room.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 22:11:45 by llopez            #+#    #+#             */
/*   Updated: 2018/11/09 09:55:14 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

void	save_room(t_tube **tube, char *name, int x, int y)
{
	if (find_room(name, tube))
		return;
	(*tube)->name = name;
	(*tube)->x = x;
	(*tube)->y = y;
	(*tube)->vu = 0;
	(*tube)->links = NULL;
	if (!((*tube)->next = malloc(sizeof(t_tube))))
		exit(0);
	(*tube)->next->prev = (*tube);
	(*tube)->next->name = NULL;
	(*tube)->next->next = NULL;
	(*tube) = (*tube)->next;
}
