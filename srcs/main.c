/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 19:11:46 by llopez            #+#    #+#             */
/*   Updated: 2018/11/21 07:25:59 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		main(void)
{
	t_infos *infos;
	t_tube	*tube;
	t_paths	*paths;
	t_tube	**ants;
	int		i;

	i = 0;
	ants = NULL;
	if (!(tube = (t_tube *)malloc(sizeof(t_tube)))\
			|| !(paths = (t_paths *)malloc(sizeof(t_paths)))\
			|| !(infos = (t_infos *)malloc(sizeof(t_infos))))
		exit(1);
	set_tube(tube);
	infos->fourmis = 0;
	paths->steps = NULL;
	if (!read_stdin(tube, infos) || !tube->name || !infos->start || !infos->end)
		display_error(tube, paths, infos, ants);
	else
		set_research(infos, paths, ants, tube);
	free_everything(tube, infos, paths, ants);
	return (1);
}
