/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarles <pcarles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 18:48:49 by pcarles           #+#    #+#             */
/*   Updated: 2019/01/05 18:51:35 by pcarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TUBE_H
# define TUBE_H

# include "struct/path.h"

typedef	struct		s_btu {
	int		rounds;
	int		index;
	struct s_tube	*room;
}			t_btu;

typedef	struct		s_tube {
	char			*name;
	int				x;
	int				y;
	int				vu;
	int				ants;
	int				steps;
	int				already_moved;
	int				hidden;
	int				index;
	int				passages;
	int				path_length;
	int				ants_passed;
	struct s_paths	*links;
	struct s_tube	*next;
	struct s_tube	*to;
	struct s_tube	*prev;
}					t_tube;

#endif