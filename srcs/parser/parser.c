/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/09 13:43:33 by jaguillo          #+#    #+#             */
/*   Updated: 2015/03/09 16:34:56 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>

static void		parse_identifier(t_parsing *p)
{
	(void)p;
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
	p = (t_parsing){env, &buff, ft_stringnew()};
	parse_blank(&p);
	while (buff.fd >= 0)
	{
		parse_identifier(&p);
		parse_blank(&p);
	}
	free(buff.data);
	ft_stringkil(p.tmp);
}
