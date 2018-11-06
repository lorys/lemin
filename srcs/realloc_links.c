/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc_links.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 22:10:30 by llopez            #+#    #+#             */
/*   Updated: 2018/11/06 22:10:55 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

t_tube	**realloc_links(t_tube *tube, t_tube *add)
{
	int length;
	t_tube **links_tmp;

	length = 0;
	while (tube->links && tube->links[length])
		length++;
	links_tmp = malloc(sizeof(t_tube) * (length + 2));
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
