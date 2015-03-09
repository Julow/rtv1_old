/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/09 18:03:09 by jaguillo          #+#    #+#             */
/*   Updated: 2015/03/09 20:20:06 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_bool			parse_error_before(t_parsing *p, const char *msg)
{
	ft_stringclr(p->tmp);
	if (ft_isword(BG(p->buff)))
		ft_parsesubf(p->buff, p->tmp, &ft_isword);
	else
		ft_stringaddc(p->tmp, BG(p->buff));
	ft_fdprintf(2, ERROR "%s before '%s' at %s:%d\n",
		msg, p->tmp->content, p->file, p->line);
	return (false);
}

t_bool			parse_error_undef(t_parsing *p, const char *msg, const char *s)
{
	ft_fdprintf(2, ERROR "Undefined %s '%s' at %s:%d\n",
		msg, s, p->file, p->line);
	return (false);
}