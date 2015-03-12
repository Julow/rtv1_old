/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/12 20:46:47 by jaguillo          #+#    #+#             */
/*   Updated: 2015/03/12 21:21:06 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "msg.h"

static t_bool	parse_options(t_env *env, const char *arg)
{
	if (arg[0] != '-')
		return (false);
	while (*(++arg) != '\0')
	{
		if (*arg == 's')
			env->flags |= FLAG_S;
		else if (*arg == 'c')
			env->flags |= FLAG_C;
		else if (*arg == '-')
			return (false);
		else
			return (ft_fdprintf(2, W_BAD_OPTION_MSG, *arg), true);
	}
	return (true);
}

t_bool			parse_argv(t_env *env, int argc, char **argv)
{
	int				i;

	i = 1;
	while (i < argc && parse_options(env, argv[i]))
		i++;
	while (i < argc)
	{
		parse_file(env, argv[i]);
		i++;
	}
	return (true);
}
