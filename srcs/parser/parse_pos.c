/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_pos.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/09 20:10:20 by jaguillo          #+#    #+#             */
/*   Updated: 2015/03/09 20:17:59 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_bool			parse_pos(t_parsing *p, t_pos *pos)
{
	if (!BIS(p->buff, '{'))
		return (parse_error_before(p, "Expect '{'"));
	parse_blank(p);
	pos->x = (double)ft_parseint(p->buff);
	parse_blank(p);
	if (!BIS(p->buff, ','))
		return (parse_error_before(p, "Expect ','"));
	parse_blank(p);
	pos->y = (double)ft_parseint(p->buff);
	parse_blank(p);
	if (!BIS(p->buff, ','))
		return (parse_error_before(p, "Expect ','"));
	parse_blank(p);
	pos->z = (double)ft_parseint(p->buff);
	parse_blank(p);
	if (!BIS(p->buff, '}'))
		return (parse_error_before(p, "Expect '}'"));
	return (true);
}
