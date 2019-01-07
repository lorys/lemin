/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infos.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarles <pcarles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 18:52:24 by pcarles           #+#    #+#             */
/*   Updated: 2019/01/05 18:53:10 by pcarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INFOS_H
# define INFOS_H

# include "struct/tube.h"

typedef	struct		s_infos {
	struct s_tube	*end;
	struct s_tube	*start;
	int				fourmis;
	int				bonus;
	int				select;
	int				bonusants;
	int				room_total;
	int				rounds;
}					t_infos;

#endif