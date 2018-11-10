/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 19:11:46 by llopez            #+#    #+#             */
/*   Updated: 2018/11/10 22:14:45 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"


static void		free_list(t_tube *list)
{
	t_tube *tmp;
	
	if (!list)
		return;
	tmp = list->prev;
	printf("%s freed\n", list->name);
	free(list->name);
	free(list->links);
	free(list);
	if (tmp)
		free_list(tmp);
}

static void		display_error()
{
	write(2, "ERROR", 5);
	exit(1);
}

static void		set_tube(t_tube *tube)
{
	tube->prev = NULL;
	tube->next = NULL;
	tube->name = NULL;
	tube->to_end = 0;
	tube->x = 0;
	tube->y = 0;
	tube->vu = 0;
	tube->links = NULL;	
}

int				main(void)
{
	t_infos *infos;
	t_tube	*tube;
	t_paths	*paths;
	int		ret;
	int		i;

	i = 0;
	ret = 0;
	
	if (!(tube = (t_tube *)malloc(sizeof(t_tube)))\
			|| !(paths = (t_paths *)malloc(sizeof(t_paths)))\
			|| !(infos = (t_infos *)malloc(sizeof(t_infos))))
		exit(1);
	set_tube(tube);
	paths->steps = NULL;
	paths->base = NULL;
	if (!read_stdin(tube, infos))
		display_error();
	else
	{
		ret = find_path(infos->start, infos, infos->start, paths);
			printf("\n\n\n-------------------------------------------------\n\n\n");
			i = 0;
			while (paths->steps && paths->steps[i])
			{
				printf("> %s\n", paths->steps[i]->name);
				i++;
			}
			printf("\n\n\n-------------------------------------------------\n\n\n");
	}
	//show_struct(&tube);
	free_list(toend(tube));
	if (!ret)
		printf("Il n'y a aucun chemin menant a la fin.");
	return (0);
}
