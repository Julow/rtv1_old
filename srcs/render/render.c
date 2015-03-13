/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/13 19:14:13 by jaguillo          #+#    #+#             */
/*   Updated: 2015/03/13 20:10:09 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "msg.h"
#include "mlx.h"
#include <stdlib.h>

static t_bool	ft_imageini(t_image *img, void *mlx, t_pt size)
{
	int				bpp;

	if ((img->img = mlx_new_image(mlx, size.x, size.y)) == NULL)
		return (false);
	if ((img->data = (t_byte*)mlx_get_data_addr(img->img, &bpp, &img->l_size,
		&img->endian)) == NULL)
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
		return (ft_fdprintf(2, ERROR_MLX_MSG), false);
	if ((r->win = mlx_new_window(r->mlx,
		WIN_WIDTH, WIN_HEIGHT, WIN_TITLE)) == NULL)
		return (ft_fdprintf(2, ERROR_WIN_MSG), false);
	r->scene = NULL;
	if (!ft_imageini(&(r->img), r->mlx, PT(WIN_WIDTH, WIN_HEIGHT)))
		return (ft_fdprintf(2, ERROR_IMG_MSG), false);
	return (true);
}

t_bool			render(t_env *env)
{
	t_render		render;

	if (!init_render(&render, env))
		return (false);
	mlx_expose_hook(render.win, &expose_hook, &render);
	mlx_key_hook(render.win, &key_hook, &render);
	draw_scene(&render, TG(t_scene, env->scenes, 0));
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
