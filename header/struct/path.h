/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarles <pcarles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 18:50:20 by pcarles           #+#    #+#             */
/*   Updated: 2019/01/05 18:51:11 by pcarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PATH_H
# define PATH_H

#include "struct/tube.h"

typedef	struct	s_paths {
	struct s_paths	*next;
	struct s_paths	*prev;
	struct s_tube	*room;
}				t_paths;

#endif