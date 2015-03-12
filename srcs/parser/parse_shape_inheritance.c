/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_shape_inheritance.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/12 13:18:56 by jaguillo          #+#    #+#             */
/*   Updated: 2015/03/12 16:04:17 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_bool			parse_shape_inheritance(t_parsing *p, t_shape *shape)
{
	t_shape			tmp;
	t_shape			*parent;

	parse_blank(p);
	if (!BIS(p->buff, '('))
		return ((shape->type = NONE), true);
	ft_stringclr(p->tmp);
	ft_parsesubf(p->buff, p->tmp, &ft_isword);
	if ((parent = get_shape(p->env, p->tmp->content)) == NULL)
		return (parse_error_undef(p, "shape"));
	tmp.name = shape->name;
	ft_memcpy(&(tmp.childs), &(shape->childs), sizeof(t_tab));
	ft_memcpy(shape, &parent, sizeof(t_shape));
	ft_memcpy(&(shape->childs), &(tmp.childs), sizeof(t_tab));
	shape->name = tmp.name;
	ft_tabaddn(&(shape->childs), parent->childs.data, parent->childs.length);
	parse_blank(p);
	if (!BIS(p->buff, ')'))
		return (parse_error_before(p, "Expected ')'"));
	return (true);
}
