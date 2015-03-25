/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/13 19:54:21 by jaguillo          #+#    #+#             */
/*   Updated: 2015/03/25 18:24:22 by jaguillo         ###   ########.fr       */
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
	t_ray			tmp;
	int				i;
	t_shape			*shape;

	ray.pos = POS(0, 0, 0);
	ray.dirr = VECTOR(FOV, WIN_WIDTH / 2 - pt.x, WIN_HEIGHT / 2 - pt.y);
	ft_vnorme(&(ray.dirr));
	i = -1;
	while (++i < r->scene->shapes.length)
	{
		shape = TG(t_shape, r->scene->shapes, i);
		tmp.pos = ray.pos;
		tmp.camera = POS(shape->pos.x - r->scene->pos.x, shape->pos.y - r->scene->pos.y, shape->pos.z - r->scene->pos.z);
		ft_vmultm(&(tmp.dirr), &(shape->m), &(ray.dirr));
		if (ray_shape(&tmp, shape))
			return (shape->color);
	}
	return (r->scene->background);
}

void			draw_scene(t_render *r, t_scene *scene)
{
	t_pt			pt;

	init_draw_scene(r, scene);
	if (FLAG(r->env->flags, FLAG_D))
		ft_printf(RENDER_SCENE_MSG, scene->name);
	pt = PT(-1, -1);
	while (++pt.y < r->img.height)
	{
		pt.x = -1;
		while (++pt.x < r->img.width)
			ft_drawpt(&(r->img), pt, ray_trace(r, pt));
	}
}
