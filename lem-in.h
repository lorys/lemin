/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 19:12:06 by llopez            #+#    #+#             */
/*   Updated: 2018/09/25 18:45:36 by llopez           ###   ########.fr       */
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
