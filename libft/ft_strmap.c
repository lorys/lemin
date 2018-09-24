/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 19:09:57 by llopez            #+#    #+#             */
/*   Updated: 2017/11/12 19:59:45 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*str_m;
	int		s_len;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (!(str_m = (char *)ft_memalloc(sizeof(char) * s_len + 1)))
		return (NULL);
	while (i < s_len)
	{
		str_m[i] = f(s[i]);
		i++;
	}
	return (str_m);
}
