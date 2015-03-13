/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/13 19:37:54 by jaguillo          #+#    #+#             */
/*   Updated: 2015/03/13 19:45:27 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "msg.h"

int				key_hook(int key, t_render *r)
{
	if (key == ESC_KEY)
		return (destroy_render(r), 0);
	if (FLAG(r->env->flags, FLAG_D))
		ft_printf(DEBUG_KEYHOOK_MSG, key);
	return (0);
}
