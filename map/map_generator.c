/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_generator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 15:27:37 by llopez            #+#    #+#             */
/*   Updated: 2018/11/24 15:27:58 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

static int	ft_numblen(const char *str)
{
	int b;

	b = 0;
	while (str[b] == ' ' || (str[b] >= 9 && str[b] <= 13))
		b++;
	b = (str[b] == '-' || str[b] == '+') ? b + 1 : b;
	while (str[b])
		b++;
	return (b);
}

int				ft_atoi(char const *str)
{
	int i;
	int zero;
	int tmp;
	int result;
	int positive;

	result = 0;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	positive = (str[i] == '-') ? -1 : 1;
	positive = (str[i] == '+') ? 1 : positive;
	i = (str[i] == '-' || str[i] == '+') ? i : i - 1;
	while (str[++i])
	{
		zero = 0;
		tmp = ((int)str[i] - '0') * positive;
		while (zero++ < ((int)ft_numblen((char const *)str) - i - 1))
			tmp *= 10;
		result += tmp;
	}
	return (result);
}

int	main(int argc, char **argv)
{
	int a;
	int b;
	int tmp;

	tmp = 0;
	a = ft_atoi(argv[2]);
	b = 1;
	printf("%s\n", argv[1]);
	printf("##start\n0 0 0\n");
	printf("##end\n%d %d %d\n", a, a, a);
	while (b < a)
	{
		printf("%d %d %d\n", b, b, b);
		b++;
	}
	b = a;
	while (a)
	{
		tmp = a-ft_atoi(argv[3]);
		while (tmp < a)
		{
			if (tmp >= 0 && tmp != a)
				printf("%d-%d\n", a, tmp);
			tmp++;
		}
		a--;
	}
	return (0);
}
