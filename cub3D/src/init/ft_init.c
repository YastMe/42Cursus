/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeltran <abeltran@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 09:48:09 by fragarci          #+#    #+#             */
/*   Updated: 2023/12/21 17:54:04 by abeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub.h"

static void	ft_init_basics(t_data *data)
{
	data->width = WIDTH;
	data->height = HEIGHT;
	data->sky = 0;
	data->floor = 0;
	data->paths.n_wall = NULL;
	data->paths.s_wall = NULL;
	data->paths.e_wall = NULL;
	data->paths.w_wall = NULL;
	data->n_wall = NULL;
	data->s_wall = NULL;
	data->e_wall = NULL;
	data->w_wall = NULL;
	data->minimap = false;
	data->rotate_mouse = false;
}

static void	ft_init_mlx(t_data *data)
{
	data->mlx = mlx_init(data->width, data->height, "cub3D", false);
	if (!data->mlx)
		ft_error(data, ERR_LIBMLX, NULL);
	data->image = mlx_new_image(data->mlx, data->width, data->height);
	if (!data->image)
		ft_error(data, ERR_LIBMLX, NULL);
	if (mlx_image_to_window(data->mlx, data->image, 0, 0) == -1)
		ft_error(data, ERR_LIBMLX, NULL);
	mlx_set_cursor(data->mlx, NULL);
	data->mouse_x = 0;
}

static void	ft_load_textures(t_data *data)
{
	data->n_wall = mlx_load_png(data->paths.n_wall);
	data->s_wall = mlx_load_png(data->paths.s_wall);
	data->e_wall = mlx_load_png(data->paths.e_wall);
	data->w_wall = mlx_load_png(data->paths.w_wall);
	data->cursor = mlx_load_png("./textures/crosshair.png");
	data->cursor_img = mlx_texture_to_image(data->mlx, data->cursor);
	mlx_image_to_window(data->mlx, data->cursor_img,
		WIDTH / 2 - 16, HEIGHT / 2 - 16);
	mlx_delete_texture(data->cursor);
	mlx_set_cursor_mode(data->mlx, MLX_MOUSE_HIDDEN);
	if (!data->n_wall || !data->s_wall || !data->e_wall || !data->w_wall)
		ft_error(data, ERR_LIBMLX, NULL);
	data->pn_wall = (uint32_t *)data->n_wall->pixels;
	data->ps_wall = (uint32_t *)data->s_wall->pixels;
	data->pe_wall = (uint32_t *)data->e_wall->pixels;
	data->pw_wall = (uint32_t *)data->w_wall->pixels;
}

static char	*clean_textures(char *texture)
{
	char	*trim;

	if (texture)
	{
		trim = ft_strtrim(texture, "\n");
		free(texture);
		return (trim);
	}
	return (NULL);
}

void	ft_init(t_data *data, char *filename)
{
	int	x;
	int	y;

	ft_init_basics(data);
	ft_init_mlx(data);
	ft_extension(data, filename);
	ft_parse(data, filename);
	mlx_get_mouse_pos(data->mlx, &x, &y);
	srand(x * y);
	data->paths.n_wall = clean_textures(data->paths.n_wall);
	data->paths.s_wall = clean_textures(data->paths.s_wall);
	data->paths.e_wall = clean_textures(data->paths.e_wall);
	data->paths.w_wall = clean_textures(data->paths.w_wall);
	ft_parser_check(data);
	ft_load_textures(data);
	ft_load_anims(data);
	ft_base_minimap(data);
}
