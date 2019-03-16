/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertice.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarles <pcarles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 18:48:49 by pcarles           #+#    #+#             */
/*   Updated: 2019/02/21 18:20:29 by pcarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VERTICE_H
# define VERTICE_H

typedef	struct			s_vertice {
	char				*name;
	unsigned int		id;
	int					x;
	int					y;
	struct s_path		*links;
	struct s_vertice	*next;
}						t_vertice;

#endif
