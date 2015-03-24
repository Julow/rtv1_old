/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/24 19:52:47 by jaguillo          #+#    #+#             */
/*   Updated: 2015/03/24 19:57:06 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MATH_H
# define FT_MATH_H

/*
** ft_math.h
** ---
** Contains advenced math functions
** Use the lib math (-lm)
*/

# include "libft.h"
# include <math.h>

typedef struct	s_dirr
{
	double			yaw;
	double			pitch;
	double			roll;
}				t_dirr;

typedef struct	s_matrix
{
	double			d[3][3];
}				t_matrix;

typedef struct	s_vector
{
	double			x;
	double			y;
	double			z;
}				t_vector;

typedef struct	s_ray
{
	t_pos			pos;
	t_vector		dirr;
}				t_ray;

# define SQ(n)			((n) * (n))

# define MATRIX()		((t_matrix){{[0 ... 2] = {[0 ... 2] = 0.0}}})
# define M(m,x,y)		((m)->d[(y)][(x)])

# define VECTOR(x,y,z)	((t_vector){(x), (y), (z)})

void			ft_mmult(t_matrix *dst, t_matrix *m1, t_matrix *m2);
void			ft_mrot(t_matrix *m, t_dirr *dirr, t_bool rev);

void			ft_vnorme(t_vector *v);
void			ft_vmultm(t_vector *dst, t_matrix *m, t_vector *v);

/*
** debug
*/
void			print_vector(t_vector *v);
void			print_ray(t_ray *ray);

#endif
