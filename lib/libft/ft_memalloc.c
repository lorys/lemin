/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 18:49:58 by llopez            #+#    #+#             */
/*   Updated: 2017/11/11 18:59:12 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t len)
{
	unsigned char *alloc;

	if (!(alloc = (unsigned char *)malloc(len)))
		return (0);
	ft_bzero(alloc, len);
	return (alloc);
}
