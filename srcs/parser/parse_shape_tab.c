/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_shape_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/09 23:43:18 by jaguillo          #+#    #+#             */
/*   Updated: 2015/03/10 19:09:02 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static t_bool	parse_shape_instance(t_parsing *p, t_shape *instance)
{
	t_shape			*shape;

	ft_stringclr(p->tmp);
	ft_parsesubf(p->buff, p->tmp, &ft_isword);
	if ((shape = get_shape(p->env, p->tmp->content)) == NULL)
		return (parse_error_undef(p, "shape", p->tmp->content));
	ft_memcpy(instance, shape, sizeof(t_shape));
	parse_blank(p);
	while (!BIS(p->buff, '}') && !BEOF(p->buff))
	{
		if (!parse_shape_prop(p, instance))
			return (false);
		parse_blank(p);
	}
	return (true);
}

t_bool			parse_shape_tab(t_parsing *p, t_tab *tab)
{
	t_shape			tmp;

	if (!BIS(p->buff, '['))
		return (parse_error_before(p, "Expected '['"));
	parse_blank(p);
	while (true)
	{
		if (!parse_shape_instance(p, &tmp))
			return (false);
		ft_tabadd(tab, &tmp);
		parse_blank(p);
		if (!BIS(p->buff, ','))
			break ;
		parse_blank(p);
	}
	if (!BIS(p->buff, ']'))
		return (parse_error_before(p, "Expected ']' or ','"));
	return (true);
}
