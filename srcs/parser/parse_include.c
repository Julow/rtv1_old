/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_include.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/13 14:18:52 by jaguillo          #+#    #+#             */
/*   Updated: 2015/03/13 18:27:07 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "msg.h"

t_bool			parse_include(t_parsing *p)
{
	ft_stringclr(p->tmp);
	if (!ft_parsequote(p->buff, p->tmp))
		return (parse_error_before(p, "Expect string"));
	if (ft_strequ(p->file, p->tmp->content))
		return (ft_fdprintf(2, ERROR_INCLOOP_MSG, p->file, p->line), false);
	if (!parse_file(p->env, p->tmp->content))
		return (ft_fdprintf(2, ERROR_INCLUDE_MSG, p->tmp->content, p->file, p->line), false);
	return (true);
}
