/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_ants.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 01:04:03 by llopez            #+#    #+#             */
/*   Updated: 2018/11/12 07:22:36 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int				set_ants(t_infos *infos, t_tube ***ants)
{
	int	i;

	i = 0;
	if (!((*ants) = (t_tube **)malloc(sizeof(t_tube *) * (infos->fourmis + 1))))
		return (0);
	(*ants)[infos->fourmis] = NULL;
	while (infos->fourmis >= i + 1)
		(*ants)[i++] = infos->start;
	return (1);
}
