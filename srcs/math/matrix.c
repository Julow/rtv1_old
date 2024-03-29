/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/23 14:45:37 by jaguillo          #+#    #+#             */
/*   Updated: 2015/03/24 19:53:57 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

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
