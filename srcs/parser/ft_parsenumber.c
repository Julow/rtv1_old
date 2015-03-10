/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsenumber.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/10 15:10:43 by jaguillo          #+#    #+#             */
/*   Updated: 2015/03/10 15:14:59 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

/*
** Parse an integer
** decimal/hexa/octal/binary
** hexa is case insensitive
*/
t_ulong			ft_parsenumber(t_buff *buff)
{
	if (BIS(buff, '0'))
	{
		if (BIS(buff, 'x'))
			return (ft_parsebasei(buff, BASE_16));
		else if (BIS(buff, 'b'))
			return (ft_parsebase(buff, BASE_2));
		return (ft_parsebase(buff, BASE_8));
	}
	return (ft_parsebase(buff, BASE_10));
}
