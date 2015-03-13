/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_scene.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/09 17:19:06 by jaguillo          #+#    #+#             */
/*   Updated: 2015/03/13 18:59:55 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "msg.h"

static t_bool	parse_scene_name(t_parsing *p, t_scene *scene)
{
	ft_stringclr(p->tmp);
	ft_parsesubf(p->buff, p->tmp, &ft_isword);
	if (p->tmp->length <= 0)
		return (parse_error_before(p, "Expected scene name"));
	scene->name = ft_strdup(p->tmp->content);
	if (FLAG(p->env->flags, FLAG_D))
		ft_printf(DEBUG_SCENE_MSG, scene->name, p->file, p->line);
	if (del_scene(p->env, p->tmp->content))
		parse_warning_redef(p, "scene");
	return (true);
}

t_bool			parse_scene(t_parsing *p)
{
	t_scene			scene;

	ft_bzero(&scene, sizeof(t_scene));
	ft_tabini(&(scene.shapes), sizeof(t_shape));
	ft_tabini(&(scene.spots), sizeof(t_shape));
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
