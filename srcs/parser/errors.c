/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarles <pcarles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 05:36:22 by pcarles           #+#    #+#             */
/*   Updated: 2019/03/16 18:06:57 by pcarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parser.h"

void		warn_parsing(char *str, int nline)
{
	char	*nline_str;

	if (str && PARSER_VERBOSITY && nline > 0)
	{
		fill_buffer(NULL);
		nline_str = ft_itoa(nline);
		ft_putstr_fd("\e[95;1mwarning\e[0m: line ", 2);
		ft_putstr_fd(nline_str, 2);
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(str, 2);
		ft_putchar_fd('\n', 2);
		free(nline_str);
	}
}

void		error_parsing(char *str, int nline)
{
	char	*nline_str;

	if (str && PARSER_VERBOSITY && nline > 0)
	{
		fill_buffer(NULL);
		nline_str = ft_itoa(nline);
		ft_putstr_fd("\e[91;1merror\e[0m: line ", 2);
		ft_putstr_fd(nline_str, 2);
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(str, 2);
		ft_putchar_fd('\n', 2);
		free(nline_str);
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
