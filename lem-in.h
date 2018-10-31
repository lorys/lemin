/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 19:12:06 by llopez            #+#    #+#             */
/*   Updated: 2018/10/30 10:23:56 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "libft.h"
#include "get_next_line.h"

typedef	struct	s_tube {
	char			*name;
	int				x;
	int				y;
	struct s_tube	**links; 
	struct s_tube	*next;
	struct s_tube	*prev;
}				t_tube;

typedef	struct	s_infos { 
	struct s_tube	*end;
	struct s_tube	*start;
}				t_infos;

t_tube		**realloc_links(t_tube *tube, t_tube *add);
