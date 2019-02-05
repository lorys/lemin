/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 09:10:05 by llopez            #+#    #+#             */
/*   Updated: 2017/11/17 13:52:50 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char *dc;
	unsigned char *sc;

	dc = (unsigned char *)dest;
	sc = (unsigned char *)src;
	if (sc < dc)
		while (n--)
			dc[n] = sc[n];
	else
		ft_memcpy(dc, sc, n);
	return (dest);
}
