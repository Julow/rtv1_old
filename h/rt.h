/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/09 12:51:58 by jaguillo          #+#    #+#             */
/*   Updated: 2015/03/10 17:27:19 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_H
# define RT_H

# include "libft.h"

typedef enum	e_shape_t
{
	NONE,
	SPHERE,
	CONE,
	CYLINDRE,
	PLANE,
	SHAPE_T_COUNT
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
	t_color			background;
	t_tab			shapes;
}				t_scene;

typedef struct	s_shape
{
	t_shape_t		type;
	char			*name;
	t_pos			pos;
	t_dirr			dirr;
	t_color			color;
	double			reflect;
	double			bright;
	double			width;
	double			height;
	double			radius;
	t_tab			childs;
}				t_shape;

typedef struct	s_env
{
	t_tab			scenes;
	t_tab			shapes;
}				t_env;

/*
** ========================================================================== **
** parser
*/

/*
** parse_file
** Parse a file
*/
void			parse_file(t_env *env, const char *file);

/*
** internal
*/

# define BUFF_SIZE		512

# define BEOF(b)		((b)->fd < 0)

typedef struct	s_parsing
{
	t_env			*env;
	t_buff			*buff;
	t_string		*tmp;
	const char		*file;
	int				line;
}				t_parsing;

t_bool			parse_shape(t_parsing *p);
t_bool			parse_shape_prop(t_parsing *p, t_shape *shape);

t_bool			parse_scene(t_parsing *p);
t_bool			parse_scene_prop(t_parsing *p, t_scene *scene);

t_bool			parse_pos(t_parsing *p, t_pos *pos);
t_bool			parse_shape_tab(t_parsing *p, t_tab *tab);

t_bool			parse_error_before(t_parsing *p, const char *msg);
t_bool			parse_error_undef(t_parsing *p, const char *msg, const char *s);

void			parse_blank(t_parsing *p);
t_bool			parse_color(t_parsing *p, t_color *color);

t_ulong			ft_parsebasei(t_buff *buff, const char *base);
t_ulong			ft_parsenumber(t_buff *buff);

/*
** ========================================================================== **
** other
*/

t_shape			*get_shape(t_env *env, const char *name);

void			kill_scene(t_scene *scene);
void			kill_shape(t_shape *shape);

#endif
