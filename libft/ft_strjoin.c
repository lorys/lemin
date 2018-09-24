/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 10:11:40 by llopez            #+#    #+#             */
/*   Updated: 2017/11/14 04:25:59 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*alloc;

	if (!s1 || !s2)
		return (NULL);
	alloc = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!alloc)
		return (NULL);
	ft_strcpy(alloc, s1);
	ft_strcpy(alloc + ft_strlen(s1), s2);
	return (alloc);
}
