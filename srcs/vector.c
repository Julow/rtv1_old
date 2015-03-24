/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/24 19:47:23 by jaguillo          #+#    #+#             */
/*   Updated: 2015/03/24 19:50:20 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include <math.h>

void			ft_vnorme(t_vector *v)
{
	double			dist;

	dist = sqrt(SQ(v->x) + SQ(v->y) + SQ(v->z));
	v->x /= dist;
	v->y /= dist;
	v->z /= dist;
}

void			ft_vmultm(t_vector *dst, t_matrix *m, t_vector *v)
{
	dst->x = M(m, 0, 0) * v->x;
	dst->x += M(m, 1, 0) * v->y;
	dst->x += M(m, 2, 0) * v->z;
	dst->y = M(m, 0, 1) * v->x;
	dst->y += M(m, 1, 1) * v->y;
	dst->y += M(m, 2, 1) * v->z;
	dst->z = M(m, 0, 2) * v->x;
	dst->z += M(m, 1, 2) * v->y;
	dst->z += M(m, 2, 2) * v->z;
}
