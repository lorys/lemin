/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarles <pcarles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 18:50:20 by pcarles           #+#    #+#             */
/*   Updated: 2019/02/05 21:14:27 by pcarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PATH_H
# define PATH_H

typedef	struct	s_paths {
	struct s_paths		*next;
	struct s_paths		*prev;
	struct s_vertice	*room;
}				t_paths;

#endif