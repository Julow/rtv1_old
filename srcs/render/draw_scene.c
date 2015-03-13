/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/13 19:54:21 by jaguillo          #+#    #+#             */
/*   Updated: 2015/03/13 20:07:16 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "msg.h"

void			draw_scene(t_render *r, t_scene *scene)
{
	r->scene = scene;
	ft_printf(RENDER_SCENE_MSG, scene->name);
}
