/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/09 12:54:05 by jaguillo          #+#    #+#             */
/*   Updated: 2015/03/10 17:11:25 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "msg.h"

static void		init_builtin_shape(t_env *env, t_shape_t type, const char *name)
{
	t_shape			*shape;

	shape = ft_tabadd0(&(env->shapes));
	shape->name = ft_strdup(name);
	shape->type = type;
}

static void		init_env(t_env *env)
{
	ft_tabini(&(env->scenes), sizeof(t_scene));
	ft_tabini(&(env->shapes), sizeof(t_shape));
	init_builtin_shape(env, NONE, "None");
	init_builtin_shape(env, SPHERE, "Sphere");
	init_builtin_shape(env, CONE, "Cone");
	init_builtin_shape(env, CYLINDRE, "Cylindre");
	init_builtin_shape(env, PLANE, "Plane");
}

static t_bool	parse_argv(t_env *env, int argc, char **argv)
{
	int				i;

	i = 0;
	while (++i < argc)
		parse_file(env, argv[i]);
	if (env->scenes.length <= 0)
		return (ft_printf(NO_SCENE_MSG), false);
	ft_printf(SCENE_LOAD_MSG, env->scenes.length);
	if (env->shapes.length <= SHAPE_T_COUNT)
		ft_printf(NO_SHAPE_MSG);
	else
		ft_printf(SHAPE_LOAD_MSG, env->shapes.length - SHAPE_T_COUNT);
	return (true);
}

int				main(int argc, char **argv)
{
	t_env			env;

	init_env(&env);
	if (!parse_argv(&env, argc, argv))
		return (false);
	return (0);
}
