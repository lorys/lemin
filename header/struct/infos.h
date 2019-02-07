/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infos.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarles <pcarles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 18:52:24 by pcarles           #+#    #+#             */
/*   Updated: 2019/02/07 02:02:30 by pcarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INFOS_H
# define INFOS_H

typedef	struct		s_infos {
	struct s_vertice	*end;
	struct s_vertice	*start;
	int					fourmis;
	int					nb_paths;
	int					bonus;
	int					select;
	int					bonusants;
	int					round_bonus;
	char				*file_path;
	unsigned int		room_total;
	int					rounds;
}					t_infos;

#endif