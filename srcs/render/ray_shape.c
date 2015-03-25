/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_shape.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/25 18:12:30 by jaguillo          #+#    #+#             */
/*   Updated: 2015/03/25 18:19:41 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_bool			ray_shape(t_ray *ray, t_shape *shape)
{
	if (shape->type == SPHERE)
		return (ray_shape_sphere(ray, shape));
	return (false);
}
