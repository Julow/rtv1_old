/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/09 13:43:33 by jaguillo          #+#    #+#             */
/*   Updated: 2015/03/25 18:07:08 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "msg.h"
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

#define P_DESTROY(p)	(free(p.buff->data), ft_stringkil(p.tmp))

static t_bool	parse_identifier(t_parsing *p)
{
	if (!ft_isword(BG(p->buff)))
		return (parse_error_before(p, "Expected identifier"));
	ft_stringclr(p->tmp);
	ft_parsesubf(p->buff, p->tmp, &ft_isword);
	parse_blank(p);
	if (ft_strequ(p->tmp->content, "shape"))
		return (parse_shape(p));
	else if (ft_strequ(p->tmp->content, "scene"))
		return (parse_scene(p));
	else if (ft_strequ(p->tmp->content, "include"))
		return (parse_include(p));
	return (parse_error_undef(p, "identifier"));
}

t_bool			parse_file(t_env *env, const char *file)
{
	int				fd;
	t_parsing		p;
	t_buff			buff;

	if ((fd = open(file, O_RDONLY)) < 0)
		return (ft_fdprintf(2, ERROR_OPEN_MSG, strerror(errno), file), false);
	buff = BUFF(fd, MAL(char, BUFF_SIZE), BUFF_SIZE);
	p = (t_parsing){env, &buff, ft_stringnew(), file, 1};
	parse_blank(&p);
	while (!BEOF(p.buff))
	{
		if (!parse_identifier(&p))
		{
			if (FLAG(env->flags, FLAG_D))
				ft_printf(DEBUG_FAIL_MSG, p.file, p.line);
			return (P_DESTROY(p), false);
		}
		parse_blank(&p);
	}
	close(fd);
	P_DESTROY(p);
	return (true);
}
