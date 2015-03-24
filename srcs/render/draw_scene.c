/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/13 19:54:21 by jaguillo          #+#    #+#             */
/*   Updated: 2015/03/24 19:49:13 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "msg.h"

static void		init_draw_scene(t_render *r, t_scene *scene)
{
	int				i;
	t_shape			*shape;

	r->scene = scene;
	i = -1;
	while (++i < scene->shapes.length)
	{
		shape = TG(t_shape, scene->shapes, i);
		ft_mrot(&(shape->m), &(shape->dirr), false);
		ft_mrot(&(shape->mrev), &(shape->dirr), true);
	}
}

t_color			ray_trace(t_render *r, t_pt pt)
{
	t_ray			ray;

	ray.pos = POS(0, 0, 0);
	ray.dirr = VECTOR(FOV, WIN_WIDTH / 2 - pt.x, WIN_HEIGHT / 2 - pt.y);
	ft_vnorme(&(ray.dirr));
	return (r->scene->background);
}

void			draw_scene(t_render *r, t_scene *scene)
{
	t_pt			pt;

	init_draw_scene(r, scene);
	ft_printf(RENDER_SCENE_MSG, scene->name);
	// pt = PT(-1, -1);
	// while (++pt.y < r->img.height)
	// {
	// 	pt.x = -1;
	// 	while (++pt.x < r->img.width)
	// 		ft_drawpt(&(r->img), pt, ray_trace(r, pt));
	// }
	pt = PT(WIN_WIDTH / 2, WIN_HEIGHT / 2);
	ft_drawpt(&(r->img), pt, ray_trace(r, pt));
}
