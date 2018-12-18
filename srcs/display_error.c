/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 07:02:40 by llopez            #+#    #+#             */
/*   Updated: 2018/12/18 15:32:41 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	display_error(t_tube *tube, t_infos *infos)
{
	free_everything(tube, infos);
	write(2, "ERROR\n", 6);
	exit(EXIT_FAILURE);
}
