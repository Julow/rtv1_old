/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/24 19:52:47 by jaguillo          #+#    #+#             */
/*   Updated: 2015/03/25 18:07:17 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MATH_H
# define FT_MATH_H

/*
** ft_math.h
** ---
** Contains advenced math functions
** ---
** Include math.h
** Use the lib math (-lm)
*/

# include "libft.h"
# include <math.h>

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

# define SQ(n)			((n) * (n))

# define MATRIX()		((t_matrix){{[0 ... 2] = {[0 ... 2] = 0.0}}})
# define M(m,x,y)		((m)->d[(y)][(x)])

# define VECTOR(x,y,z)	((t_vector){(x), (y), (z)})

void			ft_mmult(t_matrix *dst, t_matrix *m1, t_matrix *m2);
void			ft_mrot(t_matrix *m, t_vector *v, t_bool rev);

void			ft_vnorme(t_vector *v);
void			ft_vmultm(t_vector *dst, t_matrix *m, t_vector *v);

#endif
