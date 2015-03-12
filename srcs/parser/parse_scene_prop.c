/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_scene_prop.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/09 23:49:43 by jaguillo          #+#    #+#             */
/*   Updated: 2015/03/12 16:04:50 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static t_bool	scene_prop(t_parsing *p, t_scene *scene, const char *prop)
{
	if (ft_strequ(prop, "camera_pos"))
		return (parse_pos(p, &(scene->pos)));
	else if (ft_strequ(prop, "camera_dirr"))
		return (parse_pos(p, (t_pos*)&(scene->dirr)));
	else if (ft_strequ(prop, "ambient"))
		return ((scene->ambient = ft_parsedouble(p->buff)), true);
	else if (ft_strequ(prop, "background"))
		return (parse_color(p, &(scene->background)));
	else if (ft_strequ(prop, "shapes"))
		return (parse_shape_tab(p, &(scene->shapes)));
	else
		return (parse_error_undef(p, "scene property"));
}

t_bool			parse_scene_prop(t_parsing *p, t_scene *scene)
{
	ft_stringclr(p->tmp);
	ft_parsesubf(p->buff, p->tmp, &ft_isword);
	parse_blank(p);
	if (!BIS(p->buff, ':'))
		return (parse_error_before(p, "Expected ':'"));
	parse_blank(p);
	if (!scene_prop(p, scene, p->tmp->content))
		return (false);
	parse_blank(p);
	if (!BIS(p->buff, ';'))
		return (parse_error_before(p, "Expected ';'"));
	return (true);
}
