/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 07:06:44 by llopez            #+#    #+#             */
/*   Updated: 2018/11/12 07:06:54 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	free_list(t_tube *list)
{
	t_tube *tmp;

	if (!list)
		return ;
	tmp = list->prev;
	free(list->name);
	free(list->links);
	free(list);
	if (tmp)
		free_list(tmp);
}
