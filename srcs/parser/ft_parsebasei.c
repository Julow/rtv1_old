/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsebasei.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/10 14:31:09 by jaguillo          #+#    #+#             */
/*   Updated: 2015/03/10 14:39:21 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

#define LOWER(c)		(((c) >= 'A' && (c) <= 'Z') ? (c) - 32 : (c))

static int		ft_strichri(const char *str, char c)
{
	char			*tmp;

	tmp = (char*)str;
	c = LOWER(c);
	while (LOWER(*tmp) != c)
	{
		if (*tmp == '\0')
			return (-1);
		tmp++;
	}
	return (tmp - str);
}

t_ulong			ft_parsebasei(t_buff *buff, const char *base)
{
	const t_uint	base_len = ft_strlen(base);
	t_ulong			nb;
	int				tmp;

	nb = 0;
	while ((tmp = ft_strichri(base, BG(buff))) != -1)
		nb = nb * base_len + tmp;
	return (nb);
}
