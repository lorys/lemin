/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 22:11:08 by llopez            #+#    #+#             */
/*   Updated: 2018/11/22 05:45:29 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	show_struct(t_tube **tube)
{
	int	i;

	i = 0;
	ft_printf("addr = %p\n", (*tube));
	ft_printf("nom = %s\n", (*tube)->name);
	ft_printf("x = %d\n", (*tube)->x);
	ft_printf("y = %d\n", (*tube)->y);
	while ((*tube)->links && (*tube)->links[i])
	{
		ft_printf("\tliens === %s\n", (*tube)->links[i]->name);
		i++;
	}
	ft_printf("prev = %p\n", (*tube)->prev);
	ft_printf("next = %p\n", (*tube)->next);
	ft_printf("------------------------------\n");
	if ((*tube)->next && (*tube)->next->name)
		show_struct(&(*tube)->next);
}
