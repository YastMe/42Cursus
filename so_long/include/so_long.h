/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeltran <abeltran@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 13:49:37 by abeltran          #+#    #+#             */
/*   Updated: 2023/03/06 15:21:08 by abeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/include/libft.h"
# include "../MLX42/include/MLX42/MLX42.h"
# include <unistd.h>
# include <fcntl.h>

typedef struct s_textures
{
	mlx_texture_t	*ground;
	mlx_texture_t	*water;
	mlx_texture_t	*coffee;
	mlx_texture_t	*player;
	mlx_texture_t	*exit;
}	t_textures;

typedef struct s_data
{
	mlx_t			*mlx;
	mlx_image_t		*character;
	t_textures		*textures;
	mlx_image_t		**images;
	char			**map;
	char			key_pressed;
	int				x;
	int				y;
	int				size_x;
	int				size_y;
	int				moves;
	int				collectibles;
	int				total_collectibles;
	char			end;
}	t_data;

typedef struct s_checker
{
	char	**visited;
	char	**map;
	int		collectibles;
}	t_checker;

void	ft_update(void *param);
void	read_map_file(char *map_file, t_data *data);
void	ft_finish(t_data	*data);
int		ft_start(void);
void	ft_start_pos(t_data *data);
int		ft_fill_map(t_data *data);
int		ft_render(t_data *data);
int		ft_fill_map(t_data *data);
int		ft_render_sprite(int i, int j, t_data *data, mlx_texture_t *texture);
void	ft_exit_program(t_data *data);
void	ft_check_end(t_data *data);
void	ft_check_collectibles(t_data *data);
void	ft_collectibles(t_data *data);
int		ft_collectible_list(t_data *data, mlx_image_t *image);

#endif