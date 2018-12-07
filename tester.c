/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 05:24:27 by llopez            #+#    #+#             */
/*   Updated: 2018/12/07 06:12:17 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <string.h>
#include <stdarg.h>

int		main(int argc, char **argv)
{
	int		tmpa;
	int		tmpb;
	int		fd;
	char	*line;
	int		ret;
	char	*tmp;
	char	*buffer;

	line = (char *)malloc(sizeof(char) * 3000);
	system("mkdir -p map_test");
	system("../../generator --big > map_test/big");
	fd = open("map_test/big", O_RDONLY);
	ret = read(fd, line, 50);
	line[ret] = '\0';
	tmpa = atoi(line);
	system("./lem-in < map_test/big | wc -l | tr -d ' '");
	line[ret] = '\0';
	tmpb = atoi(line);
	printf("difference = %d\n", (tmpb - tmpa));
	return (0);
}
