/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_scene.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/09 17:19:06 by jaguillo          #+#    #+#             */
/*   Updated: 2015/03/10 01:22:08 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static t_bool	parse_scene_name(t_parsing *p, t_scene *scene)
{
	ft_stringclr(p->tmp);
	ft_parsesubf(p->buff, p->tmp, &ft_isword);
	if (p->tmp->length <= 0)
		return (parse_error_before(p, "Expected scene name"));
	scene->name = ft_strdup(p->tmp->content);
	return (true);
}

t_bool			parse_scene(t_parsing *p)
{
	t_scene			scene;

	scene = (t_scene){0};
	ft_tabini(&(scene.shapes), sizeof(t_shape));
	if (!parse_scene_name(p, &scene))
		return (false);
	parse_blank(p);
	if (!BIS(p->buff, '{'))
		return (parse_error_before(p, "Expected '{'"), kill_scene(&scene), 0);
	parse_blank(p);
	while (!BIS(p->buff, '}') && !BEOF(p->buff))
	{
		if (!parse_scene_prop(p, &scene))
			return (kill_scene(&scene), false);
		parse_blank(p);
	}
	ft_tabadd(&(p->env->scenes), &scene);
	return (true);
}
