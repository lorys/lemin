/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 08:22:58 by llopez            #+#    #+#             */
/*   Updated: 2017/11/10 10:48:58 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(char const *str, char const *search, size_t n)
{
	int	i;
	int b;

	b = 0;
	i = 0;
	if (!*search)
		return ((char *)str);
	while (str[i] != '\0' && i < (int)n)
	{
		if (str[i] == search[b])
		{
			while (search[b] == str[i + b] && (i + b) < (int)n)
			{
				if (search[b + 1] == '\0')
					return ((char *)str + i);
				b++;
			}
			b = 0;
		}
		i++;
	}
	return (0);
}
