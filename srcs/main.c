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
	while (room)
	{
		if (room != infos->end && room->ants && !room->already_moved\
		&& ((room == infos->start && (room->to = get_minus(room, infos)))\
		|| (room != infos->start && (room->to = next_step_path(room, 1, infos)))))
			return (room);
		room = room->next;
	}
	return (NULL);
}

t_tube	*to_base(t_tube *base)
{
	while (base && base->prev)
		base = base->prev;
	return (base);
}

static void	reset_infos(t_tube *base)
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
	int	count;

	moved = 0;
	count = 0;
	base = to_base(infos->start);
	tmp = NULL;
	skip = NULL;
	while ((tmp = choose_ants(base, infos)))
	{
		if (moved)
			fill_buffer(" ", buffer, 0, infos);
		moved += change_room(infos, tmp, tmp->to, buffer);
		tmp->to = NULL;
	}
	reset_infos(base);
	if (moved && ++infos->rounds)
		fill_buffer("\n", buffer, 0, infos);
	if (choose_ants(base, infos))
		move_ants(infos, buffer);
}

int		main(int argc, char **argv)
{
	t_infos		infos;
	t_tube		*room_list;
	t_paths		*tmp;
	int		i;
	char		*buffer;

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
		if (find_paths(&infos))
		{
			while ((i = bury_path(infos.start, &infos, 1)))
			{
				if (!infos.minus_path)
					infos.minus_path = \
					path_length(last_path(&infos), &infos);
				infos.paths_nb++;
			}
			tmp = infos.start->links;
			while (tmp)
			{
				if (tmp->room->hidden)
					printf("%s (%d path length) (%d hidden) (%d steps)\n"\
				, tmp->room->name\
				, path_length(tmp->room, &infos)
				, tmp->room->hidden\
				, tmp->room->steps);
				tmp = tmp->next;
			}
			printf("%d steps\n", infos.minus_path);
			move_ants(&infos, buffer);
			fill_buffer(NULL, buffer, 1, &infos);
			printf("\n\t\t\033[41m%d ROUNDS\033[0m\n", infos.rounds);
			printf("\n%d/%d\n", infos.end->ants, infos.fourmis);
			
			printf("%d links to end.\n", ft_linkslen(infos.end));
		}
	}
	free_everything(room_list);
	return (EXIT_SUCCESS);
}
