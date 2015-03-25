/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/09 12:51:58 by jaguillo          #+#    #+#             */
/*   Updated: 2015/03/25 18:19:05 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_H
# define RT_H

/*
** rtv1
** ---
** Options:
**  -d		Print loaded shapes and scenes (debug purpose)
**  --		Stop options parsing
*/

# include "libft.h"
# include "ft_math.h"

/*
** ========================================================================== **
** init
*/

# define FOV			150

/*
** Contains importants things
*/
typedef struct	s_env
{
	t_tab			scenes;
	t_tab			shapes;
	int				flags;
}				t_env;

# define FLAG_D			1

/*
** Parse argv
** Set the flags (t_env) with the options
** and start the parsing of files
*/
t_bool			parse_argv(t_env *env, int argc, char **argv);

/*
** ========================================================================== **
** objects
*/

typedef enum	e_shape_t
{
	NONE,
	SPHERE,
	CONE,
	CYLINDRE,
	PLANE,
	SHAPE_T_COUNT
}				t_shape_t;

typedef struct	s_scene
{
	char			*name;
	t_pos			pos;
	t_vector		dirr;
	double			ambient;
	t_color			background;
	t_tab			spots;
	t_tab			shapes;
}				t_scene;

typedef struct	s_shape
{
	t_shape_t		type;
	char			*name;
	t_pos			pos;
	t_vector		dirr;
	t_color			color;
	double			scale;
	double			ambient;
	double			reflect;
	double			bright;
	double			width;
	double			height;
	double			radius;
	t_tab			childs;
	t_matrix		m;
	t_matrix		mrev;
}				t_shape;

typedef struct	s_spot
{
	t_pos			pos;
	t_color			color;
	double			bright;
}				t_spot;

/*
** ========================================================================== **
** render
*/

typedef struct	s_render
{
	t_env			*env;
	void			*mlx;
	void			*win;
	t_image			img;
	t_matrix		mcamera;
	t_scene			*scene;
}				t_render;

typedef struct	s_ray
{
	t_pos			pos;
	t_vector		dirr;
	t_pos			camera;
}				t_ray;

# define WIN_WIDTH		500
# define WIN_HEIGHT		500

# define ESC_KEY		53

t_bool			render(t_env *env);
void			destroy_render(t_render *render);

t_bool			init_window(t_render *r);

void			draw_scene(t_render *r, t_scene *scene);

t_bool			ray_shape(t_ray *ray, t_shape *shape);
t_bool			ray_shape_sphere(t_ray *ray, t_shape *shape);

/*
** debug
*/
void			print_vector(t_vector *v);
void			print_ray(t_ray *ray);

/*
** ========================================================================== **
** parser
*/

/*
** Parse a file
*/
t_bool			parse_file(t_env *env, const char *file);

/*
** internal
*/

# define BUFF_SIZE		512

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
t_bool			parse_shape_inheritance(t_parsing *p, t_shape *shape);

t_bool			parse_scene(t_parsing *p);
t_bool			parse_scene_prop(t_parsing *p, t_scene *scene);

t_bool			parse_spot(t_parsing *p);

t_bool			parse_shape_tab(t_parsing *p, t_tab *tab);
t_bool			parse_spot_tab(t_parsing *p, t_tab *tab);

t_bool			parse_include(t_parsing *p);

t_bool			parse_error_before(t_parsing *p, const char *msg);
t_bool			parse_error_undef(t_parsing *p, const char *msg);
t_bool			parse_error_redef(t_parsing *p, const char *msg);
void			parse_warning_redef(t_parsing *p, const char *msg);

void			parse_blank(t_parsing *p);
t_bool			parse_pos(t_parsing *p, t_pos *pos);
t_bool			parse_color(t_parsing *p, t_color *color);
t_bool			parse_double(t_parsing *p, double *d);

t_bool			ft_parsequote(t_buff *buff, t_string *dst);
char			ft_escape(char c);
char			ft_unescape(char c);

/*
** ========================================================================== **
** other
*/

void			init_shape(t_shape *shape);
t_shape			*get_shape(t_env *env, const char *name);
t_bool			del_shape(t_env *env, const char *name);
void			kill_shape(t_shape *shape);

void			init_scene(t_scene *scene);
t_scene			*get_scene(t_env *env, const char *name);
t_bool			del_scene(t_env *env, const char *name);
void			kill_scene(t_scene *scene);

#endif
