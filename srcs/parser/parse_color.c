/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/10 12:44:21 by jaguillo          #+#    #+#             */
/*   Updated: 2015/03/25 18:07:12 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_bool			parse_color(t_parsing *p, t_color *color)
{
	t_ulong			tmp;

	*color = C(0);
	if (!ft_parsenumber(p->buff, &tmp))
			return (parse_error_before(p, "Expect color"));
	if (tmp > 0xFFFFFFFF)
		return (parse_error_before(p, "Bad color"));
	*color = C((t_uint)tmp);
	return (true);
}
