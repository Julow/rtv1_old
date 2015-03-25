/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/13 19:14:13 by jaguillo          #+#    #+#             */
/*   Updated: 2015/03/25 18:29:36 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "msg.h"
#include "mlx.h"
#include <stdlib.h>
#include <time.h>

static t_bool	ft_imageini(t_image *img, void *mlx, t_pt size)
{
	int				bpp;

	if ((img->img = mlx_new_image(mlx, size.x, size.y)) == NULL)
		return (false);
	if ((img->data = (t_byte*)mlx_get_data_addr(img->img, &bpp,
		&(img->l_size), &(img->endian))) == NULL)
		return (false);
	img->width = size.x;
	img->height = size.y;
	img->opp = bpp / 8;
	return (true);
}

static t_bool	init_render(t_render *r, t_env *env)
{
	r->env = env;
	if (FLAG(r->env->flags, FLAG_D))
		ft_printf(DEBUG_MLXINIT_MSG);
	if ((r->mlx = mlx_init()) == NULL)
		return (ft_fdprintf(2, ERROR_MLX_MSG), false);	r->scene = NULL;
	if (!ft_imageini(&(r->img), r->mlx, PT(WIN_WIDTH, WIN_HEIGHT)))
		return (ft_fdprintf(2, ERROR_IMG_MSG), false);
	return (true);
}

t_bool			render(t_env *env)
{
	t_render		render;
	clock_t			render_time;

	if (!init_render(&render, env))
		return (false);
	render_time = clock();
	draw_scene(&render, TG(t_scene, env->scenes, 0));
	render_time = (clock() - render_time) * 1000 / CLOCKS_PER_SEC;
	if (FLAG(env->flags, FLAG_D))
		ft_printf(DEBUG_TIME_MSG, (int)render_time);
	if (!init_window(&render))
		return (false);
	if (FLAG(env->flags, FLAG_D))
		ft_printf(DEBUG_MLXLOOP_MSG);
	mlx_loop(render.mlx);
	return (true);
}

void			destroy_render(t_render *r)
{
	if (FLAG(r->env->flags, FLAG_D))
		ft_printf(DEBUG_EXIT_MSG);
	mlx_destroy_window(r->mlx, r->win);
	exit(0);
}
