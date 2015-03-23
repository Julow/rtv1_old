/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/13 19:54:21 by jaguillo          #+#    #+#             */
/*   Updated: 2015/03/23 19:49:39 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "msg.h"

void			draw_scene(t_render *r, t_scene *scene)
{
	t_pt			pt;

	r->scene = scene;
	ft_printf(RENDER_SCENE_MSG, scene->name);
	pt = PT(-1, -1);
	while (++pt.y < r->img.height)
	{
		pt.x = -1;
		while (++pt.x < r->img.width)
			ft_drawpt(&(r->img), pt, ray_trace(r));
	}
}
