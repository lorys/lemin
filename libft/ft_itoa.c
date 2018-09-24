/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 15:25:54 by llopez            #+#    #+#             */
/*   Updated: 2017/11/14 16:11:44 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoa(int n)
{
	char	*alloc;
	char	neg;
	int		i;
	int		count;
	int		min_index;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	i = n;
	neg = (n < 0) ? '-' : '+';
	n = (n < 0) ? n * -1 : n;
	count = (neg == '-') ? ft_intlen(n) + 1 : ft_intlen(n);
	if (!(alloc = (char *)malloc(sizeof(char) * count - 1)))
		return (NULL);
	alloc[count] = '\0';
	min_index = (neg == '-') ? 1 : 0;
	while (count-- > min_index)
	{
		i = n % 10;
		n = n / 10;
		alloc[count] = i + '0';
	}
	if (min_index == 1)
		alloc[0] = '-';
	return (alloc);
}
