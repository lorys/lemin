/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 15:29:17 by llopez            #+#    #+#             */
/*   Updated: 2017/11/14 03:01:53 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memset(void *s, int c, size_t n)
{
	unsigned char *r;

	r = (unsigned char *)s;
	if (n == 0)
		return (s);
	while (n-- > 0)
		*r++ = (unsigned char)c;
	return (s);
}
