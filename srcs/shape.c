/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/12 18:39:18 by jaguillo          #+#    #+#             */
/*   Updated: 2015/03/25 08:33:55 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include <stdlib.h>

void			init_shape(t_shape *shape)
{
	shape->type = NONE;
	shape->name = NULL;
	shape->pos = POS(0, 0, 0);
	shape->dirr = VECTOR(0, 0, 0);
	shape->color = C(0xFF000000);
	shape->scale = 1.0;
	shape->ambient = 0.1;
	shape->reflect = 0.0;
	shape->bright = 0.0;
	shape->width = 0.0;
	shape->height = 0.0;
	shape->radius = 0.0;
	ft_tabini(&(shape->childs), sizeof(t_shape));
	shape->m = MATRIX();
}

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
