/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarles <pcarles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 14:06:07 by pcarles           #+#    #+#             */
/*   Updated: 2019/02/09 17:40:33 by pcarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>
#include "libft.h"
#include "ft_printf.h"
#include "common.h"

int				create_matrix(t_infos *infos)
{
	unsigned int	index;
	size_t			length;
	uint32_t		**matrix;

	index = 0;
	if ((matrix = (uint32_t**)malloc(sizeof(*matrix) * infos->room_total)) == NULL)
		return (-1);
	length = ((sizeof(**matrix) * infos->room_total) / 32) + sizeof(**matrix);
	while (index < infos->room_total)
	{
		if ((matrix[index] = (uint32_t*)malloc(length)) == NULL)
		{
			// malloc error free everything
			while (--index)
				free(matrix[index]); // Leak sur le premier maillon (matrix[0])
			free(matrix);
			return (-1);
		}
		ft_bzero(matrix[index], length);
		index++;
	}
	infos->adjacency_matrix = matrix;
	return (1);
}

void			free_matrix(uint32_t **adjacency_matrix, unsigned int size)
{
	if (adjacency_matrix == NULL)
		return ;
	while (--size > 0)
		free(adjacency_matrix[size]);
	free(*adjacency_matrix);
	free(adjacency_matrix);
}

int				write_matrix(t_infos *infos, unsigned int x, unsigned int y)
{
	if (x >= infos->room_total || y >= infos->room_total)
		return (-1);
	// if (value != 0)
	// 	infos->adjacency_matrix[y][x / 32] |= (0x80000000 >> (x % 32));
	// else
	// 	infos->adjacency_matrix[y][x / 32] &= ~(0x80000000 >> (x % 32));
	infos->adjacency_matrix[y][x / 32] ^= (0x80000000 >> (x % 32));
	return (1);
}

int				read_matrix(t_infos *infos, unsigned int x, unsigned int y)
{
	if (x >= infos->room_total || y >= infos->room_total)
		return (-1);
	return (infos->adjacency_matrix[y][x / 32] & (0x80000000 >> (x % 32)));
}

void			print_matrix(t_infos *infos)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (i < infos->room_total)
	{
		while (j < infos->room_total)
		{
			ft_putchar(read_matrix(infos, j, i) ? '1' : '0');
			ft_putchar(' ');
			j++;
		}
		j = 0;
		ft_putchar('\n');
		i++;
	}
}