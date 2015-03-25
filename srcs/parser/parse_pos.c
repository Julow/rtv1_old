/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_pos.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/09 20:10:20 by jaguillo          #+#    #+#             */
/*   Updated: 2015/03/25 18:07:11 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_bool			parse_pos(t_parsing *p, t_pos *pos)
{
	if (!BIS(p->buff, '{'))
		return (parse_error_before(p, "Expect '{'"));
	parse_blank(p);
	if (!parse_double(p, &(pos->x)))
		return (false);
	parse_blank(p);
	if (!BIS(p->buff, ','))
		return (parse_error_before(p, "Expect ','"));
	parse_blank(p);
	if (!parse_double(p, &(pos->y)))
		return (false);
	parse_blank(p);
	if (!BIS(p->buff, ','))
		return (parse_error_before(p, "Expect ','"));
	parse_blank(p);
	if (!parse_double(p, &(pos->z)))
		return (false);
	parse_blank(p);
	if (!BIS(p->buff, '}'))
		return (parse_error_before(p, "Expect '}'"));
	return (true);
}
