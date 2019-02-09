/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarles <pcarles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 14:06:07 by pcarles           #+#    #+#             */
/*   Updated: 2019/02/10 00:09:21 by pcarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>
#include "libft.h"
#include "ft_printf.h"
#include "common.h"

int				create_matrix(uint32_t ***matrixp, size_t size)
{
	unsigned int	index;
	size_t			length;
	uint32_t		**matrix;

	index = 0;
	if (matrixp == NULL || (matrix = (uint32_t**)malloc(sizeof(*matrix) * size)) == NULL)
		return (-1);
	length = ((sizeof(**matrix) * size) / 32) + sizeof(**matrix);
	while (index < size)
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
	*matrixp = matrix;
	return (1);
}

void			free_matrix(uint32_t **matrix, size_t size)
{
	if (matrix == NULL)
		return ;
	while (--size > 0)
		free(matrix[size]);
	free(*matrix);
	free(matrix);
}

int				write_matrix(uint32_t **matrix, unsigned int x, unsigned int y)
{
	matrix[y][x / 32] ^= (0x80000000 >> (x % 32));
	return (1);
}

int				read_matrix(uint32_t **matrix, unsigned int x, unsigned int y)
{
	ft_printf("x: %d, y: %d\n", x, y);
	return (matrix[y][x / 32] & (0x80000000 >> (x % 32)));
}

void			print_matrix(uint32_t **matrix, size_t size)
{
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	while (i < size)
	{
		while (j < size)
		{
			ft_putchar(read_matrix(matrix, j, i) ? '1' : '0');
			ft_putchar(' ');
			j++;
		}
		j = 0;
		ft_putchar('\n');
		i++;
	}
}