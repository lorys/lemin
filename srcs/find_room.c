/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_room.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 22:22:35 by llopez            #+#    #+#             */
/*   Updated: 2018/11/06 22:22:55 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

t_tube	*find_room(char *name, t_tube **list)
{
	t_tube *tube;

	tube = *list;
	while (tube && tube->prev != NULL)
		tube = tube->prev;
	while (tube && tube->next != NULL && tube->name)
	{
		if (name && tube->name && !ft_strcmp(tube->name, name))
			return (tube);
		tube = tube->next;
	}
	while (tube && tube->next != NULL && tube->next->name)
		tube = tube->next;
	return (NULL);
}
