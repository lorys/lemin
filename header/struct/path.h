/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarles <pcarles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 18:50:20 by pcarles           #+#    #+#             */
/*   Updated: 2019/02/20 18:02:28 by pcarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PATH_H
# define PATH_H

typedef	struct	s_path {
	struct s_vertice	*room;
	struct s_path		*next;
	unsigned int		ant;
}				t_path;

#endif
