/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 17:25:35 by jihykim2          #+#    #+#             */
/*   Updated: 2023/11/23 02:46:29 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	draw_background(t_game *game)
{
	int	screen_x;
	int	screen_y;

	screen_x = 0;
	while (screen_x < SCR_WIDTH)
	{
		screen_y = 0;
		while (screen_y < SCR_HEIGHT / 2)
			my_mlx_pixel_put(&game->screen, screen_x, screen_y++, \
				game->img_info.ceiling);
		while (screen_y < SCR_HEIGHT)
			my_mlx_pixel_put(&game->screen, screen_x, screen_y++, \
				game->img_info.floor);
	}
}

void	draw_wall(t_game *game, int screen_x)
{
	t_raycast	*ray;
	double		ratio;
	double		tex_pos;
	int			texture_x;
	int			screen_y;

	ray = &game->ray_info;
	ratio = (double)(ray->wall_data->height / ray->wall_length_in_screen);
	tex_pos = (ray->draw_start - SCR_HEIGHT / 2 + \
		ray->wall_length_in_screen / 2) * ratio;

	// texture_x: from hit_point(ratio)
	texture_x = (int)(ray->hit_point * (double)ray->wall_data->width);
	if (ray->side == W_OR_E && ray->ray_dir.x > 0)
		texture_x = 0;////////////////////////////////////////////////

	// draw wall
	screen_y = ray->draw_start;
	while (screen_y < ray->draw_end)
		my_mlx_pixel_put(&game->screen, screen_x, screen_y++, \
			get_color_in_texture(ray->wall_data, tex_pos, ray->hit_point));
}

int	get_color_in_texture(t_image *wall, int tex_pos, int hit_point)
{
	int	texture_x;
	int	texture_y;
	int	color;

	texture_x = (int)(hit_point * (double)wall->width);
	texture_y = (int)tex_pos & (wall->height - 1);
	color = wall->addr + (texture_y * wall->size_line + \
		texture_x * (wall->bpp / 8));
	return (color);
}

void	my_mlx_pixel_put(t_image *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->size_line + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}
