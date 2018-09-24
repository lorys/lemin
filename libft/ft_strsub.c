/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 09:12:13 by llopez            #+#    #+#             */
/*   Updated: 2017/11/14 16:30:55 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char *alloc;

	if (!s)
		return (NULL);
	if (!(alloc = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	ft_strncpy(alloc, s + start, len);
	alloc[len] = '\0';
	return (alloc);
}
