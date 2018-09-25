/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 19:11:46 by llopez            #+#    #+#             */
/*   Updated: 2018/09/25 18:45:35 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

t_tube	*find_room(char *name, t_tube *tube)
{
	while (tube->prev != NULL)
		tube = tube->prev;
	while (tube->next != NULL)
	{
		if (!ft_strcmp(tube->name, name))
			return (tube);
		tube = tube->next;
	}
	return (NULL);
}

int		main(int argc, char **argv)
{
	char	*line;
	char	**starting_room;
	char	**ending_room;
	t_tube	*tube;
	char	**split_tmp;

	tube = malloc(sizeof(t_tube));
	tube->prev = NULL;
	while (get_next_line(0, &line))
	{
		if (line[0] == '#' && line[1] != '#')
			continue;
		else if (!ft_strcmp("##start", line))
		{
			get_next_line(0, &line);
			starting_room = ft_strsplit(line, ' ');
		}
		else if (!ft_strcmp("##end", line))
		{
			get_next_line(0, &line);
			ending_room = ft_strsplit(line, ' ');
		}
		else if (!ft_strchr(line, '-') && ft_strchr(line, ' '))
		{
			split_tmp = ft_strsplit(line, ' ');
			tube->name = split_tmp[0];
			tube->x = ft_atoi(split_tmp[1]);
			tube->y = ft_atoi(split_tmp[2]);
			tube->next = malloc(sizeof(t_tube));
			tube->next->prev = tube;
			tube->next->next = NULL;
			tube = tube->next;
		}
		else if (ft_strchr(line, '-') && !ft_strchr(line, ' '))
		{
			split_tmp = ft_strsplit(line, '-');
			find_room(split_tmp[0], tube)->links;
		}
		free(line);
	}
	tube->next = NULL;
	printf("starting room : %s\nending room : %s\n", starting_room[0], ending_room[0]);
	while (tube->prev != NULL)
		tube = tube->prev;
	while (tube->next != NULL)
	{
		printf("room : %s\n x : %d\n y : %d\n", tube->name, tube->x, tube->y);
		tube = tube->next;
	}
	return (0);
}
