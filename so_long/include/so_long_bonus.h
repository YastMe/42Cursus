/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeltran <abeltran@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 13:49:37 by abeltran          #+#    #+#             */
/*   Updated: 2023/03/16 15:43:43 by abeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

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
	mlx_texture_t	*trap_0;
	mlx_texture_t	*trap_1;
}	t_textures;

typedef struct s_data
{
	mlx_t			*mlx;
	mlx_image_t		*character;
	mlx_image_t		*text;
	mlx_image_t		**collectible_images;
	mlx_image_t		**exit_images;
	mlx_image_t		**trap_images;
	mlx_image_t		**active_traps;
	mlx_image_t		**inactive_traps;
	mlx_image_t		**anim_image_frames;
	mlx_texture_t	**anim_texture_frames;
	t_textures		*textures;
	char			**map;
	char			key_pressed;
	char			end;
	char			loaded_anims;
	int				x;
	int				y;
	int				size_x;
	int				size_y;
	int				moves;
	int				collectibles;
	int				total_collectibles;
	int				total_traps;
	int				rendered_traps;
	unsigned long	frame;
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
 * 		  it to data->x and data->y.
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

/**
 * @brief Counts the occurrences of the given char in the map.
 * 
 * @param c 
 * @param map 
 * @return int 
 */
int		ft_count(char c, char **map);

/**
 * @brief Creates/Updates the trap array for later use.
 * 
 * @param data 
 * @param image 
 * @return int 
 */
int		ft_trap_list(t_data *data, mlx_image_t *image);

/**
 * @brief Updates every trap status if aplicable.
 * 
 * @param data 
 */
void	ft_update_traps(t_data *data);

/**
 * @brief Handles the frame counter.
 * 
 * @param data 
 */
void	ft_time(t_data *data);

/**
 * @brief Checks if the player is colliding with an activated trap.
 * 
 * @param data 
 */
void	ft_check_traps(t_data *data);

/**
 * @brief Loads the player's animation files.
 * 
 * @param data 
 */
void	ft_load_anims(t_data *data);

/**
 * @brief Renders the number of moves into the screen.
 * 
 * @param data 
 */
void	ft_render_moves(t_data *data);

#endif