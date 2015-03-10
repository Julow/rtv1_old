/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_shape.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/09 17:18:52 by jaguillo          #+#    #+#             */
/*   Updated: 2015/03/10 18:46:08 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static t_bool	parse_shape_name(t_parsing *p, t_shape *shape)
{
	ft_stringclr(p->tmp);
	ft_parsesubf(p->buff, p->tmp, &ft_isword);
	if (p->tmp->length <= 0)
		return (parse_error_before(p, "Expected shape name"));
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

static t_bool	parse_shape_type(t_parsing *p, t_shape *shape)
{
	t_shape			*tmp;

	parse_blank(p);
	if (!BIS(p->buff, '('))
		return ((shape->type = NONE), true);
	ft_stringclr(p->tmp);
	ft_parsesubf(p->buff, p->tmp, &ft_isword);
	if ((tmp = get_shape(p->env, p->tmp->content)) != NULL)
		ft_memcpy(shape, tmp, sizeof(t_shape));
	else
		return (parse_error_undef(p, "shape", p->tmp->content));
	parse_blank(p);
	if (!BIS(p->buff, ')'))
		return (parse_error_before(p, "Expected ')'"));
	return (true);
}

t_bool			parse_shape(t_parsing *p)
{
	t_shape			shape;

	shape = (t_shape){0};
	ft_tabini(&(shape.childs), sizeof(t_shape));
	if (!parse_shape_name(p, &shape))
		return (false);
	if (!parse_shape_type(p, &shape) || !parse_shape_block(p, &shape))
		return (kill_shape(&shape), false);
	ft_tabadd(&(p->env->shapes), &shape);
	return (true);
}
