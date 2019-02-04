/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarles <pcarles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 07:02:40 by llopez            #+#    #+#             */
/*   Updated: 2019/02/04 18:25:34 by pcarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	display_error(t_tube *tube, t_infos *infos)
{
	free_everything(tube, infos);
	write(2, "ERROR\n", 6);
	exit(EXIT_FAILURE);
}
