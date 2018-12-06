/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc_links.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 22:10:30 by llopez            #+#    #+#             */
/*   Updated: 2018/12/06 18:42:25 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		realloc_paths(t_paths *tube, t_tube *add)
{
	int	first;

	first = 0;
	if (add == NULL || tube == NULL)
		return ;
	while (tube->prev)
		tube = tube->prev;
	if (tube->room == add)
		return ;
	first = (tube->next == NULL && tube->prev == NULL && !tube->room);
	if (first)
		tube->room = add;
	else
	{
		tube->prev = (t_paths *)malloc(sizeof(t_paths));
		tube->prev->room = add;
		tube->prev->prev = NULL;
		tube->prev->next = tube;
		tube = tube->prev;
	}
	while (tube->prev)
		tube = tube->prev;
}
