/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 19:11:46 by llopez            #+#    #+#             */
/*   Updated: 2018/09/29 22:40:57 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

t_tube	**realloc_links(t_tube *tube, t_tube *add)
{
	int length;
	t_tube **links_tmp;

	length = 0;
	while (tube->links && tube->links[length])
		length++;
	links_tmp = malloc(sizeof(t_tube) * length + 2);
	links_tmp[length + 1] = NULL;
	links_tmp[length] = add;
	while (length)
	{
		length--;
		links_tmp[length] = tube->links[length];
		free(tube->links[length]);
	}
	free(tube->links);
	return (links_tmp);
}

t_tube	*find_room(char *name, t_tube *tube)
{
	while (tube && tube->prev != NULL)
		tube = tube->prev;
	while (tube && tube->next != NULL)
	{
		if (name && tube->name && !ft_strcmp(tube->name, name))
			return (tube);
		tube = tube->next;
	}
	return (NULL);
}

void	save_room(t_tube **tube, char **split_tmp)
{
	(*tube)->name = split_tmp[0];
	(*tube)->x = ft_atoi(split_tmp[1]);
	(*tube)->y = ft_atoi(split_tmp[2]);
	(*tube)->links = NULL;
	if (!((*tube)->next = malloc(sizeof(t_tube))))
		exit(0);
	(*tube)->next->prev = (*tube);
	(*tube)->next->next = NULL;
	(*tube) = (*tube)->next;
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
	tube->next = NULL;
	tube->name = NULL;
	tube->x = 0;
	tube->y = 0;
	tube->links = NULL;
	while (get_next_line(0, &line))
	{
		ft_printf("%s\n", line);
		if (line[0] == '#' && line[1] != '#')
			continue;
		else if (!ft_strcmp("##start", line))
		{
			get_next_line(0, &line);
			starting_room = ft_strsplit(line, ' ');
			if (!find_room(starting_room[0], tube))
				save_room(&tube, starting_room);
		}
		else if (!ft_strcmp("##end", line))
		{
			get_next_line(0, &line);
			ending_room = ft_strsplit(line, ' ');
			if (!find_room(ending_room[0], tube))
				save_room(&tube, ending_room);
		}
		else if (!ft_strchr(line, '-') && ft_strchr(line, ' '))
		{
			printf("ho lord !\n");
			split_tmp = ft_strsplit(line, ' ');
			save_room(&tube, split_tmp);
		}
		else if (ft_strchr(line, '-') && !ft_strchr(line, ' '))
		{
			split_tmp = ft_strsplit(line, '-');
			if (find_room(split_tmp[0], tube) && find_room(split_tmp[1], tube))
			{
				printf("adding room 1\n");
				printf("adding room 2\n");
				find_room(split_tmp[0], tube)->links = realloc_links(find_room(split_tmp[0], tube), find_room(split_tmp[1], tube));
				find_room(split_tmp[1], tube)->links = realloc_links(find_room(split_tmp[1], tube), find_room(split_tmp[0], tube));
				printf("adding room finished\n");
			}
		}
		free(line);
	}
	printf("starting room : %s\nending room : %s\n", starting_room[0], ending_room[0]);
	printf("\n\ntube = %s\n", tube->name);
	while (tube->prev != NULL)
		tube = tube->prev;
	while (tube->next != NULL)
	{
		printf("room : %s\n x : %d\n y : %d\n", tube->name, tube->x, tube->y);
		while (tube->(*links))
		{
			printf("	---->%s\n", tube->links->name);
			tube->(*links)++;
		}
		tube = tube->next;
	}
	return (0);
}
