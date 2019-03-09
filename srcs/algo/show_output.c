/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_output.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarles <pcarles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 16:01:01 by pcarles           #+#    #+#             */
/*   Updated: 2019/03/09 00:58:07 by pcarles          ###   ########.fr       */
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

static t_path	*get_next_path(t_solution *solution)
{
	static size_t	last_path = 0;

	if (last_path >= solution->nb_paths)
		last_path = 0;
	return (solution->paths[last_path++]);
}

static int		push_ants(t_path *path, unsigned int new_ant)
{
	int				ret;
	unsigned int	tmp;
	char			*tmp_c;

	ret = 0;
	while (path)
	{
		tmp = path->ant;
		path->ant = new_ant;
		if (new_ant != 0)
		{
			tmp_c = ft_itoa(new_ant);
			fill_buffer("L", 1);
			fill_buffer(tmp_c, ft_strlen(tmp_c));
			fill_buffer("-", 1);
			fill_buffer(path->room->name, ft_strlen(path->room->name));
			fill_buffer(" ", 1);
			free(tmp_c);
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
				int display_rounds)
{
	unsigned int	rounds;
	unsigned int	status;
	unsigned int	next_ant;
	t_path			*next_path;

	rounds = 0;
	status = 0;
	next_ant = 1;
	next_path = get_next_path(solution);
	while (42)
	{
		status += push_ants(next_path, next_ant);
		next_path = get_next_path(solution);
		if (next_path == solution->paths[0] && print_newline(&status, &rounds))
			break ;
		if (next_ant == 0)
			continue ;
		if (next_ant < nb_ants)
			next_ant++;
		else
			next_ant = 0;
	}
	fill_buffer(NULL, 0);
	if (display_rounds == 1)
		ft_printf("%d rounds\n", rounds);
}
