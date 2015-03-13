/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_escape.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/13 14:28:28 by jaguillo          #+#    #+#             */
/*   Updated: 2015/03/13 14:35:30 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

char			*g_escapes = "a\ab\bf\fn\nr\rt\tv\v0\0\0";

char			ft_escape(char c)
{
	char			*escs;

	escs = g_escapes + 1;
	while (*escs != c)
	{
		if (*escs == '\0')
			return (c);
		escs += 2;
	}
	return (escs[-1]);
}

char			ft_unescape(char c)
{
	char			*escs;

	escs = g_escapes;
	while (*escs != '\0')
	{
		if (*escs == c)
			return (escs[1]);
		escs += 2;
	}
	return (c);
}
