/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 07:06:44 by llopez            #+#    #+#             */
/*   Updated: 2018/12/07 00:20:52 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	free_links(t_paths *room_list)
{
	if (!room_list)
		return ;
	free_links(room_list->next);
	free(room_list);
}

void	free_list(t_tube *room_list)
{
	if (!room_list)
		return ;
	free(room_list->name);
	free_links(room_list->links);
	free_list(room_list->next);
	free(room_list);
}

void	free_paths(t_paths *path_list)
{
	if (!path_list)
		return ;
	free_paths(path_list->next);
	free(path_list);
}
