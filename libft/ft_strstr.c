/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 10:45:59 by llopez            #+#    #+#             */
/*   Updated: 2017/11/11 12:17:23 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(char const *str, char const *search)
{
	int i;
	int b;

	b = 0;
	i = 0;
	if (!*search)
		return ((char *)str);
	while (str[i] != '\0')
	{
		if (str[i] == search[b])
		{
			while (search[b] == str[i + b])
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
