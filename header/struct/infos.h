/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infos.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarles <pcarles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 18:52:24 by pcarles           #+#    #+#             */
/*   Updated: 2019/02/12 20:44:28 by pcarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INFOS_H
# define INFOS_H

#include <stdint.h>

typedef	struct		s_infos {
	struct s_vertice	*room_list;
	struct s_vertice	*end;
	struct s_vertice	*start;
	int					fourmis;
	int					nb_paths;
	int					bonus;
	int					select;
	int					bonusants;
	int					round_bonus;
	char				*file_path;
	uint32_t			**adjacency_matrix;
	unsigned int		room_total;
	int					rounds;
}					t_infos;

#endif