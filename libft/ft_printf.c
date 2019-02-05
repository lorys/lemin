/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 04:20:35 by llopez            #+#    #+#             */
/*   Updated: 2018/04/25 15:59:37 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_format_second(char const *str,\
					int *skip, t_arg *fg, va_list ap)
{
	int		lenght;

	lenght = ft_printf_percent(&str[0], &skip[1], fg);
	lenght += ft_printf_s(&str[0], ap, &skip[1], fg);
	lenght += ft_printf_p(&str[0], ap, &skip[1], fg);
	lenght += ft_printf_d(&str[0], ap, &skip[1], fg);
	lenght += ft_printf_c(&str[0], ap, &skip[1], fg);
	lenght += ft_printf_oo(&str[0], ap, &skip[1], fg);
	lenght += ft_printf_uu(&str[0], ap, &skip[1], fg);
	lenght += ft_printf_xx(&str[0], ap, &skip[1], fg);
	return (lenght);
}

static int		*ft_format(const char *str, va_list ap, int *lenght)
{
	int		i;
	int		bfore;
	int		*skip;
	t_arg	fg;
	int		tmp;

	skip = (int *)malloc(sizeof(int) * 3);
	i = 0;
	skip[1] = 0;
	bfore = *lenght;
	tmp = 0;
	if (str[i] == '%' && str[i + 1] != '\0' && ++i)
	{
		ft_initialize_struct(&fg);
		i += ft_printf_flags(&str[i], &skip[1], &fg);
		tmp = ft_printf_bigs(&str[i], ap, &skip[1], &fg);
		*lenght += tmp;
		skip[2] = (tmp == -1) ? -1 : skip[2];
		tmp = ft_printf_bigc(&str[i], ap, &skip[1], &fg);
		*lenght += tmp;
		skip[2] = (tmp == -1) ? -1 : skip[2];
		*lenght += ft_format_second((str + i), &skip[0], &fg, ap);
	}
	skip[0] = (*lenght - bfore);
	return (skip);
}

int				ft_run_format(int *retrn, int *lenght, char const *format,\
		int *i)
{
	if (retrn[1] == 0 && ++*lenght)
	{
		if (format[*i] == '%' && format[*i + 1] == '\0')
			return (0);
		ft_putchar(format[*i]);
		*i += 1;
	}
	return (1);
}

int				ft_printf(const char *format, ...)
{
	va_list		ap;
	int			i;
	int			lenght;
	int			*retrn;
	int			error;

	i = 0;
	lenght = 0;
	error = 0;
	if (format == NULL)
		return (0);
	va_start(ap, format);
	while (format[i])
	{
		retrn = ft_format(&format[i], ap, &lenght);
		if (!ft_run_format(&retrn[0], &lenght, format, &i))
			return (0);
		i += retrn[1];
		error = (retrn[2] == -1) ? -1 : 0;
		free(retrn);
	}
	va_end(ap);
	return ((error == -1) ? -1 : lenght);
}
