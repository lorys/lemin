/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarles <pcarles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 05:40:26 by pcarles           #+#    #+#             */
/*   Updated: 2019/02/21 18:32:00 by pcarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>
#include "libft.h"
#include "visualizer.h"

static void		plot_line_low(int x0, int y0, int x1, int y1)
{
	int			dx;
	int			dy;
	int			yi;
	int			d;

	dx = x1 - x0;
	dy = y1 - y0;
	yi = 1;
	if (dy < 0)
	{
		yi = -1;
		dy = -dy;
	}
	d = 2 * dy - dx;
	while (x0 <= x1)
	{
		mvaddch(y0, x0, '*');
		if (d > 0)
		{
			y0 += yi;
			d = d - 2 * dx;
		}
		d = d + 2 * dy;
		++x0;
	}
}

static void		plot_line_high(int x0, int y0, int x1, int y1)
{
	int			dx;
	int			dy;
	int			xi;
	int			d;

	dx = x1 - x0;
	dy = y1 - y0;
	xi = 1;
	if (dx < 0)
	{
		xi = -1;
		dx = -dx;
	}
	d = 2 * dx - dy;
	while (y0 <= y1)
	{
		mvaddch(y0, x0, '*');
		if (d > 0)
		{
			x0 += xi;
			d = d - 2 * dy;
		}
		d = d + 2 * dx;
		++y0;
	}
}

void			plot_line(int x0, int y0, int x1, int y1)
{
	if (ft_abs(y1 - y0) < ft_abs(x1 - x0))
	{
		if (x0 > x1)
			plot_line_low(x1, y1, x0, y0);
		else
			plot_line_low(x0, y0, x1, y1);
	}
	else
	{
		if (y0 > y1)
			plot_line_high(x1, y1, x0, y0);
		else
			plot_line_high(x0, y0, x1, y1);
	}
}
