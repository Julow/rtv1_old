/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_rot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/24 19:49:25 by jaguillo          #+#    #+#             */
/*   Updated: 2015/03/25 08:32:25 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

static void		ft_mrotx(t_matrix *m, double a)
{
	t_matrix		rot;
	t_matrix		tmp;
	double			c;
	double			s;

	c = cos(a);
	s = sin(a);
	tmp = *m;
	rot = (t_matrix){{{1, 0, 0}, {0, c, -s}, {0, s, c}}};
	ft_mmult(m, &rot, &tmp);
}

static void		ft_mroty(t_matrix *m, double a)
{
	t_matrix		rot;
	t_matrix		tmp;
	double			c;
	double			s;

	c = cos(a);
	s = sin(a);
	tmp = *m;
	rot = (t_matrix){{{c, 0, s}, {0, 1, 0}, {-s, 0, c}}};
	ft_mmult(m, &rot, &tmp);
}

static void		ft_mrotz(t_matrix *m, double a)
{
	t_matrix		rot;
	t_matrix		tmp;
	double			c;
	double			s;

	c = cos(a);
	s = sin(a);
	tmp = *m;
	rot = (t_matrix){{{c, -s, 0}, {s, c, 0}, {0, 0, 1}}};
	ft_mmult(m, &rot, &tmp);
}

void			ft_mrot(t_matrix *m, t_vector *v, t_bool rev)
{
	*m = (t_matrix){{{1, 0, 0}, {0, 1, 0}, {0, 0, 1}}};
	if (!rev)
	{
		ft_mrotx(m, v->x);
		ft_mroty(m, v->y);
		ft_mrotz(m, v->z);
	}
	else
	{
		ft_mrotz(m, -v->z);
		ft_mroty(m, -v->y);
		ft_mrotx(m, -v->x);
	}
}
