/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeltran <abeltran@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 10:39:49 by fragarci          #+#    #+#             */
/*   Updated: 2023/10/02 12:20:19 by abeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLORS_H
# define COLORS_H

# include <stdint.h>

# define BLACK "\033[0;30m"
# define DARK_GRAY "\033[1;30m"
# define RED "\033[0;31m"
# define LIGHT_RED "\033[1;31m"
# define GREEN "\033[0;32m"
# define LIGHT_GREEN "\033[1;32m"
# define ORANGE "\033[0;33m"
# define YELLOW "\033[1;33m"
# define BLUE "\033[0;34m"
# define LIGHT_BLUE "\033[1;34m"
# define PURPLE "\033[0;35m"
# define LIGHT_PURPLE "\033[1;35m"
# define CYAN "\033[0;36m"
# define LIGHT_CYAN "\033[1;36m"
# define LIGHT_GRAY "\033[0;37m"
# define WHITE "\033[1;37m"
# define DEFAULT "\033[;0m"

typedef struct s_rgb
{
	float	r;
	float	g;
	float	b;
}	t_rgb;

typedef struct s_rgb_normalized
{
	float	r;
	float	g;
	float	b;
}	t_rgb_normalized;

// RGB Inicialization

void		ft_rgb_init(t_rgb *rgb, unsigned char r,
				unsigned char g, unsigned char b);

// RGB Encoding

uint32_t	ft_rgb_encode(t_rgb *rgb);

#endif
