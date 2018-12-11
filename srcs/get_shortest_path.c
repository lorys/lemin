/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_shortest_path.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 05:19:09 by llopez            #+#    #+#             */
/*   Updated: 2018/12/07 07:17:21 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

// static void		set_next(t_next **choice, int *steps, t_tube *room)
// {
// 	(*choice)->steps = *steps;
// 	(*choice)->room = room;
// 	*steps = 0;
// }

// static t_tube	*choose_path(t_next *shortest, t_next *possible, t_infos *infos)
// {
// 	t_tube *tmp;

// 	tmp = NULL;
// 	if (!shortest || !possible)
// 		return (NULL);
// 	(void)infos;
// 	if (shortest->room && !shortest->room->ants)
// 		tmp = shortest->room;
// 	if (possible->room && !tmp && possible->steps != -1\
// 			&& possible->steps < shortest->steps*2)
// 		tmp = possible->room;
// 	free(possible);
// 	free(shortest);
// 	return (tmp);
// }

// static void		init_next(t_next **possible, t_next **shortest)
// {
// 	(*possible) = (t_next *)malloc(sizeof(t_next));
// 	(*shortest) = (t_next *)malloc(sizeof(t_next));
// 	(*possible)->steps = INT_MAX;
// 	(*possible)->room = NULL;
// 	(*shortest)->steps = INT_MAX;
// 	(*shortest)->room = NULL;
// }

// static int		get_distance(t_paths *paths, t_tube *from)
// {
// 	int	i;

// 	i = 0;
// 	if (!paths)
// 		return (-1);
// 	while (paths && paths->room != from)
// 	{
// 		i++;
// 		paths = paths->next;
// 	}
// 	return (i);
// }

static void		swap(int *a, int *b)
{
	int			tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int				make_line(t_paths *path_list, t_infos *infos, int ant)
{
	int			tmp;

	tmp = 0;
	while (path_list)
	{
		if (path_list->room == infos->start)
			ant++;
		else if (path_list->room == infos->end)
			infos->end->ants++;
		else if (tmp && path_list->room->ants)
		{
			swap(&tmp, &path_list->room->ants);
		}
		else if (tmp)
		{
			path_list->room->ants = tmp;
			tmp = 0;
		}
		else if (path_list->room->ants)
			tmp = path_list->room->ants;
		else
			path_list->room->ants = ant;
		ft_printf("L%d-%s ", path_list->room->ants, path_list->room->name);
		if (tmp)
			path_list = path_list->next;
		else
			break ;
	}
	ft_putchar('\n');
	return (ant);
}
