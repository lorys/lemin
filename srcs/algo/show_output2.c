/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_output2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarles <pcarles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 10:41:46 by pcarles           #+#    #+#             */
/*   Updated: 2019/03/16 20:11:30 by pcarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct/path.h"
#include "algo.h"

t_path		*get_next_path(t_solution *solution)
{
	static size_t	last_path = 0;

	if (last_path >= solution->nb_paths)
		last_path = 0;
	return (solution->paths[last_path++]);
}
