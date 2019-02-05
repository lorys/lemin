/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarles <pcarles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 07:06:44 by llopez            #+#    #+#             */
/*   Updated: 2019/01/07 19:54:04 by pcarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "common.h"

static void	free_paths(t_paths *path_list)
{
	if (!path_list)
		return ;
	free_paths(path_list->next);
	free(path_list);
}

static void	free_rooms(t_tube *room_list)
{
	if (!room_list)
		return ;
	free(room_list->name);
	free_paths(room_list->links);
	free_rooms(room_list->next);
	free(room_list);
}

void		free_everything(t_tube *room_list)
{
	while (room_list && room_list->prev)
		room_list = room_list->prev;
	free_rooms(room_list);
}

void		free_char_tab(char **str)
{
	int	a;

	a = 0;
	while (str[a])
		free(str[a++]);
	free(str);
}