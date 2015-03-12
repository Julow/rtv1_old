/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/12 18:37:31 by jaguillo          #+#    #+#             */
/*   Updated: 2015/03/12 18:39:40 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

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
