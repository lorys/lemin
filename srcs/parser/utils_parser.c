/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarles <pcarles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 21:46:30 by pcarles           #+#    #+#             */
/*   Updated: 2019/02/19 16:26:49 by pcarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int		count_char(char *str, char c)
{
	int	ret;

	ret = 0;
	if (!str)
		return (-1);
	while (*str)
	{
		if (*str == c)
			ret++;
		str++;
	}
	return (ret);
}
