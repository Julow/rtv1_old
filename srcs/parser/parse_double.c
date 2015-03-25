/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_double.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/25 15:41:28 by jaguillo          #+#    #+#             */
/*   Updated: 2015/03/25 18:07:07 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_bool			parse_double(t_parsing *p, double *d)
{
	if (!ft_parsedouble(p->buff, d))
		return (parse_error_before(p, "Expect number"));
	return (true);
}
