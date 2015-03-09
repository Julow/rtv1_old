/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/09 19:34:56 by jaguillo          #+#    #+#             */
/*   Updated: 2015/03/09 19:42:04 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include <stdlib.h>

void			kill_scene(t_scene *scene)
{
	int				i;

	if (scene->name != NULL)
		free(scene->name);
	i = -1;
	while (++i < scene->shapes.length)
		kill_shape(TG(t_shape, scene->shapes, i));
}

void			kill_shape(t_shape *shape)
{
	int				i;

	if (shape->name != NULL)
		free(shape->name);
	i = -1;
	while (++i < shape->childs.length)
		kill_shape(TG(t_shape, shape->childs, i));
}
