/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/12 18:37:31 by jaguillo          #+#    #+#             */
/*   Updated: 2015/03/25 08:33:43 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include <stdlib.h>

void			init_scene(t_scene *scene)
{
	scene->name = NULL;
	scene->pos = POS(0, 0, 0);
	scene->dirr = VECTOR(0, 0, 0);
	scene->ambient = 0.1;
	scene->background = C(0xFF000000);
	ft_tabini(&(scene->shapes), sizeof(t_shape));
	ft_tabini(&(scene->spots), sizeof(t_shape));
}

t_scene			*get_scene(t_env *env, const char *name)
{
	int				i;

	i = -1;
	while (++i < env->scenes.length)
		if (ft_strequ(name, TG(t_scene, env->scenes, i)->name))
			return (TG(t_scene, env->scenes, i));
	return (NULL);
}

t_bool			del_scene(t_env *env, const char *name)
{
	int				i;

	i = -1;
	while (++i < env->scenes.length)
		if (ft_strequ(name, TG(t_scene, env->scenes, i)->name))
			return (ft_tabrem(&(env->scenes), i, 1), true);
	return (false);
}

void			kill_scene(t_scene *scene)
{
	if (scene->name != NULL)
		free(scene->name);
	free(scene->shapes.data);
	free(scene->spots.data);
}
