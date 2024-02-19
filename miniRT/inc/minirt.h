/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeltran <abeltran@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 19:37:17 by abeltran          #+#    #+#             */
/*   Updated: 2023/12/21 20:57:34 by abeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "../MLX42/include/MLX42/MLX42.h"
# include "../libft/include/libft.h"
# include "quaternion.h"
# include "vector.h"
# include "colors.h"

# include <fcntl.h>
# include <string.h>
# include <limits.h>
# include <stdio.h>
# include <float.h>
# include <math.h>
# include <sys/time.h>

// Error Codes

# include <errno.h>

# define ERR_CUSTOM 0
# define ERR_SYSTEM 1
# define ERR_LIBMLX 2
# define ERR_FILE	3

// Default Width & Height

# define WIDTH 500
# define HEIGHT 500

enum	e_obj
{
	light = 0,
	sphere = 1,
	plane = 2,
	cylinder = 3,
	camera = 253,
	ambient = 254,
	background = 255,
	none = -1
};

typedef struct s_object
{
	enum e_obj		type;
	int				param_nbr;
	double			*params;
	t_vector		*color;
	struct s_object	*next;
}	t_object;

typedef struct s_ray
{
	t_vector	dir;
	t_vector	color;
	t_object	*collision;
	double		t;
}	t_ray;

typedef struct s_camera
{
	t_vector	position;
	t_vector	rotation;
	int			fov;
	int			initialized;
}	t_camera;

typedef struct s_data
{
	mlx_t			*mlx;
	mlx_image_t		*canvas;
	mlx_image_t		*render_time;
	t_camera		cam;
	t_object		*scene;
	t_object		*lights;
	t_object		*ambient;
	t_vector		*bgcolor;
	t_vector		forward;
	double			t_min;
	double			t_max;
	struct timeval	last_frame;
	t_quaternion	rotation;
}	t_data;

// Data Inicialization

void		ft_init_data(t_data *data);
void		ft_init_camera(t_data *data, t_object *camera);

// File parsing

void		ft_parse(t_data *data, char *filename);
int			ft_count_params(char **pre_parse);
void		ft_init_params(int param_nbr, double *params);
void		ft_fix_coords(t_object *obj);
void		ft_valid_name(t_data *data, char *file);
void		ft_parser_conditions(t_data *data);
void		ft_set_colors(t_data *data, t_object	*obj);
void		ft_add_to_scene(t_data *data, t_object *obj);

// Math

double		ft_average(int *array, int size);
double		ft_normalize(double n, double min, double max);
double		ft_denormalize(double n, double min, double max);
double		*ft_solve_equation(double a, double b, double c);
t_vector	ft_intersect_sphere(t_data *data, t_vector *dir, t_object *sp,
				t_vector *origin);
double		ft_sphere_distance(t_data *data, t_object *sphere, t_vector *dir,
				t_vector *origin);
t_vector	ft_intersect_plane(t_data *data, t_vector *dir, t_object *pl,
				t_vector *origin);
double		ft_plane_distance(t_data *data, t_object *pl, t_vector *dir,
				t_vector *origin);
t_vector	ft_pl_normal(t_object *pl, t_vector *dir);
t_vector	ft_intersect_cylinder(t_data *data, t_vector *dir, t_object *cy,
t_vector *origin);
double	ft_cylinder_distance(t_data *data, t_object *cy, t_vector *dir,
t_vector *origin);
double		ft_min(double first, double second);
double		ft_max(double first, double second);
double		ft_clamp(double num, double min, double max);
t_vector	ft_get_dir(t_data *data, t_vector *coord);

// Scene Renderization

t_object	*ft_closest_obj(t_data *data, t_vector *dir, t_vector *origin);
void		ft_render_scene(t_data *data);
t_vector	ft_apply_light(t_data *data, t_object *obj, t_vector *hit,
				t_vector normal);
// Colors extra

uint32_t	ft_convert_to_rgba(t_vector *color);

// Hooks

void		ft_movement(void *params);
void		ft_time_to_render(void *params);

// Program Exit

void		ft_close_window(mlx_key_data_t keydata, void *param);
void		ft_exit(t_data *data, int exit_code);
void		ft_clean_array(char	**array);
void		ft_clean_scene(t_object *scene);

// Error Handling

void		ft_error(t_data *data, int err_code, char *err_msg);

#endif
