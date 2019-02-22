/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 19:04:31 by llopez            #+#    #+#             */
/*   Updated: 2017/11/16 12:31:21 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int s_len;

	s_len = 0;
	if (!s || !f)
		return ;
	while (s_len < ft_strlen(s))
	{
		f(s_len, s + s_len);
		s_len++;
	}
}
