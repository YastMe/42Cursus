/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 09:44:58 by fragarci          #+#    #+#             */
/*   Updated: 2023/12/21 11:02:09 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include "../MLX42/include/MLX42/MLX42.h"
# include "../libft/include/libft.h"
# include "colors.h"

# include <stdlib.h>
# include <limits.h>
# include <float.h>
# include <stdio.h>
# include <math.h>
# include <fcntl.h>
# include <time.h>

// Error Codes

# include <errno.h>

# define ERR_CUSTOM 0
# define ERR_SYSTEM 1
# define ERR_LIBMLX 2

# define WIDTH 1280
# define HEIGHT 720

# define SKY 0x87CEEB
# define FLOOR 0x664228

/**
 * @brief Represents anything in 2D, float
 * @param x X
 * @param y Y
 */
typedef struct s_fcoord
{
	float	x;
	float	y;
}	t_fcoord;

/**
 * @brief Represents anything in 2D, int
 * @param x X
 * @param y Y
 */
typedef struct s_icoord
{
	int	x;
	int	y;
}	t_icoord;

typedef struct s_player
{
	t_fcoord	pos;
	t_fcoord	dir;
	t_fcoord	plane;
	double		move_speed;
	double		rot_speed;
}	t_player;

typedef struct s_anim
{
	int			selected;
	int			frame;
	mlx_image_t	**yastoru;
	mlx_image_t	**kururin;
	mlx_image_t	**frisk;
}	t_anim;

typedef struct s_paths
{
	char	*n_wall;
	char	*s_wall;
	char	*w_wall;
	char	*e_wall;
}	t_paths;

typedef struct s_data
{
	mlx_t			*mlx;
	mlx_image_t		*image;
	t_player		player;
	char			**map;
	int32_t			width;
	int32_t			height;
	uint32_t		sky;
	uint32_t		floor;
	mlx_texture_t	*cursor;
	mlx_image_t		*cursor_img;
	mlx_texture_t	*n_wall;
	mlx_texture_t	*s_wall;
	mlx_texture_t	*e_wall;
	mlx_texture_t	*w_wall;
	mlx_image_t		*mapplayer;
	uint32_t		*pn_wall;
	uint32_t		*ps_wall;
	uint32_t		*pe_wall;
	uint32_t		*pw_wall;
	t_paths			paths;
	bool			spin;
	double			timer_spin;
	double			timer_anim;
	t_anim			anim;
	int				mouse_x;
	bool			minimap;
	bool			rotate_mouse;
}	t_data;

typedef struct s_ray
{
	double			cam_x;
	t_fcoord		dir;
	t_icoord		map;
	t_fcoord		side_dist;
	t_fcoord		delta_dist;
	double			p_wall_dist;
	t_icoord		step;
	int				hit;
	int				side;
	int				l_height;
	int				draw_start;
	int				draw_end;
	int				color;
	mlx_texture_t	*tex;
	uint32_t		*ptex;
	double			wallx;
	int				tex_x;
}	t_ray;

// Initialization

void	ft_init(t_data *data, char *filename);
void	ft_parse(t_data *data, char *filename);
void	ft_load_anims(t_data *data);

// Parser

void	ft_extension(t_data *data, char *filename);
int		*ft_player_coords(char **map);
void	ft_set_rotation(t_data *data, int *coords);
void	ft_set_position(t_data *data, int *coords);
char	*ft_skip_lines(int fd);
void	ft_parser_check(t_data *data);
void	ft_check_walls(t_data *data, char **map);

// Render

void	ft_clear_screen(t_data *data);
void	ft_init_ray(t_data *data, t_ray *ray, int x);
void	ft_perform_dda(t_data *data, t_ray *ray);
void	ft_get_draw_points(t_data *data, t_ray *ray);
void	ft_choose_texture(t_data *data, t_ray *ray);
void	ft_get_texture_x(t_data *data, t_ray *ray);
void	ft_draw_tline(t_data *data, int x, t_ray ray);
void	ft_render(t_data *data);
void	ft_disable_anims(t_data *data);
void	ft_base_minimap(t_data *data);

// Exit

void	ft_exit(t_data *data, int exit_code);
void	ft_error(t_data *data, int err_code, char *err_msg);
void	ft_close(mlx_key_data_t keydata, void *param);
void	ft_clean_array(char **array);

// Hooks

void	ft_rotate_right(t_player *p);
void	ft_rotate_left(t_player *p);
void	ft_movement(t_data *data);
void	ft_mouse_hook(double x, double y, void *param);
void	ft_anim_spin(t_data *data);
void	ft_main_loop(void *param);

#endif
