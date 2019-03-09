/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infos.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarles <pcarles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 18:52:24 by pcarles           #+#    #+#             */
/*   Updated: 2019/03/09 18:06:35 by pcarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INFOS_H
# define INFOS_H

# include <stdint.h>

typedef	struct		s_infos {
	char				*file_path;
	struct s_vertice	*start;
	struct s_vertice	*end;
	struct s_vertice	*room_list;
	unsigned int		room_total;
	uint32_t			**adjacency_matrix;
	uint32_t			**residual_matrix;
	int					*parent_array;
	int					nb_ants;
	unsigned int		selected_ant;
	int					rounds;
}					t_infos;

#endif
