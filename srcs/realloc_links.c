/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc_links.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 22:10:30 by llopez            #+#    #+#             */
/*   Updated: 2018/11/27 06:04:09 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_tube		**realloc_links(t_tube *tube, t_tube *add)
{
	int		length;
	t_tube	**links_tmp;

	length = 0;
	if (!add || !tube)
		return (NULL);
	while (tube->links && tube->links[length])
		length++;
	links_tmp = (t_tube **)malloc(sizeof(t_tube) * (length + 2));
	links_tmp[length + 1] = NULL;
	links_tmp[length] = add;
	length = 0;
	while (tube->links && tube->links[length])
	{
		links_tmp[length] = tube->links[length];
		length++;
	}
	free(tube->links);
	return (links_tmp);
}

void		realloc_paths(t_paths *tube, t_tube *add)
{
	int	first;

	first = 0;
	if (add == NULL || tube == NULL)
		return;
	first = (tube->next == NULL && tube->prev == NULL);
	tube->prev = (t_paths *)malloc(sizeof(t_paths));
	if (first)
		tube->room = add;
	else
		tube->prev->room = add;
	tube->prev->prev = NULL;
	tube->prev->next = tube;
}
