/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarles <pcarles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 18:59:42 by pcarles           #+#    #+#             */
/*   Updated: 2019/02/03 16:24:09 by pcarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_H
# define COMMON_H

# include "struct/infos.h"
# include "struct/tube.h"
# include "struct/path.h"

# define DEBUG 1

int				ft_stris(char *str, int (*f)(int c));
int				ft_strisnumber(char *str);
void			free_everything(t_tube *tube);
void			free_char_tab(char **str);
void			display_error(t_tube *tube);
int				count_edges(t_tube	*room);
void			print_debug(t_infos *infos);

#endif