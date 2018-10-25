/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 19:11:46 by llopez            #+#    #+#             */
/*   Updated: 2018/10/25 17:15:57 by llopez           ###   ########.fr       */
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
	links_tmp = malloc(sizeof(t_tube) * (length + 2));
	links_tmp[length + 1] = NULL;
	links_tmp[length] = add;
	length = 0;
	while (tube->links && tube->links[length])
	{
		links_tmp[length] = tube->links[length];
		length++;
	}
	free(tube->links);
	return (links_tmp);
}

void	show_struct(t_tube **tube)
{
	int	i;

	i = 0;
	printf("addr = %p\n", (*tube));
	printf("nom = %s\n", (*tube)->name);
	printf("x = %d\n", (*tube)->x);
	printf("y = %d\n", (*tube)->y);
	while ((*tube)->links && (*tube)->links[i]) {
		printf("\tliens === %s\n", (*tube)->links[i]->name);
		i++;
	}
	printf("prev = %p\n", (*tube)->prev);
	printf("next = %p\n", (*tube)->next);
	printf("------------------------------\n");
	if ((*tube)->next && (*tube)->next->name)
		show_struct(&(*tube)->next);
}

t_tube	*find_room(char *name, t_tube **list)
{
	t_tube *tube;

	tube = *list;
	while (tube && tube->prev != NULL)
		tube = tube->prev;
	while (tube && tube->next != NULL && tube->next->name)
	{
		if (name && tube->name && !ft_strcmp(tube->name, name))
			return (tube);
		tube = tube->next;
	}
	while (tube && tube->next != NULL && tube->next->name)
		tube = tube->next;
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
	(*tube)->next->name = NULL;
	(*tube)->next->next = NULL;
	(*tube) = (*tube)->next;
}

int		count_room(t_tube *tube, t_tube *start, t_tube *end)
{
	while (tube->next && tube->next->name)
	{
		
	}
}

int		main(int argc, char **argv)
{
	char	*line;
	char	**starting_room;
	char	**ending_room;
	t_tube	*tube;
	char	**split_tmp;
	int		i;

	i = 0;
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
			free(line);
			get_next_line(0, &line);
			ft_printf("%s\n", line);
			starting_room = ft_strsplit(line, ' ');
			if (!find_room(starting_room[0], &tube))
				save_room(&tube, starting_room);
		}
		else if (!ft_strcmp("##end", line))
		{
			free(line);
			get_next_line(0, &line);
			ft_printf("%s\n", line);
			ending_room = ft_strsplit(line, ' ');
			if (!find_room(ending_room[0], &tube))
				save_room(&tube, ending_room);
		}
		else if (!ft_strchr(line, '-') && ft_strchr(line, ' '))
		{
			split_tmp = ft_strsplit(line, ' ');
			save_room(&tube, split_tmp);
		}
		else if (ft_strchr(line, '-') && !ft_strchr(line, ' '))
		{
			split_tmp = ft_strsplit(line, '-');
			if (find_room(split_tmp[0], &tube) && find_room(split_tmp[1], &tube))
			{
				find_room(split_tmp[0], &tube)->links = realloc_links(find_room(split_tmp[0], &tube), find_room(split_tmp[1], &tube));
				find_room(split_tmp[1], &tube)->links = realloc_links(find_room(split_tmp[1], &tube), find_room(split_tmp[0], &tube));
			}
		}
		free(line);
	}
	while (tube->prev != NULL)
		tube = tube->prev;
	show_struct(&tube);
	return (0);
}
