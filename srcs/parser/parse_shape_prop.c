/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_shape_prop.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/10 01:33:56 by jaguillo          #+#    #+#             */
/*   Updated: 2015/03/10 01:55:56 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static t_bool	shape_prop(t_parsing *p, t_shape *shape, const char *prop)
{
	if (ft_strequ(prop, "pos"))
		return (parse_pos(p, &(shape->pos)));
	else if (ft_strequ(prop, "dirr"))
		return (parse_pos(p, (t_pos*)&(shape->dirr)));
	else if (ft_strequ(prop, "childs"))
		return (parse_shape_tab(p, &(shape->childs)));
	else
		return (parse_error_undef(p, "shape property", prop));
}

t_bool			parse_shape_prop(t_parsing *p, t_shape *shape)
{
	ft_stringclr(p->tmp);
	ft_parsesubf(p->buff, p->tmp, &ft_isword);
	if (!BIS(p->buff, ':'))
		return (parse_error_before(p, "Expected ':'"));
	parse_blank(p);
	if (!shape_prop(p, shape, p->tmp->content))
		return (false);
	parse_blank(p);
	if (!BIS(p->buff, ';'))
		return (parse_error_before(p, "Expected ';'"));
	return (true);
}
