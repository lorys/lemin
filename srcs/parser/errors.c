/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarles <pcarles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 05:36:22 by pcarles           #+#    #+#             */
/*   Updated: 2019/02/03 23:56:36 by pcarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "parser.h"

void	warn_parsing(char *str, int nline)
{
	if (str && DEBUG && nline > 0)
	{
		ft_putstr_fd("\e[95;1mwarning\e[0m: line ", 2);
		ft_putstr_fd(ft_itoa(nline), 2);
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(str, 2);
		ft_putchar_fd('\n', 2);
	}
}

void	error_parsing(char *str, int nline)
{
	if (str && DEBUG && nline > 0)
	{
		ft_putstr_fd("\e[91;1merror\e[0m: line ", 2);
		ft_putstr_fd(ft_itoa(nline), 2);
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(str, 2);
		ft_putchar_fd('\n', 2);
	}
}

int			check_overflow(char *str)
{
	long	tmp;

	tmp = ft_atoi_long(str);
	if (tmp < INT_MIN || tmp > INT_MAX || ft_strlen(str) > 10)
		return (0);
	return (1);
}
