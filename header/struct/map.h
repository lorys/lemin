/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarles <pcarles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 22:44:24 by pcarles           #+#    #+#             */
/*   Updated: 2019/02/06 22:45:17 by pcarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# define BUFFER_SIZE 4096

typedef struct		s_map
{
	char			buffer[BUFFER_SIZE];
	struct s_map	*next;
	struct s_map	*prev;
}					t_map;

#endif