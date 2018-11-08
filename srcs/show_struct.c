/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 22:11:08 by llopez            #+#    #+#             */
/*   Updated: 2018/11/08 17:10:13 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

void	show_struct(t_tube **tube)
{
	int	i;

	i = 0;
	printf("addr = %p\n", (*tube));
	printf("nom = %s\n", (*tube)->name);
	printf("x = %d\n", (*tube)->x);
	printf("y = %d\n", (*tube)->y);
	while ((*tube)->links && (*tube)->links[i]) {
		printf("\tliens === %s\n", (*tube)->links[i]->name);
		i++;
	}
	printf("prev = %p\n", (*tube)->prev);
	printf("next = %p\n", (*tube)->next);
	printf("------------------------------\n");
	if ((*tube)->next && (*tube)->next->name)
		show_struct(&(*tube)->next);
}
