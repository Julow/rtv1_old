/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/09 12:51:58 by jaguillo          #+#    #+#             */
/*   Updated: 2015/03/09 16:35:08 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_H
# define RT_H

# include "libft.h"
# include "ft_colors.h"

typedef enum	e_shape_t
{
	SPHERE,
	CONE,
	CYLINDRE,
	PLANE
}				t_shape_t;

typedef struct	s_dirr
{
	double			yaw;
	double			pitch;
	double			roll;
}				t_dirr;

typedef struct	s_scene
{
	char			*name;
	t_pos			pos;
	t_dirr			dirr;
	t_tab			shapes;
}				t_scene;

typedef struct	s_shape
{
	char			*name;
	t_pos			pos;
	t_dirr			dirr;
	t_color			color;
	double			reflect;
	double			bright;
	double			width; // plane only
	double			height; // plane and cone
	double			radius; // cone and sphere
	t_tab			childs;
}				t_shape;

typedef struct	s_env
{
	t_tab			scenes;
	t_tab			shapes;
}				t_env;

/*
** ========================================================================== **
** print
*/

# define FATAL			C_LRED "[Fatal Error]" C_RESET " "
# define ERROR			C_RED "[Error]" C_RESET " "
# define WARNING		C_YELLOW "[Warning]" C_RESET " "

/*
** ========================================================================== **
** parser
*/

typedef struct	s_parsing
{
	t_env			*env;
	t_buff			*buff;
	t_string		*tmp;
}				t_parsing;

void			parse_file(t_env *env, const char *file);

/*
** utils
*/

void			parse_blank(t_parsing *p);

/*
** ========================================================================== **
*/

#endif
