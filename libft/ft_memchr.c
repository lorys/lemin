/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 14:56:35 by llopez            #+#    #+#             */
/*   Updated: 2017/11/11 16:48:16 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	int				i;
	unsigned char	c_uc;
	unsigned char	*tmp;

	c_uc = (unsigned char)c;
	i = 0;
	tmp = (unsigned char *)s;
	while (n--)
	{
		if (tmp[i] == c_uc)
			return (tmp + i);
		i++;
	}
	return (NULL);
}
