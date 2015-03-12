/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/09 18:03:09 by jaguillo          #+#    #+#             */
/*   Updated: 2015/03/12 16:02:43 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "msg.h"

t_bool			parse_error_before(t_parsing *p, const char *msg)
{
	ft_stringclr(p->tmp);
	if (ft_isword(BG(p->buff)))
		ft_parsesubf(p->buff, p->tmp, &ft_isword);
	else
		ft_stringaddc(p->tmp, BG(p->buff));
	ft_fdprintf(2, ERROR_BEFORE_MSG, msg, p->tmp->content, p->file, p->line);
	return (false);
}

t_bool			parse_error_undef(t_parsing *p, const char *msg)
{
	ft_fdprintf(2, ERROR_UNDEF_MSG, msg, p->tmp->content, p->file, p->line);
	return (false);
}

t_bool			parse_error_redef(t_parsing *p, const char *msg)
{
	ft_fdprintf(2, ERROR_REDEF_MSG, msg, p->tmp->content, p->file, p->line);
	return (false);
}
