/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/09 12:54:05 by jaguillo          #+#    #+#             */
/*   Updated: 2015/03/09 15:27:41 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void		init_env(t_env *env)
{
	ft_tabini(&(env->scenes), sizeof(t_scene));
	ft_tabini(&(env->shapes), sizeof(t_shape));
}

static void		parse_argv(t_env *env, int argc, char **argv)
{
	int				i;

	i = 0;
	while (++i < argc)
		parse_file(env, argv[i]);
}

int				main(int argc, char **argv)
{
	t_env			env;

	init_env(&env);
	parse_argv(&env, argc, argv);
	if (env.scenes.length <= 0)
		return (ft_fdprintf(2, FATAL "0 scene loaded.\n"), 1);
	return (0);
}
