/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 17:25:35 by jihykim2          #+#    #+#             */
/*   Updated: 2023/11/24 21:46:14 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	_wall_in_range(t_game *game, int screen_x, int size, int y);
static void	_wall_out_range(t_game *game, int screen_x, int size);

void	draw_wall(t_game *game, int screen_x)
{
	t_raycast	*ray;
	int			size;
	int			start_y;

	ray = &game->ray_info;
	size = ray->wall_length_in_screen;
	start_y = (SCR_HEIGHT / 2) - (size / 2);
	if ((ray->side == W_OR_E && ray->ray_dir.x > 0)
		|| (ray->side == N_OR_S && ray->ray_dir.y < 0))
		ray->hit_point = 1 - ray->hit_point;
	if (size < SCR_HEIGHT)
		_wall_in_range(game, screen_x, size, start_y);
	else
		_wall_out_range(game, screen_x, size);
}

static void	_wall_in_range(t_game *game, int screen_x, int size, int y)
{
	int		i;
	int		color;
	t_vec_i	texture_pixel;
	t_image	*using_image;

	i = 0;
	using_image = game->ray_info.wall_data;
	while (i < size)
	{
		texture_pixel.x = game->ray_info.hit_point * using_image->width;
		texture_pixel.y = mapping_int(i, size, using_image->height);
		color = get_color_in_texture(using_image,
				texture_pixel.x, texture_pixel.y);
		my_mlx_pixel_put(&game->screen, screen_x, y + i, color);
		i++;
	}
}

static void	_wall_out_range(t_game *game, int screen_x, int size)
{
	int		i;
	int		color;
	t_vec_i	texture_pixel;
	t_image	*using_image;

	i = 0;
	using_image = game->ray_info.wall_data;
	while (i < SCR_HEIGHT)
	{
		texture_pixel.x = game->ray_info.hit_point * using_image->width;
		texture_pixel.y = mapping_int(i + (size / 2 - SCR_HEIGHT / 2),
				size, using_image->height);
		color = get_color_in_texture(using_image,
				texture_pixel.x, texture_pixel.y);
		my_mlx_pixel_put(&game->screen, screen_x, i, color);
		i++;
	}
}
