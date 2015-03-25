/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/25 08:37:44 by jaguillo          #+#    #+#             */
/*   Updated: 2015/03/25 13:57:23 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "msg.h"
#include <mlx.h>

static int		expose_hook(t_render *r)
{
	if (FLAG(r->env->flags, FLAG_D))
		ft_printf(DEBUG_EXPOSE_MSG);
	mlx_put_image_to_window(r->mlx, r->win, r->img.img, 0, 0);
	return (0);
}

static int		key_hook(int key, t_render *r)
{
	if (key == ESC_KEY)
		return (destroy_render(r), 0);
	if (FLAG(r->env->flags, FLAG_D))
		ft_printf(DEBUG_KEYHOOK_MSG, key);
	return (0);
}

t_bool			init_window(t_render *r)
{
	if (FLAG(r->env->flags, FLAG_D))
		ft_printf(DEBUG_WININIT_MSG);
	r->win = mlx_new_window(r->mlx, WIN_WIDTH, WIN_HEIGHT, WIN_TITLE);
	if (r->win == NULL)
		return (ft_fdprintf(2, ERROR_WIN_MSG), false);
	mlx_expose_hook(r->win, &expose_hook, r);
	mlx_key_hook(r->win, &key_hook, r);
	return (true);
}
