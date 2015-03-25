/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/13 19:54:21 by jaguillo          #+#    #+#             */
/*   Updated: 2015/03/25 13:57:29 by jaguillo         ###   ########.fr       */
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

static t_bool	ray_collide(t_ray *ray, t_shape *shape)
{
	double			a;
	double			b;
	double			c;

	a = ray->dirr.x * ray->dirr.x + ray->dirr.y * ray->dirr.y + ray->dirr.z * ray->dirr.z;
	b = 2 * (ray->camera.x * ray->dirr.x + ray->camera.y * ray->dirr.y + ray->camera.z * ray->dirr.z);
	c = ray->camera.x * ray->camera.x + ray->camera.y * ray->camera.y + ray->camera.z * ray->camera.z - shape->radius * shape->radius;
	if ((b * b - (4 * a * c)) >= 0)
		return (true);
	return (false);
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
		if (ray_collide(&tmp, shape))
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
		{
			// ft_printf("draw px %d.%d == %x\n", pt.x, pt.y, ray_trace(r, pt).u);
			ft_drawpt(&(r->img), pt, ray_trace(r, pt));
		}
	}
	// pt = PT(WIN_WIDTH / 2, WIN_HEIGHT / 2);
	// ft_drawpt(&(r->img), pt, ray_trace(r, pt));
}
