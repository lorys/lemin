/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 19:11:46 by llopez            #+#    #+#             */
/*   Updated: 2018/11/09 17:02:21 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

static void		set_tube(t_tube *tube)
{
	tube->prev = NULL;
	tube->next = NULL;
	tube->name = NULL;
	tube->x = 0;
	tube->y = 0;
	tube->vu = 0;
	tube->links = NULL;	
}

int				main(void)
{
	t_infos *infos;
	t_tube	*tube;
	t_tube	*paths;
	int		ret;
	int		i;

	i = 0;
	ret = 0;
	paths = (t_tube *)malloc(sizeof(t_tube));
	tube = (t_tube *)malloc(sizeof(t_tube));
	set_tube(tube);
	set_tube(paths);
	infos = (t_infos *)malloc(sizeof(t_infos));
	read_stdin(tube, infos);
	printf("start = %s\nend = %s\n", infos->start->name, infos->end->name);
	ret = find_path(infos->start, infos, infos->start, paths);

	while (paths->prev)
		paths = paths->prev;
	while (paths)
	{
		printf("\n\n\n-------------------------------------------------\n\n\n");
		while (paths->links && paths->links[i])
		{
			printf("> %s\n", paths->links[i]->name);
			i++;
		}
		paths = paths->next;
		printf("\n\n\n-------------------------------------------------\n\n\n");
	}
	if (!ret)
		printf("Il n'y a aucun chemin menant a la fin.");
	//show_struct(&tube);
	return (0);
}
