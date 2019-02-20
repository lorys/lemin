/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarles <pcarles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 07:06:44 by llopez            #+#    #+#             */
/*   Updated: 2019/02/20 17:42:31 by pcarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "common.h"

static void	free_rooms(t_vertice *room_list)
{
	if (!room_list)
		return ;
	free(room_list->name);
	free_paths(room_list->links);
	free_rooms(room_list->next);
	free(room_list);
}

static void	free_matrix(uint32_t **matrix, size_t size)
{
	if (matrix == NULL)
		return ;
	while (size-- > 0)
		free(matrix[size]);
	free(matrix);
}

void		free_paths(t_path *path_list)
{
	if (!path_list)
		return ;
	free_paths(path_list->next);
	free(path_list);
}

void		free_everything(t_infos *infos)
{
	free_rooms(infos->room_list);
	free_matrix(infos->adjacency_matrix, infos->room_total);
	free_matrix(infos->residual_matrix, infos->room_total);
	free(infos->parent_array);
}

void		free_char_tab(char **str)
{
	int	a;

	a = 0;
	while (str[a])
		free(str[a++]);
	free(str);
}