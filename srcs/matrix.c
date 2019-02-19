/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarles <pcarles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 14:06:07 by pcarles           #+#    #+#             */
/*   Updated: 2019/02/19 15:53:29 by pcarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
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
			while (index-- > 0)
				free(matrix[index]);
			return (-1);
		}
		ft_bzero(matrix[index], length);
		index++;
	}
	*matrixp = matrix;
	return (1);
}

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

int				read_matrix(uint32_t **matrix, unsigned int x, unsigned int y)
{
	size_t		index;
	size_t		offset;
	int			ret;

	index = x / 16;
	offset = (x % 16) * 2;
	ret = 0;
	if (matrix[y][index] & 0x40000000 >> offset)
		ret = 1;
	if (matrix[y][index] & 0x80000000 >> offset)
		ret = -ret;
	return (ret);
}