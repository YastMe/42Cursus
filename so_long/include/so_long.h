/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeltran <abeltran@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 13:49:37 by abeltran          #+#    #+#             */
/*   Updated: 2023/03/16 15:37:53 by abeltran         ###   ########.fr       */
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
	mlx_texture_t	*exit_empty;
	mlx_texture_t	*exit_1;
	mlx_texture_t	*exit_2;
	mlx_texture_t	*exit_3;
	mlx_texture_t	*exit_4;
}	t_textures;

typedef struct s_data
{
	mlx_t			*mlx;
	mlx_image_t		*character;
	t_textures		*textures;
	mlx_image_t		**collectible_images;
	mlx_image_t		**exit_images;
	char			**map;
	char			key_pressed;
	char			end;
	int				x;
	int				y;
	int				size_x;
	int				size_y;
	int				moves;
	int				collectibles;
	int				total_collectibles;
}	t_data;

/**
 * @brief Main hook for the project. It's executed each frame.
 * 
 * @param param 
 */
void	ft_update(void *param);

/**
 * @brief Reads the map file provided on start and saves it in data->map.
 * 
 * @param map_file 
 * @param data 
 */
void	read_map_file(char *map_file, t_data *data);
/**
 * @brief Handles the termination of the program.
 * 
 * @param data 
 */
void	ft_finish(t_data *data);

/**
 * @brief Handles the start of the program.
 * 
 * @param file 
 * @return int 
 */
int		ft_start(char *file);

/**
 * @brief Finds the player's starting position and saves 
 * 		  it to data->x and data->y
 * 
 * @param data 
 */
void	ft_start_pos(t_data *data);

/**
 * @brief Renders the map one tile at a time.
 * 
 * @param data 
 * @return int 
 */
int		ft_fill_map(t_data *data);

/**
 * @brief Handles the initial rendering of the game.
 * 
 * @param data 
 * @return int 
 */
int		ft_render(t_data *data);

/**
 * @brief Renders a single sprite in the corresponding tile.
 * 
 * @param i 
 * @param j 
 * @param data 
 * @param texture 
 * @return int 
 */
int		ft_render_sprite(int i, int j, t_data *data, mlx_texture_t *texture);

/**
 * @brief Finishes the game and exits the program if the ESC key is pressed.
 * 
 * @param data 
 */
void	ft_exit_program(t_data *data);

/**
 * @brief Checks if the player is at the end tile.
 * 
 * @param data 
 */
void	ft_check_end(t_data *data);

/**
 * @brief Checks if the player is at a collectible tile
 * 		  and, if so, removes it from the game.
 * 
 * @param data 
 */
void	ft_check_collectibles(t_data *data);

/**
 * @brief Counts the total collectibles.
 * 
 * @param data 
 */
void	ft_collectibles(t_data *data);

/**
 * @brief Creates/updates the collectible image array.
 * 
 * @param data 
 * @param image 
 * @return int 
 */
int		ft_collectible_list(t_data *data, mlx_image_t *image);

/**
 * @brief Validates if the map is playable according to the subject.
 * 
 * @param data 
 * @return int 
 */
int		ft_validate(t_data data);

/**
 * @brief Prints various debug data.
 * 
 * @param data 
 */
void	ft_print_data(t_data *data);

/**
 * @brief Frees the map array to avoid leaks.
 * 
 * @param data 
 */
void	ft_free_map(t_data *data);

/**
 * @brief Renders every exit image for later use.
 * 
 * @param i 
 * @param j 
 * @param data 
 */
void	ft_render_exits(int i, int j, t_data *data);

#endif