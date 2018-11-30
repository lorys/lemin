/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarles <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 05:40:26 by pcarles           #+#    #+#             */
/*   Updated: 2018/11/30 05:40:28 by pcarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>
#include "vizualizer.h"

/*
static void		trace_segment(int x1, int x2, int y1, int y2)
{
	int			dx;
	int			dy;
	int			e;

	e = x2 - x1;
	dx = e * 2;
	dy = (y2 - y1) * 2;
	while (x1 <= x2)
	{
		mvaddch(y1, x1, '*');
		++x1;
		if ((e = e - dy) <= 0)
		{
			++y1;
			e += dx;
		}
	}
}
*/

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
