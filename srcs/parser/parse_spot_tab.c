/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_spot_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/12 18:56:34 by jaguillo          #+#    #+#             */
/*   Updated: 2015/03/12 20:45:00 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static t_bool	spot_prop(t_parsing *p, t_spot *spot, const char *prop)
{
	if (ft_strequ(prop, "pos"))
		return (parse_pos(p, &(spot->pos)));
	else if (ft_strequ(prop, "color"))
		return (parse_color(p, &(spot->color)));
	else if (ft_strequ(prop, "brightness"))
		return ((spot->bright = ft_parsedouble(p->buff)), true);
	return (parse_error_undef(p, "spot property"));
}

static t_bool	parse_spot_prop(t_parsing *p, t_spot *spot)
{
	ft_stringclr(p->tmp);
	ft_parsesubf(p->buff, p->tmp, &ft_isword);
	parse_blank(p);
	if (!BIS(p->buff, ':'))
		return (parse_error_before(p, "Expected ':'"));
	parse_blank(p);
	if (!spot_prop(p, spot, p->tmp->content))
		return (false);
	parse_blank(p);
	if (!BIS(p->buff, ';'))
		return (parse_error_before(p, "Expected ';'"));
	return (true);
}

static t_bool	parse_spot_instance(t_parsing *p, t_spot *spot)
{
	if (!BIS(p->buff, '{'))
		return (parse_error_before(p, "Expected '{'"));
	parse_blank(p);
	while (!BIS(p->buff, '}') && !BEOF(p->buff))
	{
		if (!parse_spot_prop(p, spot))
			return (false);
		parse_blank(p);
	}
	return (true);
}

t_bool			parse_spot_tab(t_parsing *p, t_tab *tab)
{
	t_spot			spot;

	if (!BIS(p->buff, '['))
		return (parse_error_before(p, "Expected '['"));
	parse_blank(p);
	if (BIS(p->buff, ']'))
		return (true);
	while (true)
	{
		ft_bzero(&spot, sizeof(t_spot));
		if (!parse_spot_instance(p, &spot))
			return (false);
		ft_tabadd(tab, &spot);
		parse_blank(p);
		if (!BIS(p->buff, ','))
			break ;
		parse_blank(p);
	}
	if (!BIS(p->buff, ']'))
		return (parse_error_before(p, "Expected ']' or ','"));
	return (true);
}
