/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_everything.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 07:05:15 by llopez            #+#    #+#             */
/*   Updated: 2019/02/04 00:35:13 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	free_everything(t_tube *room_list, t_infos *infos)
{
	free_list(room_list);
	free(infos);
}

t_tube	*to_base(t_tube *base)
{
	while (base && base->prev)
		base = base->prev;
	return (base);
}
