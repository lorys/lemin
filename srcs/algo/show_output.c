/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_output.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarles <pcarles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 16:01:01 by pcarles           #+#    #+#             */
/*   Updated: 2019/03/17 20:22:22 by pcarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "ft_printf.h"
#include "common.h"
#include "algo.h"

static void		fill_buffer(char *str, size_t str_len)
{
	static char		buffer[4096 + 1] = {'\0'};
	static size_t	index = 0;

	if (str != NULL && *str == '\n')
	{
		buffer[index - 1] = '\n';
		return ;
	}
	if (str == NULL || index + str_len >= 4096)
	{
		write(1, buffer, index);
		index = 0;
		if (str == NULL)
			return ;
	}
	ft_strcpy(buffer + index, str);
	index += str_len;
}

static void		show_ant(unsigned int new_ant, t_path *path, t_infos *infos)
{
	char		*tmp_c;

	tmp_c = ft_itoa(new_ant);
	if (new_ant == infos->selected_ant)
		fill_buffer("\e[30;41m", 8);
	fill_buffer("L", 1);
	fill_buffer(tmp_c, ft_strlen(tmp_c));
	fill_buffer("-", 1);
	fill_buffer(path->room->name, ft_strlen(path->room->name));
	if (new_ant == infos->selected_ant)
		fill_buffer("\e[0m", 4);
	fill_buffer(" ", 1);
	free(tmp_c);
}

static int		push_ants(t_path *path, unsigned int new_ant, t_infos *infos)
{
	int				ret;
	unsigned int	tmp;

	ret = 0;
	while (path)
	{
		tmp = path->ant;
		path->ant = new_ant;
		if (new_ant != 0)
		{
			show_ant(new_ant, path, infos);
			ret++;
		}
		new_ant = tmp;
		path = path->next;
	}
	return (ret);
}

static int		print_newline(unsigned int *status, unsigned int *rounds)
{
	fill_buffer("\n", 1);
	if (*status == 0)
		return (1);
	(*rounds)++;
	*status = 0;
	return (0);
}

void			show_output(t_solution *solution, size_t nb_ants, \
				int display_rounds, t_infos *infos)
{
	unsigned int	rounds;
	unsigned int	status;
	unsigned int	next_ant;
	t_path			*next_path;

	rounds = 0;
	status = 0;
	(void)nb_ants;
	next_path = get_next_path(solution);
	while (42)
	{
		next_ant = get_next_ant(solution, next_path);
		status += push_ants(next_path, next_ant, infos);
		next_path = get_next_path(solution);
		if (next_path == solution->paths[0] && print_newline(&status, &rounds))
			break ;
		if (next_ant == 0)
			continue ;
	}
	fill_buffer(NULL, 0);
	if (display_rounds == 1)
	{
		ft_putstr("\n\e[30;41m");
		ft_putnbr(rounds);
		ft_putstr(" rounds\e[0m\n");
	}
}
