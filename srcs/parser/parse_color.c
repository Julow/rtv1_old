/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/10 12:44:21 by jaguillo          #+#    #+#             */
/*   Updated: 2015/03/10 15:16:50 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_bool			parse_color(t_parsing *p, t_color *color)
{
	*color = C(0);
	if (BIS(p->buff, '#'))
		color->u = (t_uint)ft_parsebasei(p->buff, BASE_16) | 0xFF000000;
	else
		color->u = (t_uint)ft_parsenumber(p->buff);
	return (true);
}
