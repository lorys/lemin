/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarles <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 05:35:58 by pcarles           #+#    #+#             */
/*   Updated: 2018/11/30 05:36:01 by pcarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# define STATE_ROOMS 1
# define STATE_TUBES 2
# define STATE_START_ROOM 3
# define STATE_END_ROOM 4

void			warn_parsing(char *str, int nline);
void			error_parsing(char *str, int nline);

#endif
