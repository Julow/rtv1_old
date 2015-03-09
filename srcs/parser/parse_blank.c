/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_blank.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/09 14:14:34 by jaguillo          #+#    #+#             */
/*   Updated: 2015/03/09 15:49:57 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void			parse_blank(t_parsing *p)
{
	ft_parsewhite(p->buff);
	while (BIS(p->buff, '#'))
	{
		ft_parseendl(p->buff);
		ft_parsewhite(p->buff);
	}
}
