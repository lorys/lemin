/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 19:11:46 by llopez            #+#    #+#             */
/*   Updated: 2018/09/24 19:40:17 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

int		main(int argc, char **argv)
{
	char *line;

	while (get_next_line(0, &line))
	{
		if (!ft_strcmp("##start", line))
			starting_room(get_next_line(0, &line), );
		free(line);
	}
	return (0);
}
