/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_ants.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 01:04:03 by llopez            #+#    #+#             */
/*   Updated: 2018/11/30 09:53:00 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int				set_ants(t_infos *infos, t_tube ***ants, int length)
{
	int	i;

	i = 0;
	if (!((*ants) = (t_tube **)ft_memalloc(sizeof(t_tube *) * (length + 1))))
		return (0);
	(*ants)[length] = NULL;
	while (infos->fourmis >= i + 1)
		(*ants)[i++] = infos->start;
	return (1);
}
