/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_room.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 22:11:45 by llopez            #+#    #+#             */
/*   Updated: 2018/11/08 17:09:51 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

void	save_room(t_tube **tube, char **split_tmp)
{
	if (find_room(split_tmp[0], tube))
		return;
	(*tube)->name = split_tmp[0];
	(*tube)->x = ft_atoi(split_tmp[1]);
	(*tube)->y = ft_atoi(split_tmp[2]);
	(*tube)->vu = 0;
	(*tube)->links = NULL;
	if (!((*tube)->next = malloc(sizeof(t_tube))))
		exit(0);
	(*tube)->next->prev = (*tube);
	(*tube)->next->name = NULL;
	(*tube)->next->next = NULL;
	(*tube) = (*tube)->next;
}
