/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/03 23:29:25 by llopez            #+#    #+#             */
/*   Updated: 2019/02/03 23:31:33 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			fill_buffer(const char *str, char *buffer, int print,\
		t_infos *infos)
{
	static size_t	index = 0;
	int				str_len;
	char			*tmp;

	if (print || infos->bonus || infos->select > 0)
	{
		if (print)
			write(1, buffer, index);
		else
			write(1, str, ft_strlen(str));
		index = 0;
		return ;
	}
	tmp = buffer + index;
	str_len = ft_strlen(str);
	if (index + str_len >= BUFFER_SIZE - 1)
	{
		write(1, buffer, index);
		index = 0;
		fill_buffer(str, buffer, 0, infos);
		return ;
	}
	ft_memcpy(tmp, str, str_len);
	index += str_len;
}

void			show_ant(int l, t_tube *room, t_infos *infos, char *buffer)
{
	char	*tmp;

	if (!room || !infos)
		return ;
	if (infos->select == l)
		ft_printf("\033[41mL%d-%s\033[0m", l, room->name);
	else if (infos->bonus)
		ft_printf("\033[%dmL%d-%s\033[0m", l, l, room->name);
	else
	{
		tmp = ft_itoa(l);
		fill_buffer("L", buffer, 0, infos);
		fill_buffer(tmp, buffer, 0, infos);
		fill_buffer("-", buffer, 0, infos);
		fill_buffer(room->name, buffer, 0, infos);
		free(tmp);
	}
}
