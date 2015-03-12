/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/12 18:39:18 by jaguillo          #+#    #+#             */
/*   Updated: 2015/03/12 20:40:18 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include <stdlib.h>

t_shape			*get_shape(t_env *env, const char *name)
{
	int				i;

	i = -1;
	while (++i < env->shapes.length)
		if (ft_strequ(name, TG(t_shape, env->shapes, i)->name))
			return (TG(t_shape, env->shapes, i));
	return (NULL);
}

t_bool			del_shape(t_env *env, const char *name)
{
	int				i;

	i = -1;
	while (++i < env->shapes.length)
		if (ft_strequ(name, TG(t_shape, env->shapes, i)->name))
			return (ft_tabrem(&(env->shapes), i, 1), true);
	return (false);
}

void			kill_shape(t_shape *shape)
{
	int				i;

	if (shape->name != NULL)
		free(shape->name);
	i = -1;
	while (++i < shape->childs.length)
		kill_shape(TG(t_shape, shape->childs, i));
	free(shape->childs.data);
}
