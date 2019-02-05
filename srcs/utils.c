/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarles <pcarles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 15:17:38 by llopez            #+#    #+#             */
/*   Updated: 2019/01/07 19:58:26 by pcarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "common.h"

int		ft_stris(char *str, int (*f)(int c))
{
	while (*str)
	{
		if (!f((int)*str))
			return (0);
		str++;
	}
	return (1);
}

int		ft_strisnumber(char *str)
{
	if (*str == '-' || *str == '+')
		str++;
	return (ft_stris(str, &ft_isdigit));
}

void	display_error(t_tube *tube)
{
	free_everything(tube);
	write(2, "ERROR\n", 6);
	exit(EXIT_FAILURE);
}

t_tube	*find_room(char *room_name, t_tube *room_list)
{
	t_tube	*tmp;

	if (!room_name || !room_list)
		return (NULL);
	tmp = room_list->next;
	while (room_list)
	{
		if (!ft_strcmp(room_list->name, room_name))
			return (room_list);
		room_list = room_list->prev;
	}	
	while (tmp)
	{
		if (!ft_strcmp(tmp->name, room_name))
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}