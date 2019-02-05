/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 10:21:40 by llopez            #+#    #+#             */
/*   Updated: 2017/11/14 03:04:13 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*alloc;
	int		i;
	int		b;
	int		s_len;

	i = 0;
	if (!s)
		return (NULL);
	b = ft_strlen(s) - 1;
	s_len = ft_strlen(s);
	while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t') && s_len-- > 0)
		i++;
	if (s_len <= 0)
		return (ft_strnew(0));
	while ((s[b] == ' ' || s[b] == '\n' || s[b] == '\t') && s_len-- > 0)
		b--;
	if (!(alloc = (char *)malloc(sizeof(char) * (s_len + 1))))
		return (NULL);
	ft_strncpy(alloc, s + i, s_len);
	alloc[s_len] = '\0';
	return (alloc);
}
