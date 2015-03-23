/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/23 14:45:37 by jaguillo          #+#    #+#             */
/*   Updated: 2015/03/23 18:18:31 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include <math.h>

void			ft_mmult(t_matrix *dst, t_matrix *m1, t_matrix *m2)
{
	int				i;
	int				j;

	i = -1;
	while (++i < 3)
	{
		j = -1;
		while (++j < 3)
		{
			M(dst, i, j) = M(m1, 0, j) * M(m2, i, 0);
			M(dst, i, j) += M(m1, 1, j) * M(m2, i, 1);
			M(dst, i, j) += M(m1, 2, j) * M(m2, i, 2);
		}
	}
}

void			ft_minit(t_matrix *m, t_dirr dirr, double scale)
{
	t_matrix	tmp;
	t_matrix	mrot;
	double		c;
	double		s;

	tmp = (t_matrix){{{scale, 0, 0}, {0, scale, 0}, {0, 0, scale}}};
	c = cos(dirr.yaw);
	s = sin(dirr.yaw);
	mrot = (t_matrix){{{1, 0, 0}, {0, c, -s}, {0, s, c}}};
	ft_mmult(m, &tmp, &mrot);
	c = cos(dirr.pitch);
	s = sin(dirr.pitch);
	mrot = (t_matrix){{{c, 0, s}, {0, 1, 0}, {-s, 0, c}}};
	ft_mmult(&tmp, m, &mrot);
	c = cos(dirr.roll);
	s = sin(dirr.roll);
	mrot = (t_matrix){{{c, -s, 0}, {s, c, 0}, {0, 0, 1}}};
	ft_mmult(m, &tmp, &mrot);
}
