/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 17:25:35 by jihykim2          #+#    #+#             */
/*   Updated: 2023/11/23 14:12:08 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	get_color_in_texture(t_image *wall, int tex_pos, int texture_x);
void	my_mlx_pixel_put(t_image *img, int x, int y, int color);

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
		screen_x++;
	}
}

void	draw_wall(t_game *game, int screen_x)
{
	t_raycast	*ray;
	double		ratio;
	double		tex_pos;
	int			texture_x;
	// int			texture_y;
	int			screen_y;

	ray = &game->ray_info;
	ratio = (double)(ray->wall_data->height / ray->wall_length_in_screen);
	tex_pos = (ray->draw_start - SCR_HEIGHT / 2 + \
		ray->wall_length_in_screen / 2) * ratio;

	// texture_x: 'real pixel value at x-dir' from hit_point(ratio)
	texture_x = (int)(ray->hit_point * (double)ray->wall_data->width);
	if ((ray->side == W_OR_E && ray->ray_dir.x > 0) || \
		(ray->side == N_OR_S && ray->ray_dir.y < 0))
		texture_x = ray->wall_data->width - texture_x - 1;

	// draw wall
	screen_y = ray->draw_start;
	while (screen_y < ray->draw_end)
	{
		// texture_y = (int)()
		my_mlx_pixel_put(&game->screen, screen_x, screen_y++, \
			get_color_in_texture(ray->wall_data, tex_pos, texture_x));
		tex_pos += ratio;
	}
}

int	get_color_in_texture(t_image *texture, int tex_pos, int texture_x)
{
	char	*color;
	int		texture_y;

	// texture_y = (int)(tex_pos & (texture->height - 1));
	texture_y = tex_pos % texture->height;
	color = texture->addr + (texture_y * texture->size_line + \
		texture_x * (texture->bpp / 8));
	return (*(unsigned int *)color);
}

void	my_mlx_pixel_put(t_image *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->size_line + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}
