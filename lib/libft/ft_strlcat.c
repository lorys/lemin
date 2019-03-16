/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 07:51:44 by llopez            #+#    #+#             */
/*   Updated: 2017/11/11 17:04:31 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, char const *src, size_t size)
{
	int i;
	int b;

	b = 0;
	i = 0;
	while (dst[i] && size)
	{
		i++;
		size--;
	}
	if (!size)
		return (i + ft_strlen(src));
	while (src[b] && --size)
	{
		dst[i + b] = src[b];
		b++;
	}
	dst[i + b] = '\0';
	return (i + ft_strlen(src));
}
