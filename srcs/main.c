/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 19:11:46 by llopez            #+#    #+#             */
/*   Updated: 2018/11/07 19:35:26 by llopez           ###   ########.fr       */
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

int		main(void)
{
	t_infos *infos;
	t_tube	*tube;
	int		i;

	i = 0;
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
	while (infos->start->links[i])
	{
		printf("\\/\\/\\/\\/\\/\\/\\/\\/\n");
		find_path(infos->start->links[i], infos, infos->start, 0);
		printf("/\\/\\/\\/\\/\\/\\/\\/\\\n\n\n\n");
		i++;
	}
	show_struct(&tube);
	return (0);
}
