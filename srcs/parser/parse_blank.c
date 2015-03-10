/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_blank.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/09 14:14:34 by jaguillo          #+#    #+#             */
/*   Updated: 2015/03/10 17:20:18 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void			parse_blank(t_parsing *p)
{
	while (1)
	{
		ft_parsespace(p->buff);
		while (BIS(p->buff, '\n'))
		{
			p->line++;
			ft_parsespace(p->buff);
		}
		if (BIS(p->buff, '#'))
		{
			ft_parseendl(p->buff);
			p->line++;
		}
		else
			break ;
	}
}
