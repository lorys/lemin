/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 19:11:46 by llopez            #+#    #+#             */
/*   Updated: 2018/11/06 23:15:23 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

int		ft_tubelen(t_tube *len) {
	int i;

	i = 0;
	while (len->links && len->links[i])
		i++;
	return (i-1);
}

int		read_stdin(t_tube *tube, t_infos *infos)
{
	char	*line;
	char	**tmp;

	tmp = NULL;
	while (get_next_line(0, &line))
	{
		ft_printf("%s\n", line);
		if (ft_isdigit(line[0]) && !ft_strchr(line, ' ') &&\
				!ft_strchr(line, '-'))
			infos->fourmis = ft_atoi(line);
		else if (line[0] == '#' && line[1] != '#')
			continue;
		else if (!ft_strcmp("##start", line))
			save_start(tube, infos);
		else if (!ft_strcmp("##end", line))
			save_end(tube, infos);
		else if (!ft_strchr(line, '-') && ft_strchr(line, ' '))
			save_room(&tube, (tmp = ft_strsplit(line, ' ')));
		else if (ft_strchr(line, '-') && !ft_strchr(line, ' '))
			make_tube(line, tube);
	}
	return (1);
}

int		main(void)
{
	t_infos *infos;
	t_tube	*tube;

	tube = malloc(sizeof(t_tube));
	tube->prev = NULL;
	tube->next = NULL;
	tube->name = NULL;
	tube->x = 0;
	tube->y = 0;
	tube->vu = 0;
	tube->links = NULL;
	infos = (t_infos *)malloc(sizeof(t_infos));
	read_stdin(tube, infos);
	
	
	
	printf("start = %s\nend = %s\n", infos->start->name, infos->end->name);
	while (tube->prev != NULL)
		tube = tube->prev;
	printf("nbr of steps = %d\n", find_path(infos->start, infos, NULL));
	show_struct(&tube);
	return (0);
}
