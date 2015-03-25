/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_shape_sphere.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/25 18:12:58 by jaguillo          #+#    #+#             */
/*   Updated: 2015/03/25 18:43:18 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_bool			ray_shape_sphere(t_ray *ray, t_shape *shape)
{
	double			a;
	double			b;
	double			c;

	a = VSQUARE(ray->dirr);
	b = 2 * VMULTADD(ray->camera, ray->dirr);
	c = VSQUARE(ray->camera) - (shape->radius * shape->radius);
	if ((b * b - (4 * a * c)) >= 0)
		return (true);
	return (false);
}
