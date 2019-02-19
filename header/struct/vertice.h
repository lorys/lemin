/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertice.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarles <pcarles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 18:48:49 by pcarles           #+#    #+#             */
/*   Updated: 2019/02/19 15:50:13 by pcarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TUBE_H
# define TUBE_H

typedef	struct			s_vertice {
	char				*name;
	unsigned int		id;
	int					x;
	int					y;
	int					vu;
	int					ants;
	struct s_path		*links;
	struct s_vertice	*next;
}						t_vertice;

#endif