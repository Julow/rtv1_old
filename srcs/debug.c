/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/24 18:30:25 by jaguillo          #+#    #+#             */
/*   Updated: 2015/03/24 19:40:03 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void			print_vector(t_vector *v)
{
	ft_printf("V{ %f, %f, %f }\n", v->x, v->y, v->z);
}

void			print_ray(t_ray *ray)
{
	ft_putstr("pos: ");
	print_vector((t_vector*)(&(ray->pos)));
	ft_putstr("dirr: ");
	print_vector((t_vector*)(&(ray->dirr)));
}
