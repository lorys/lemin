/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarles <pcarles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 19:11:46 by llopez            #+#    #+#             */
/*   Updated: 2019/02/03 15:41:27 by pcarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "common.h"
#include "parser.h"
#include "lem_in.h"

static	void	bonus_manager(int argc, char **argv, t_infos *infos)
{
	int			i;

	i = 0;
	infos->select = -1;
	infos->bonus = 0;
	while (argc > i)
	{
		if (!ft_strcmp(argv[i], "-colors"))
			infos->bonus = 1;
		if (!ft_strcmp(argv[i], "-select") && argv[i + 1])
			infos->select = ft_atoi(argv[i + 1]);
		if (!ft_strcmp(argv[i], "-ants") && argv[i + 1])
			infos->bonusants = ft_atoi(argv[i + 1]);
		i++;
	}
}

t_tube		*choose_ants(t_tube *room, t_infos *infos)
{
	t_tube	*minus_room;

	minus_room = NULL;
	if (get_minus(infos->start, infos))
		return (infos->start);
	while (room)
	{
		if (get_minus(room, infos))
			return (room);
		room = room->next;
	}
	return (minus_room);
}

t_tube	*to_base(t_tube *base)
{
	while (base && base->prev)
		base = base->prev;
	return (base);
}

static void			reset_infos(t_tube *base)
{
	while (base)
	{
		base->already_moved = 0;
		base = base->next;
	}
}

void		move_ants(t_infos *infos, char *buffer)
{
	t_tube	*tmp;
	t_tube	*skip;
	int	moved;
	t_tube	*base;

	moved = 0;
	base = to_base(infos->start);
	tmp = NULL;
	skip = NULL;
	while ((tmp = choose_ants(base, infos)))
	{
		printf("ant choosen : %d\n", tmp->ants);
		if (tmp->ants && !tmp->already_moved && (skip = get_minus(tmp, infos)))
		{
			if (moved)
				fill_buffer(" ", buffer, 0, infos);
			moved += change_room(infos, tmp, skip, buffer);
		}
		tmp = (!get_minus(tmp, infos)) ? tmp->next : tmp;
	}
	reset_infos(base);
	if (moved && ++infos->rounds)
		fill_buffer("\n", buffer, 0, infos);
	if (infos->end->ants < infos->fourmis)
		move_ants(infos, buffer);
}

int		main(int argc, char **argv)
{
	t_infos		infos;
	t_tube		*room_list;
	int		i;
	char		*buffer;
	//t_tube		*tmp;
	//t_paths		*paths_tmp;

	i = 0;
	buffer = NULL;
	init_infos(&infos);
	room_list = NULL;
	bonus_manager(argc, argv, &infos);
	read_stdin(&room_list, &infos);
	if (!room_list || !infos.start || !infos.end || infos.fourmis <= 0)
		display_error(room_list);
	else
	{
		buffer = malloc(sizeof(char) * BUFFER_SIZE);
		infos.start->ants = infos.fourmis;
		find_paths(&infos);
		while (room_list)
		{
			if (room_list->steps)
			{
				i++;
				printf("%s\t(%d steps)\n", room_list->name, room_list->steps);
			}
			room_list = room_list->next;
		}
		printf("%d rooms used\n", i);
		move_ants(&infos, buffer);
	}
	free_everything(room_list);
	return (EXIT_SUCCESS);
}
