/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarles <pcarles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 14:06:07 by pcarles           #+#    #+#             */
/*   Updated: 2019/02/12 20:41:53 by pcarles          ###   ########.fr       */
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
	length = ((sizeof(**matrix) * size) / (sizeof(**matrix) * 4)) + sizeof(**matrix);
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

void			copy_matrix(uint32_t **dst, uint32_t **src, size_t size)
{
	size = ((sizeof(**src) * size) / (sizeof(**src) * 4)) + sizeof(**src);
	while (size--)
		ft_memcpy(dst[size], src[size], size);
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

/**
 * op represent the operation to do on the matrix it can be +1 or -1
 */
int				write_matrix(uint32_t **matrix, int op, unsigned int x, unsigned int y)
{
	size_t		offset;
	size_t		index;

	index = x / 16;
	offset = (x % 16) * 2;
	if (op != 1 || (matrix[y][index] & (0x80000000 >> offset)))
		matrix[y][index] ^= 0x80000000 >> offset;
	matrix[y][index] ^= 0x40000000 >> offset;
	return (1);
}

/**
 * We use 2 bit to store one matrix member, the first bit is for the sign of the member
 * 00 -> 0
 * 01 -> 1
 * 11 -> -1
 *
 * 10 -> -0? (unused)
 */
int				read_matrix(uint32_t **matrix, unsigned int x, unsigned int y)
{
	int			ret;

	ret = 0;
	if (matrix[y][x / 16] & 0x40000000 >> ((x % 16) * 2))
		ret = 1;
	if (matrix[y][x / 16] & 0x80000000 >> ((x % 16) * 2))
		ret = -ret;
	return (ret);
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
			if (j == size - 1)
				ft_printf("%d", read_matrix(matrix, j, i));
			else
				ft_printf("%-2d ", read_matrix(matrix, j, i));
			j++;
		}
		j = 0;
		ft_putchar('\n');
		i++;
	}
}