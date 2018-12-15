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
	int			flag;
	t_tube		*to_place;
	t_tube		*cur_room;

	tmp = 0;
	flag = 1;
	to_place = NULL;
	while (path_list && flag)
	{
		cur_room = path_list->room;
		if (cur_room == infos->start)
			ant++;
		else if (cur_room == infos->end)
		{
			infos->end->ants++;
			tmp = 0;
			flag = 0;
		}
		else if (tmp && cur_room->ants)
			swap(&tmp, &cur_room->ants);
		else if (tmp)
		{
			cur_room->ants = tmp;
			tmp = 0;
		}
		else if (cur_room->ants)
		{
			to_place = cur_room;
			tmp = cur_room->ants;
		}
		else if (to_place)
		{
			cur_room = to_place;
			to_place = NULL;
			cur_room->ants = ant;
			flag = 0;
		}
		else
		{
			flag = 0;
			cur_room->ants = ant;
		}
		if (cur_room != infos->start)
			ft_printf("L%d-%s ", cur_room->ants, cur_room->name);
		path_list = path_list->next;
	}
	ft_putchar('\n');
	infos->rounds++;
	return (ant);
}

// int				make_line(t_paths *path_list, t_infos *infos, int ant)
// {
// 	int			tmp;
// 	t_tube		*to_place;

// 	tmp = 0;
// 	to_place = NULL;
// 	while (path_list)
// 	{
// 		if (path_list->room == infos->start)
// 		{
// 			path_list = path_list->next;
// 			ant++;
// 			continue ;
// 		}
// 		else if (path_list->room == infos->end)
// 		{
// 			infos->end->ants++;
// 			ft_printf("L%d-%s", tmp, path_list->room->name);
// 			tmp = 0;
// 			path_list = path_list->next;
// 			continue ;
// 		}
// 		else if (tmp && path_list->room->ants)
// 			swap(&tmp, &path_list->room->ants);
// 		else if (tmp)
// 		{
// 			path_list->room->ants = tmp;
// 			tmp = 0;
// 		}
// 		else if (path_list->room->ants)
// 		{
// 			tmp = path_list->room->ants;
// 			to_place = path_list->room;
// 		}
// 		else if (!tmp && to_place)
// 		{
// 			to_place->ants = ant;
// 			ft_printf("L%d-%s", to_place->ants, to_place->name);
// 			to_place = NULL;
// 		}
// 		else
// 		{
// 			if (to_place)
// 				to_place->ants = ant;
// 			else
// 				path_list->room->ants = ant;
// 		}
// 		ft_printf("L%d-%s", path_list->room->ants, path_list->room->name);
// 		path_list = path_list->next;
// 		ft_putchar(' ');
// 	}
// 	ft_putchar('\n');
// 	infos->rounds++;
// 	return (ant++);
// }
