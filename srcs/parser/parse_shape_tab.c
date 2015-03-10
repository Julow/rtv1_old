/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_shape_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/09 23:43:18 by jaguillo          #+#    #+#             */
/*   Updated: 2015/03/10 16:24:30 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_bool			parse_shape_tab(t_parsing *p, t_tab *tab)
{
	if (!BIS(p->buff, '['))
		return (parse_error_before(p, "Expected '['"));
	parse_blank(p);
	return (false);
	(void)tab;
	parse_blank(p);
	if (!BIS(p->buff, ']'))
		return (parse_error_before(p, "Expected ']'"));
	return (true);
}
