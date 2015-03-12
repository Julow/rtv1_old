/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_shape.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/09 17:18:52 by jaguillo          #+#    #+#             */
/*   Updated: 2015/03/12 16:02:56 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static t_bool	parse_shape_name(t_parsing *p, t_shape *shape)
{
	ft_stringclr(p->tmp);
	ft_parsesubf(p->buff, p->tmp, &ft_isword);
	if (p->tmp->length <= 0)
		return (parse_error_before(p, "Expected shape name"));
	if (get_shape(p->env, p->tmp->content) != NULL)
		return (parse_error_redef(p, "shape"));
	shape->name = ft_strdup(p->tmp->content);
	return (true);
}

static t_bool	parse_shape_block(t_parsing *p, t_shape *shape)
{
	parse_blank(p);
	if (!BIS(p->buff, '{'))
		return (parse_error_before(p, "Expected '{'"));
	parse_blank(p);
	while (!BIS(p->buff, '}') && !BEOF(p->buff))
	{
		if (!parse_shape_prop(p, shape))
			return (false);
		parse_blank(p);
	}
	return (true);
}

t_bool			parse_shape(t_parsing *p)
{
	t_shape			shape;

	shape = (t_shape){0};
	ft_tabini(&(shape.childs), sizeof(t_shape));
	if (!parse_shape_name(p, &shape))
		return (false);
	if (!parse_shape_inheritance(p, &shape) || !parse_shape_block(p, &shape))
		return (kill_shape(&shape), false);
	ft_tabadd(&(p->env->shapes), &shape);
	return (true);
}
