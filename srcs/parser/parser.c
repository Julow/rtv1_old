/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/09 13:43:33 by jaguillo          #+#    #+#             */
/*   Updated: 2015/03/09 20:19:24 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>

static t_bool	parse_identifier(t_parsing *p)
{
	ft_stringclr(p->tmp);
	ft_parsesubf(p->buff, p->tmp, &ft_isword);
	if (ft_strequ(p->tmp->content, "shape"))
		return (parse_shape(p));
	else if (ft_strequ(p->tmp->content, "scene"))
		return (parse_scene(p));
	return (parse_error_undef(p, "identifier", p->tmp->content));
}

void			parse_file(t_env *env, const char *file)
{
	int				fd;
	t_parsing		p;
	t_buff			buff;

	if ((fd = open(file, O_RDONLY)) < 0)
	{
		ft_fdprintf(2, ERROR "%s: '%s'\n", strerror(errno), file);
		return ;
	}
	buff = INBUFF(fd, MAL(char, BUFF_SIZE), BUFF_SIZE);
	p = (t_parsing){env, &buff, ft_stringnew(), file, 1};
	parse_blank(&p);
	while (!BEOF(p.buff))
	{
		if (!parse_identifier(&p))
			break ;
		parse_blank(&p);
	}
	free(buff.data);
	ft_stringkil(p.tmp);
}
