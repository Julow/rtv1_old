/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expose.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/13 19:32:34 by jaguillo          #+#    #+#             */
/*   Updated: 2015/03/13 20:10:47 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "msg.h"
#include "mlx.h"

int				expose_hook(t_render *r)
{
	if (FLAG(r->env->flags, FLAG_D))
		ft_printf(DEBUG_EXPOSE_MSG);
	mlx_put_image_to_window(r->mlx, r->win, r->img.img, 0, 0);
	return (0);
}
