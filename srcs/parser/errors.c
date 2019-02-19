/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarles <pcarles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 05:36:22 by pcarles           #+#    #+#             */
/*   Updated: 2019/02/19 16:27:05 by pcarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parser.h"

void	warn_parsing(char *str, int nline)
{
	char	*nline_str;

	if (str && DEBUG && nline > 0)
	{
		nline_str = ft_itoa(nline);
		ft_putstr_fd("\e[95;1mwarning\e[0m: line ", 2);
		ft_putstr_fd(nline_str, 2);
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(str, 2);
		ft_putchar_fd('\n', 2);
		free(nline_str);
	}
}

void	error_parsing(char *str, int nline)
{
	char	*nline_str;

	if (str && DEBUG && nline > 0)
	{
		nline_str = ft_itoa(nline);
		ft_putstr_fd("\e[91;1merror\e[0m: line ", 2);
		ft_putstr_fd(nline_str, 2);
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(str, 2);
		ft_putchar_fd('\n', 2);
		free(nline_str);
	}
}
